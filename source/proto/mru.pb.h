// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mru.proto

#ifndef PROTOBUF_mru_2eproto__INCLUDED
#define PROTOBUF_mru_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include "client_config.pb.h"
// @@protoc_insertion_point(includes)

namespace protobuf_mru_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void InitDefaultsMRUImpl();
void InitDefaultsMRU();
inline void InitDefaults() {
  InitDefaultsMRU();
}
}  // namespace protobuf_mru_2eproto
namespace aspia {
namespace proto {
class MRU;
class MRUDefaultTypeInternal;
extern MRUDefaultTypeInternal _MRU_default_instance_;
}  // namespace proto
}  // namespace aspia
namespace aspia {
namespace proto {

// ===================================================================

class MRU : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:aspia.proto.MRU) */ {
 public:
  MRU();
  virtual ~MRU();

  MRU(const MRU& from);

  inline MRU& operator=(const MRU& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MRU(MRU&& from) noexcept
    : MRU() {
    *this = ::std::move(from);
  }

  inline MRU& operator=(MRU&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const MRU& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MRU* internal_default_instance() {
    return reinterpret_cast<const MRU*>(
               &_MRU_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(MRU* other);
  friend void swap(MRU& a, MRU& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MRU* New() const PROTOBUF_FINAL { return New(NULL); }

  MRU* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const MRU& from);
  void MergeFrom(const MRU& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MRU* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .aspia.proto.ClientConfig client_config = 1;
  int client_config_size() const;
  void clear_client_config();
  static const int kClientConfigFieldNumber = 1;
  const ::aspia::proto::ClientConfig& client_config(int index) const;
  ::aspia::proto::ClientConfig* mutable_client_config(int index);
  ::aspia::proto::ClientConfig* add_client_config();
  ::google::protobuf::RepeatedPtrField< ::aspia::proto::ClientConfig >*
      mutable_client_config();
  const ::google::protobuf::RepeatedPtrField< ::aspia::proto::ClientConfig >&
      client_config() const;

  // @@protoc_insertion_point(class_scope:aspia.proto.MRU)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::aspia::proto::ClientConfig > client_config_;
  mutable int _cached_size_;
  friend struct ::protobuf_mru_2eproto::TableStruct;
  friend void ::protobuf_mru_2eproto::InitDefaultsMRUImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MRU

// repeated .aspia.proto.ClientConfig client_config = 1;
inline int MRU::client_config_size() const {
  return client_config_.size();
}
inline const ::aspia::proto::ClientConfig& MRU::client_config(int index) const {
  // @@protoc_insertion_point(field_get:aspia.proto.MRU.client_config)
  return client_config_.Get(index);
}
inline ::aspia::proto::ClientConfig* MRU::mutable_client_config(int index) {
  // @@protoc_insertion_point(field_mutable:aspia.proto.MRU.client_config)
  return client_config_.Mutable(index);
}
inline ::aspia::proto::ClientConfig* MRU::add_client_config() {
  // @@protoc_insertion_point(field_add:aspia.proto.MRU.client_config)
  return client_config_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::aspia::proto::ClientConfig >*
MRU::mutable_client_config() {
  // @@protoc_insertion_point(field_mutable_list:aspia.proto.MRU.client_config)
  return &client_config_;
}
inline const ::google::protobuf::RepeatedPtrField< ::aspia::proto::ClientConfig >&
MRU::client_config() const {
  // @@protoc_insertion_point(field_list:aspia.proto.MRU.client_config)
  return client_config_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace aspia

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_mru_2eproto__INCLUDED
