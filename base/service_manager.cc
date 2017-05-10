//
// PROJECT:         Aspia Remote Desktop
// FILE:            base/service_manager.cc
// LICENSE:         See top-level directory
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#include "base/service_manager.h"
#include "base/unicode.h"
#include "base/util.h"
#include "base/logging.h"

#include <atomic>
#include <random>

namespace aspia {

static std::atomic_uint32_t _last_service_id = 0;

ServiceManager::ServiceManager(const std::wstring& service_short_name) :
    sc_manager_(OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS))
{
    if (!sc_manager_.IsValid())
    {
        LOG(ERROR) << "OpenSCManagerW() failed: " << GetLastError();
    }
    else
    {
        service_ = OpenServiceW(sc_manager_,
                                service_short_name.c_str(),
                                SERVICE_ALL_ACCESS);
        if (!service_.IsValid())
        {
            LOG(ERROR) << "OpenServiceW() failed: " << GetLastError();
            sc_manager_.Reset();
        }
    }
}

ServiceManager::ServiceManager(ServiceManager&& other)
{
    sc_manager_.Reset(other.sc_manager_.Release());
    service_.Reset(other.service_.Release());
}

// private
ServiceManager::ServiceManager(SC_HANDLE sc_manager, SC_HANDLE service) :
    sc_manager_(sc_manager),
    service_(service)
{
    // Nothing
}

ServiceManager::~ServiceManager()
{
    service_.Reset();
    sc_manager_.Reset();
}

// static
ServiceManager ServiceManager::Create(const std::wstring& command_line,
                                      const std::wstring& service_full_name,
                                      const std::wstring& service_short_name,
                                      const std::wstring& service_description)
{
    // Открываем менеджер служб.
    ScopedScHandle sc_manager(OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS));
    if (!sc_manager)
    {
        LOG(ERROR) << "OpenSCManagerW() failed: " << GetLastError();
        return ServiceManager();
    }

    // Пытаемся создать службу.
    ScopedScHandle service(CreateServiceW(sc_manager,
                                          service_short_name.c_str(),
                                          service_full_name.c_str(),
                                          SERVICE_ALL_ACCESS,
                                          SERVICE_WIN32_OWN_PROCESS,
                                          SERVICE_AUTO_START,
                                          SERVICE_ERROR_NORMAL,
                                          command_line.c_str(),
                                          nullptr,
                                          nullptr,
                                          nullptr,
                                          nullptr,
                                          nullptr));
    if (!service.IsValid())
    {
        LOG(ERROR) << "CreateServiceW() failed: " << GetLastError();
        return ServiceManager();
    }

    if (!service_description.empty())
    {
        SERVICE_DESCRIPTIONW description;
        description.lpDescription = const_cast<LPWSTR>(service_description.c_str());

        // Устанавливаем описание службы.
        if (!ChangeServiceConfig2W(service,
                                   SERVICE_CONFIG_DESCRIPTION,
                                   &description))
        {
            LOG(WARNING) << "ChangeServiceConfig2W() failed: " << GetLastError();
        }
    }

    SC_ACTION action;
    action.Type  = SC_ACTION_RESTART;
    action.Delay = 60000; // 60 seconds

    SERVICE_FAILURE_ACTIONS actions;
    actions.dwResetPeriod = 0;
    actions.lpRebootMsg   = nullptr;
    actions.lpCommand     = nullptr;
    actions.cActions      = 1;
    actions.lpsaActions   = &action;

    if (!ChangeServiceConfig2W(service, SERVICE_CONFIG_FAILURE_ACTIONS, &actions))
    {
        LOG(WARNING) << "ChangeServiceConfig2W() failed: " << GetLastError();
    }

    return ServiceManager(sc_manager.Release(), service.Release());
}

// static
std::wstring ServiceManager::GenerateUniqueServiceId()
{
    uint32_t process_id = GetCurrentProcessId();
    uint32_t last_service_id = _last_service_id;

    std::random_device device;
    std::uniform_int_distribution<uint32_t> uniform(0, std::numeric_limits<uint32_t>::max());

    uint32_t random = uniform(device);

    ++_last_service_id;

    return StringPrintfW(L"%u.%u.%u", process_id, last_service_id, random);
}

// static
std::wstring ServiceManager::CreateUniqueServiceName(const std::wstring& service_name,
                                                     const std::wstring& service_id)
{
    std::wstring unique_name(service_name);

    unique_name.append(L".");
    unique_name.append(service_id);

    return unique_name;
}

// static
bool ServiceManager::IsServiceInstalled(const std::wstring& service_name)
{
    ScopedScHandle sc_manager(OpenSCManagerW(nullptr, nullptr, SC_MANAGER_CONNECT));

    if (!sc_manager.IsValid())
        return false;

    ScopedScHandle service(OpenServiceW(sc_manager,
                                        service_name.c_str(),
                                        SERVICE_QUERY_STATUS));

    return service.IsValid();
}

bool ServiceManager::IsValid() const
{
    return sc_manager_.IsValid() && service_.IsValid();
}

bool ServiceManager::Start() const
{
    if (!StartServiceW(service_, 0, nullptr))
    {
        LOG(ERROR) << "StartServiceW() failed: " << GetLastError();
        return false;
    }

    return true;
}

bool ServiceManager::Stop() const
{
    SERVICE_STATUS status;

    if (!ControlService(service_, SERVICE_CONTROL_STOP, &status))
    {
        LOG(ERROR) << "ControlService() failed: " << GetLastError();
        return false;
    }

    return true;
}

bool ServiceManager::Remove()
{
    if (!DeleteService(service_))
    {
        LOG(ERROR) << "DeleteService() failed: " << GetLastError();
        return false;
    }

    service_.Reset();
    sc_manager_.Reset();

    return true;
}

ServiceManager& ServiceManager::operator=(ServiceManager&& other)
{
    service_.Reset(other.service_.Release());
    sc_manager_.Reset(other.sc_manager_.Release());

    return *this;
}

} // namespace aspia
