// Generated by gencpp from file hi/hiGenSer.msg
// DO NOT EDIT!


#ifndef HI_MESSAGE_HIGENSER_H
#define HI_MESSAGE_HIGENSER_H

#include <ros/service_traits.h>


#include <hi/hiGenSerRequest.h>
#include <hi/hiGenSerResponse.h>


namespace hi
{

struct hiGenSer
{

typedef hiGenSerRequest Request;
typedef hiGenSerResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct hiGenSer
} // namespace hi


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::hi::hiGenSer > {
  static const char* value()
  {
    return "d591b6a387f1833506368224b4a25781";
  }

  static const char* value(const ::hi::hiGenSer&) { return value(); }
};

template<>
struct DataType< ::hi::hiGenSer > {
  static const char* value()
  {
    return "hi/hiGenSer";
  }

  static const char* value(const ::hi::hiGenSer&) { return value(); }
};


// service_traits::MD5Sum< ::hi::hiGenSerRequest> should match 
// service_traits::MD5Sum< ::hi::hiGenSer > 
template<>
struct MD5Sum< ::hi::hiGenSerRequest>
{
  static const char* value()
  {
    return MD5Sum< ::hi::hiGenSer >::value();
  }
  static const char* value(const ::hi::hiGenSerRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::hi::hiGenSerRequest> should match 
// service_traits::DataType< ::hi::hiGenSer > 
template<>
struct DataType< ::hi::hiGenSerRequest>
{
  static const char* value()
  {
    return DataType< ::hi::hiGenSer >::value();
  }
  static const char* value(const ::hi::hiGenSerRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::hi::hiGenSerResponse> should match 
// service_traits::MD5Sum< ::hi::hiGenSer > 
template<>
struct MD5Sum< ::hi::hiGenSerResponse>
{
  static const char* value()
  {
    return MD5Sum< ::hi::hiGenSer >::value();
  }
  static const char* value(const ::hi::hiGenSerResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::hi::hiGenSerResponse> should match 
// service_traits::DataType< ::hi::hiGenSer > 
template<>
struct DataType< ::hi::hiGenSerResponse>
{
  static const char* value()
  {
    return DataType< ::hi::hiGenSer >::value();
  }
  static const char* value(const ::hi::hiGenSerResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // HI_MESSAGE_HIGENSER_H
