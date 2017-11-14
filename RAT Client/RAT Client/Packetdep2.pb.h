// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Packet.proto

#ifndef PROTOBUF_Packet_2eproto__INCLUDED
#define PROTOBUF_Packet_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace Info {
class Packet;
class PacketDefaultTypeInternal;
extern PacketDefaultTypeInternal _Packet_default_instance_;
}  // namespace Info

namespace Info {

namespace protobuf_Packet_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_Packet_2eproto

// ===================================================================

class Packet : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Info.Packet) */ {
 public:
  Packet();
  virtual ~Packet();

  Packet(const Packet& from);

  inline Packet& operator=(const Packet& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Packet& default_instance();

  static inline const Packet* internal_default_instance() {
    return reinterpret_cast<const Packet*>(
               &_Packet_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Packet* other);

  // implements Message ----------------------------------------------

  inline Packet* New() const PROTOBUF_FINAL { return New(NULL); }

  Packet* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Packet& from);
  void MergeFrom(const Packet& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Packet* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional string date = 2;
  bool has_date() const;
  void clear_date();
  static const int kDateFieldNumber = 2;
  const ::std::string& date() const;
  void set_date(const ::std::string& value);
  #if LANG_CXX11
  void set_date(::std::string&& value);
  #endif
  void set_date(const char* value);
  void set_date(const char* value, size_t size);
  ::std::string* mutable_date();
  ::std::string* release_date();
  void set_allocated_date(::std::string* date);

  // optional string processor = 3;
  bool has_processor() const;
  void clear_processor();
  static const int kProcessorFieldNumber = 3;
  const ::std::string& processor() const;
  void set_processor(const ::std::string& value);
  #if LANG_CXX11
  void set_processor(::std::string&& value);
  #endif
  void set_processor(const char* value);
  void set_processor(const char* value, size_t size);
  ::std::string* mutable_processor();
  ::std::string* release_processor();
  void set_allocated_processor(::std::string* processor);

  // optional bytes screen = 4;
  bool has_screen() const;
  void clear_screen();
  static const int kScreenFieldNumber = 4;
  const ::std::string& screen() const;
  void set_screen(const ::std::string& value);
  #if LANG_CXX11
  void set_screen(::std::string&& value);
  #endif
  void set_screen(const char* value);
  void set_screen(const void* value, size_t size);
  ::std::string* mutable_screen();
  ::std::string* release_screen();
  void set_allocated_screen(::std::string* screen);

  // @@protoc_insertion_point(class_scope:Info.Packet)
 private:
  void set_has_name();
  void clear_has_name();
  void set_has_date();
  void clear_has_date();
  void set_has_processor();
  void clear_has_processor();
  void set_has_screen();
  void clear_has_screen();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr date_;
  ::google::protobuf::internal::ArenaStringPtr processor_;
  ::google::protobuf::internal::ArenaStringPtr screen_;
  friend struct protobuf_Packet_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Packet

// optional string name = 1;
inline bool Packet::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Packet::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Packet::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Packet::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Packet::name() const {
  // @@protoc_insertion_point(field_get:Info.Packet.name)
  return name_.GetNoArena();
}
inline void Packet::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Info.Packet.name)
}
#if LANG_CXX11
inline void Packet::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Info.Packet.name)
}
#endif
inline void Packet::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Info.Packet.name)
}
inline void Packet::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Info.Packet.name)
}
inline ::std::string* Packet::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:Info.Packet.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Packet::release_name() {
  // @@protoc_insertion_point(field_release:Info.Packet.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Packet::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Info.Packet.name)
}

// optional string date = 2;
inline bool Packet::has_date() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Packet::set_has_date() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Packet::clear_has_date() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Packet::clear_date() {
  date_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_date();
}
inline const ::std::string& Packet::date() const {
  // @@protoc_insertion_point(field_get:Info.Packet.date)
  return date_.GetNoArena();
}
inline void Packet::set_date(const ::std::string& value) {
  set_has_date();
  date_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Info.Packet.date)
}
#if LANG_CXX11
inline void Packet::set_date(::std::string&& value) {
  set_has_date();
  date_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Info.Packet.date)
}
#endif
inline void Packet::set_date(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_date();
  date_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Info.Packet.date)
}
inline void Packet::set_date(const char* value, size_t size) {
  set_has_date();
  date_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Info.Packet.date)
}
inline ::std::string* Packet::mutable_date() {
  set_has_date();
  // @@protoc_insertion_point(field_mutable:Info.Packet.date)
  return date_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Packet::release_date() {
  // @@protoc_insertion_point(field_release:Info.Packet.date)
  clear_has_date();
  return date_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Packet::set_allocated_date(::std::string* date) {
  if (date != NULL) {
    set_has_date();
  } else {
    clear_has_date();
  }
  date_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), date);
  // @@protoc_insertion_point(field_set_allocated:Info.Packet.date)
}

// optional string processor = 3;
inline bool Packet::has_processor() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Packet::set_has_processor() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Packet::clear_has_processor() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Packet::clear_processor() {
  processor_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_processor();
}
inline const ::std::string& Packet::processor() const {
  // @@protoc_insertion_point(field_get:Info.Packet.processor)
  return processor_.GetNoArena();
}
inline void Packet::set_processor(const ::std::string& value) {
  set_has_processor();
  processor_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Info.Packet.processor)
}
#if LANG_CXX11
inline void Packet::set_processor(::std::string&& value) {
  set_has_processor();
  processor_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Info.Packet.processor)
}
#endif
inline void Packet::set_processor(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_processor();
  processor_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Info.Packet.processor)
}
inline void Packet::set_processor(const char* value, size_t size) {
  set_has_processor();
  processor_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Info.Packet.processor)
}
inline ::std::string* Packet::mutable_processor() {
  set_has_processor();
  // @@protoc_insertion_point(field_mutable:Info.Packet.processor)
  return processor_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Packet::release_processor() {
  // @@protoc_insertion_point(field_release:Info.Packet.processor)
  clear_has_processor();
  return processor_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Packet::set_allocated_processor(::std::string* processor) {
  if (processor != NULL) {
    set_has_processor();
  } else {
    clear_has_processor();
  }
  processor_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), processor);
  // @@protoc_insertion_point(field_set_allocated:Info.Packet.processor)
}

// optional bytes screen = 4;
inline bool Packet::has_screen() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Packet::set_has_screen() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Packet::clear_has_screen() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Packet::clear_screen() {
  screen_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_screen();
}
inline const ::std::string& Packet::screen() const {
  // @@protoc_insertion_point(field_get:Info.Packet.screen)
  return screen_.GetNoArena();
}
inline void Packet::set_screen(const ::std::string& value) {
  set_has_screen();
  screen_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Info.Packet.screen)
}
#if LANG_CXX11
inline void Packet::set_screen(::std::string&& value) {
  set_has_screen();
  screen_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Info.Packet.screen)
}
#endif
inline void Packet::set_screen(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_screen();
  screen_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Info.Packet.screen)
}
inline void Packet::set_screen(const void* value, size_t size) {
  set_has_screen();
  screen_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Info.Packet.screen)
}
inline ::std::string* Packet::mutable_screen() {
  set_has_screen();
  // @@protoc_insertion_point(field_mutable:Info.Packet.screen)
  return screen_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Packet::release_screen() {
  // @@protoc_insertion_point(field_release:Info.Packet.screen)
  clear_has_screen();
  return screen_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Packet::set_allocated_screen(::std::string* screen) {
  if (screen != NULL) {
    set_has_screen();
  } else {
    clear_has_screen();
  }
  screen_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), screen);
  // @@protoc_insertion_point(field_set_allocated:Info.Packet.screen)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace Info

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Packet_2eproto__INCLUDED
