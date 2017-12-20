//
// PROJECT:         Aspia
// FILE:            system_info/category_dmi_memory_device.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_SYSTEM_INFO__CATEGORY_DMI_MEMORY_DEVICE_H
#define _ASPIA_SYSTEM_INFO__CATEGORY_DMI_MEMORY_DEVICE_H

#include "system_info/category.h"

namespace aspia {

class CategoryDmiMemoryDevice : public CategoryInfo
{
public:
    CategoryDmiMemoryDevice();

    const char* Name() const final;
    IconId Icon() const final;

    const char* Guid() const final;
    void Parse(Table& table, const std::string& data) final;
    std::string Serialize() final;

private:
    DISALLOW_COPY_AND_ASSIGN(CategoryDmiMemoryDevice);
};

} // namespace aspia

#endif // _ASPIA_SYSTEM_INFO__CATEGORY_DMI_MEMORY_DEVICE_H