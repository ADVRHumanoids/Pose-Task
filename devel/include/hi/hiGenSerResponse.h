// Generated by gencpp from file hi/hiGenSerResponse.msg
// DO NOT EDIT!


#ifndef HI_MESSAGE_HIGENSERRESPONSE_H
#define HI_MESSAGE_HIGENSERRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace hi
{
template <class ContainerAllocator>
struct hiGenSerResponse_
{
  typedef hiGenSerResponse_<ContainerAllocator> Type;

  hiGenSerResponse_()
    : srv_JointName()
    , srv_JointName_hiTask()
    , srv_JointPos_hiTask()
    , srv_ExeTime_hiTask()  {
    }
  hiGenSerResponse_(const ContainerAllocator& _alloc)
    : srv_JointName(_alloc)
    , srv_JointName_hiTask(_alloc)
    , srv_JointPos_hiTask(_alloc)
    , srv_ExeTime_hiTask(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _srv_JointName_type;
  _srv_JointName_type srv_JointName;

   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _srv_JointName_hiTask_type;
  _srv_JointName_hiTask_type srv_JointName_hiTask;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _srv_JointPos_hiTask_type;
  _srv_JointPos_hiTask_type srv_JointPos_hiTask;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _srv_ExeTime_hiTask_type;
  _srv_ExeTime_hiTask_type srv_ExeTime_hiTask;





  typedef boost::shared_ptr< ::hi::hiGenSerResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hi::hiGenSerResponse_<ContainerAllocator> const> ConstPtr;

}; // struct hiGenSerResponse_

typedef ::hi::hiGenSerResponse_<std::allocator<void> > hiGenSerResponse;

typedef boost::shared_ptr< ::hi::hiGenSerResponse > hiGenSerResponsePtr;
typedef boost::shared_ptr< ::hi::hiGenSerResponse const> hiGenSerResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hi::hiGenSerResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hi::hiGenSerResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace hi

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::hi::hiGenSerResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hi::hiGenSerResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hi::hiGenSerResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hi::hiGenSerResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hi::hiGenSerResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hi::hiGenSerResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hi::hiGenSerResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d591b6a387f1833506368224b4a25781";
  }

  static const char* value(const ::hi::hiGenSerResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd591b6a387f18335ULL;
  static const uint64_t static_value2 = 0x06368224b4a25781ULL;
};

template<class ContainerAllocator>
struct DataType< ::hi::hiGenSerResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hi/hiGenSerResponse";
  }

  static const char* value(const ::hi::hiGenSerResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hi::hiGenSerResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[]  srv_JointName\n\
string[]  srv_JointName_hiTask\n\
float32[] srv_JointPos_hiTask\n\
float32[] srv_ExeTime_hiTask\n\
";
  }

  static const char* value(const ::hi::hiGenSerResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hi::hiGenSerResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.srv_JointName);
      stream.next(m.srv_JointName_hiTask);
      stream.next(m.srv_JointPos_hiTask);
      stream.next(m.srv_ExeTime_hiTask);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct hiGenSerResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hi::hiGenSerResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hi::hiGenSerResponse_<ContainerAllocator>& v)
  {
    s << indent << "srv_JointName[]" << std::endl;
    for (size_t i = 0; i < v.srv_JointName.size(); ++i)
    {
      s << indent << "  srv_JointName[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.srv_JointName[i]);
    }
    s << indent << "srv_JointName_hiTask[]" << std::endl;
    for (size_t i = 0; i < v.srv_JointName_hiTask.size(); ++i)
    {
      s << indent << "  srv_JointName_hiTask[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.srv_JointName_hiTask[i]);
    }
    s << indent << "srv_JointPos_hiTask[]" << std::endl;
    for (size_t i = 0; i < v.srv_JointPos_hiTask.size(); ++i)
    {
      s << indent << "  srv_JointPos_hiTask[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.srv_JointPos_hiTask[i]);
    }
    s << indent << "srv_ExeTime_hiTask[]" << std::endl;
    for (size_t i = 0; i < v.srv_ExeTime_hiTask.size(); ++i)
    {
      s << indent << "  srv_ExeTime_hiTask[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.srv_ExeTime_hiTask[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HI_MESSAGE_HIGENSERRESPONSE_H
