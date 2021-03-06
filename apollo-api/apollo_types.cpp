/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "apollo_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace apollo { namespace rpc { namespace api {


Experiment::~Experiment() throw() {
}


void Experiment::__set_testKey(const std::string& val) {
  this->testKey = val;
}

void Experiment::__set_arguments(const std::map<std::string, std::string> & val) {
  this->arguments = val;
}

uint32_t Experiment::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->testKey);
          this->__isset.testKey = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->arguments.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _ktype1;
            ::apache::thrift::protocol::TType _vtype2;
            xfer += iprot->readMapBegin(_ktype1, _vtype2, _size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              std::string _key5;
              xfer += iprot->readString(_key5);
              std::string& _val6 = this->arguments[_key5];
              xfer += iprot->readString(_val6);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.arguments = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Experiment::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Experiment");

  xfer += oprot->writeFieldBegin("testKey", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->testKey);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("arguments", ::apache::thrift::protocol::T_MAP, 2);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->arguments.size()));
    std::map<std::string, std::string> ::const_iterator _iter7;
    for (_iter7 = this->arguments.begin(); _iter7 != this->arguments.end(); ++_iter7)
    {
      xfer += oprot->writeString(_iter7->first);
      xfer += oprot->writeString(_iter7->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Experiment &a, Experiment &b) {
  using ::std::swap;
  swap(a.testKey, b.testKey);
  swap(a.arguments, b.arguments);
  swap(a.__isset, b.__isset);
}

Experiment::Experiment(const Experiment& other8) {
  testKey = other8.testKey;
  arguments = other8.arguments;
  __isset = other8.__isset;
}
Experiment& Experiment::operator=(const Experiment& other9) {
  testKey = other9.testKey;
  arguments = other9.arguments;
  __isset = other9.__isset;
  return *this;
}
void Experiment::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Experiment(";
  out << "testKey=" << to_string(testKey);
  out << ", " << "arguments=" << to_string(arguments);
  out << ")";
}


UserToIdentity::~UserToIdentity() throw() {
}


void UserToIdentity::__set_key(const std::string& val) {
  this->key = val;
}

void UserToIdentity::__set_properties(const std::map<std::string, std::string> & val) {
  this->properties = val;
}

uint32_t UserToIdentity::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->properties.clear();
            uint32_t _size10;
            ::apache::thrift::protocol::TType _ktype11;
            ::apache::thrift::protocol::TType _vtype12;
            xfer += iprot->readMapBegin(_ktype11, _vtype12, _size10);
            uint32_t _i14;
            for (_i14 = 0; _i14 < _size10; ++_i14)
            {
              std::string _key15;
              xfer += iprot->readString(_key15);
              std::string& _val16 = this->properties[_key15];
              xfer += iprot->readString(_val16);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.properties = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t UserToIdentity::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("UserToIdentity");

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("properties", ::apache::thrift::protocol::T_MAP, 2);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->properties.size()));
    std::map<std::string, std::string> ::const_iterator _iter17;
    for (_iter17 = this->properties.begin(); _iter17 != this->properties.end(); ++_iter17)
    {
      xfer += oprot->writeString(_iter17->first);
      xfer += oprot->writeString(_iter17->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(UserToIdentity &a, UserToIdentity &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.properties, b.properties);
  swap(a.__isset, b.__isset);
}

UserToIdentity::UserToIdentity(const UserToIdentity& other18) {
  key = other18.key;
  properties = other18.properties;
  __isset = other18.__isset;
}
UserToIdentity& UserToIdentity::operator=(const UserToIdentity& other19) {
  key = other19.key;
  properties = other19.properties;
  __isset = other19.__isset;
  return *this;
}
void UserToIdentity::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "UserToIdentity(";
  out << "key=" << to_string(key);
  out << ", " << "properties=" << to_string(properties);
  out << ")";
}


FeatureRequest::~FeatureRequest() throw() {
}


void FeatureRequest::__set_ns(const std::string& val) {
  this->ns = val;
}

void FeatureRequest::__set_names(const std::vector<std::string> & val) {
  this->names = val;
}

void FeatureRequest::__set_logId(const int64_t val) {
  this->logId = val;
}

void FeatureRequest::__set_user(const UserToIdentity& val) {
  this->user = val;
}

uint32_t FeatureRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_ns = false;
  bool isset_names = false;
  bool isset_logId = false;
  bool isset_user = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ns);
          isset_ns = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->names.clear();
            uint32_t _size20;
            ::apache::thrift::protocol::TType _etype23;
            xfer += iprot->readListBegin(_etype23, _size20);
            this->names.resize(_size20);
            uint32_t _i24;
            for (_i24 = 0; _i24 < _size20; ++_i24)
            {
              xfer += iprot->readString(this->names[_i24]);
            }
            xfer += iprot->readListEnd();
          }
          isset_names = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->logId);
          isset_logId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->user.read(iprot);
          isset_user = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_ns)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_names)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_logId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_user)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t FeatureRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FeatureRequest");

  xfer += oprot->writeFieldBegin("ns", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->ns);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("names", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->names.size()));
    std::vector<std::string> ::const_iterator _iter25;
    for (_iter25 = this->names.begin(); _iter25 != this->names.end(); ++_iter25)
    {
      xfer += oprot->writeString((*_iter25));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("logId", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->logId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("user", ::apache::thrift::protocol::T_STRUCT, 4);
  xfer += this->user.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FeatureRequest &a, FeatureRequest &b) {
  using ::std::swap;
  swap(a.ns, b.ns);
  swap(a.names, b.names);
  swap(a.logId, b.logId);
  swap(a.user, b.user);
}

FeatureRequest::FeatureRequest(const FeatureRequest& other26) {
  ns = other26.ns;
  names = other26.names;
  logId = other26.logId;
  user = other26.user;
}
FeatureRequest& FeatureRequest::operator=(const FeatureRequest& other27) {
  ns = other27.ns;
  names = other27.names;
  logId = other27.logId;
  user = other27.user;
  return *this;
}
void FeatureRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FeatureRequest(";
  out << "ns=" << to_string(ns);
  out << ", " << "names=" << to_string(names);
  out << ", " << "logId=" << to_string(logId);
  out << ", " << "user=" << to_string(user);
  out << ")";
}


FeatureResult::~FeatureResult() throw() {
}


void FeatureResult::__set_name(const std::string& val) {
  this->name = val;
}

void FeatureResult::__set_allow(const bool val) {
  this->allow = val;
}

void FeatureResult::__set_experiment(const Experiment& val) {
  this->experiment = val;
__isset.experiment = true;
}

uint32_t FeatureResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_name = false;
  bool isset_allow = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          isset_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->allow);
          isset_allow = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->experiment.read(iprot);
          this->__isset.experiment = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_allow)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t FeatureResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FeatureResult");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("allow", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->allow);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.experiment) {
    xfer += oprot->writeFieldBegin("experiment", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->experiment.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FeatureResult &a, FeatureResult &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.allow, b.allow);
  swap(a.experiment, b.experiment);
  swap(a.__isset, b.__isset);
}

FeatureResult::FeatureResult(const FeatureResult& other28) {
  name = other28.name;
  allow = other28.allow;
  experiment = other28.experiment;
  __isset = other28.__isset;
}
FeatureResult& FeatureResult::operator=(const FeatureResult& other29) {
  name = other29.name;
  allow = other29.allow;
  experiment = other29.experiment;
  __isset = other29.__isset;
  return *this;
}
void FeatureResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FeatureResult(";
  out << "name=" << to_string(name);
  out << ", " << "allow=" << to_string(allow);
  out << ", " << "experiment="; (__isset.experiment ? (out << to_string(experiment)) : (out << "<null>"));
  out << ")";
}


FeatureResponse::~FeatureResponse() throw() {
}


void FeatureResponse::__set_code(const int32_t val) {
  this->code = val;
}

void FeatureResponse::__set_message(const std::string& val) {
  this->message = val;
__isset.message = true;
}

void FeatureResponse::__set_results(const std::vector<FeatureResult> & val) {
  this->results = val;
}

uint32_t FeatureResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_code = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->code);
          isset_code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->results.clear();
            uint32_t _size30;
            ::apache::thrift::protocol::TType _etype33;
            xfer += iprot->readListBegin(_etype33, _size30);
            this->results.resize(_size30);
            uint32_t _i34;
            for (_i34 = 0; _i34 < _size30; ++_i34)
            {
              xfer += this->results[_i34].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.results = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_code)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t FeatureResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FeatureResponse");

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->code);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.message) {
    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("results", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->results.size()));
    std::vector<FeatureResult> ::const_iterator _iter35;
    for (_iter35 = this->results.begin(); _iter35 != this->results.end(); ++_iter35)
    {
      xfer += (*_iter35).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FeatureResponse &a, FeatureResponse &b) {
  using ::std::swap;
  swap(a.code, b.code);
  swap(a.message, b.message);
  swap(a.results, b.results);
  swap(a.__isset, b.__isset);
}

FeatureResponse::FeatureResponse(const FeatureResponse& other36) {
  code = other36.code;
  message = other36.message;
  results = other36.results;
  __isset = other36.__isset;
}
FeatureResponse& FeatureResponse::operator=(const FeatureResponse& other37) {
  code = other37.code;
  message = other37.message;
  results = other37.results;
  __isset = other37.__isset;
  return *this;
}
void FeatureResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FeatureResponse(";
  out << "code=" << to_string(code);
  out << ", " << "message="; (__isset.message ? (out << to_string(message)) : (out << "<null>"));
  out << ", " << "results=" << to_string(results);
  out << ")";
}


SelectRequest::~SelectRequest() throw() {
}


void SelectRequest::__set_ns(const std::string& val) {
  this->ns = val;
}

void SelectRequest::__set_name(const std::string& val) {
  this->name = val;
}

void SelectRequest::__set_logId(const int64_t val) {
  this->logId = val;
}

void SelectRequest::__set_users(const std::vector<UserToIdentity> & val) {
  this->users = val;
}

uint32_t SelectRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_ns = false;
  bool isset_name = false;
  bool isset_logId = false;
  bool isset_users = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ns);
          isset_ns = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          isset_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->logId);
          isset_logId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->users.clear();
            uint32_t _size38;
            ::apache::thrift::protocol::TType _etype41;
            xfer += iprot->readListBegin(_etype41, _size38);
            this->users.resize(_size38);
            uint32_t _i42;
            for (_i42 = 0; _i42 < _size38; ++_i42)
            {
              xfer += this->users[_i42].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          isset_users = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_ns)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_logId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_users)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t SelectRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SelectRequest");

  xfer += oprot->writeFieldBegin("ns", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->ns);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("logId", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->logId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("users", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->users.size()));
    std::vector<UserToIdentity> ::const_iterator _iter43;
    for (_iter43 = this->users.begin(); _iter43 != this->users.end(); ++_iter43)
    {
      xfer += (*_iter43).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SelectRequest &a, SelectRequest &b) {
  using ::std::swap;
  swap(a.ns, b.ns);
  swap(a.name, b.name);
  swap(a.logId, b.logId);
  swap(a.users, b.users);
}

SelectRequest::SelectRequest(const SelectRequest& other44) {
  ns = other44.ns;
  name = other44.name;
  logId = other44.logId;
  users = other44.users;
}
SelectRequest& SelectRequest::operator=(const SelectRequest& other45) {
  ns = other45.ns;
  name = other45.name;
  logId = other45.logId;
  users = other45.users;
  return *this;
}
void SelectRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SelectRequest(";
  out << "ns=" << to_string(ns);
  out << ", " << "name=" << to_string(name);
  out << ", " << "logId=" << to_string(logId);
  out << ", " << "users=" << to_string(users);
  out << ")";
}


SelectResult::~SelectResult() throw() {
}


void SelectResult::__set_key(const std::string& val) {
  this->key = val;
}

void SelectResult::__set_allow(const bool val) {
  this->allow = val;
}

uint32_t SelectResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_key = false;
  bool isset_allow = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          isset_key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->allow);
          isset_allow = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_key)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_allow)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t SelectResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SelectResult");

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("allow", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->allow);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SelectResult &a, SelectResult &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.allow, b.allow);
}

SelectResult::SelectResult(const SelectResult& other46) {
  key = other46.key;
  allow = other46.allow;
}
SelectResult& SelectResult::operator=(const SelectResult& other47) {
  key = other47.key;
  allow = other47.allow;
  return *this;
}
void SelectResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SelectResult(";
  out << "key=" << to_string(key);
  out << ", " << "allow=" << to_string(allow);
  out << ")";
}


SelectResponse::~SelectResponse() throw() {
}


void SelectResponse::__set_code(const int32_t val) {
  this->code = val;
}

void SelectResponse::__set_message(const std::string& val) {
  this->message = val;
__isset.message = true;
}

void SelectResponse::__set_results(const std::vector<SelectResult> & val) {
  this->results = val;
}

uint32_t SelectResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_code = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->code);
          isset_code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->results.clear();
            uint32_t _size48;
            ::apache::thrift::protocol::TType _etype51;
            xfer += iprot->readListBegin(_etype51, _size48);
            this->results.resize(_size48);
            uint32_t _i52;
            for (_i52 = 0; _i52 < _size48; ++_i52)
            {
              xfer += this->results[_i52].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.results = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_code)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t SelectResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SelectResponse");

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->code);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.message) {
    xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->message);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("results", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->results.size()));
    std::vector<SelectResult> ::const_iterator _iter53;
    for (_iter53 = this->results.begin(); _iter53 != this->results.end(); ++_iter53)
    {
      xfer += (*_iter53).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SelectResponse &a, SelectResponse &b) {
  using ::std::swap;
  swap(a.code, b.code);
  swap(a.message, b.message);
  swap(a.results, b.results);
  swap(a.__isset, b.__isset);
}

SelectResponse::SelectResponse(const SelectResponse& other54) {
  code = other54.code;
  message = other54.message;
  results = other54.results;
  __isset = other54.__isset;
}
SelectResponse& SelectResponse::operator=(const SelectResponse& other55) {
  code = other55.code;
  message = other55.message;
  results = other55.results;
  __isset = other55.__isset;
  return *this;
}
void SelectResponse::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SelectResponse(";
  out << "code=" << to_string(code);
  out << ", " << "message="; (__isset.message ? (out << to_string(message)) : (out << "<null>"));
  out << ", " << "results=" << to_string(results);
  out << ")";
}

}}} // namespace
