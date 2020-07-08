// Generated by gencpp from file wtr_usb2ros/motor_msgs.msg
// DO NOT EDIT!


#ifndef WTR_USB2ROS_MESSAGE_MOTOR_MSGS_H
#define WTR_USB2ROS_MESSAGE_MOTOR_MSGS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace wtr_usb2ros
{
template <class ContainerAllocator>
struct motor_msgs_
{
  typedef motor_msgs_<ContainerAllocator> Type;

  motor_msgs_()
    : header()
    , mode(0)
    , ID(0)
    , angle(0.0)
    , current(0.0)
    , temperature(0.0)
    , speed(0.0)  {
    }
  motor_msgs_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , mode(0)
    , ID(0)
    , angle(0.0)
    , current(0.0)
    , temperature(0.0)
    , speed(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _mode_type;
  _mode_type mode;

   typedef uint16_t _ID_type;
  _ID_type ID;

   typedef float _angle_type;
  _angle_type angle;

   typedef float _current_type;
  _current_type current;

   typedef float _temperature_type;
  _temperature_type temperature;

   typedef float _speed_type;
  _speed_type speed;





  typedef boost::shared_ptr< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> const> ConstPtr;

}; // struct motor_msgs_

typedef ::wtr_usb2ros::motor_msgs_<std::allocator<void> > motor_msgs;

typedef boost::shared_ptr< ::wtr_usb2ros::motor_msgs > motor_msgsPtr;
typedef boost::shared_ptr< ::wtr_usb2ros::motor_msgs const> motor_msgsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::wtr_usb2ros::motor_msgs_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace wtr_usb2ros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'wtr_usb2ros': ['/home/ruoyo/WTR/wtr_chassis/catkin_ws/src/wtr_canbus/wtr_usb2ros/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "109b30478e8baae9b5a5e30d9f70c28f";
  }

  static const char* value(const ::wtr_usb2ros::motor_msgs_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x109b30478e8baae9ULL;
  static const uint64_t static_value2 = 0xb5a5e30d9f70c28fULL;
};

template<class ContainerAllocator>
struct DataType< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "wtr_usb2ros/motor_msgs";
  }

  static const char* value(const ::wtr_usb2ros::motor_msgs_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header       # motor header\n\
uint8 mode          # mode 1 means position servo, mode 2 means speed servo\n\
uint16 ID           # CAN ID of a motor\n\
float32 angle       # motor angle\n\
float32 current     # motor current\n\
float32 temperature # motor temperature\n\
float32 speed       # motor speed\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::wtr_usb2ros::motor_msgs_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.mode);
      stream.next(m.ID);
      stream.next(m.angle);
      stream.next(m.current);
      stream.next(m.temperature);
      stream.next(m.speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct motor_msgs_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::wtr_usb2ros::motor_msgs_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::wtr_usb2ros::motor_msgs_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.mode);
    s << indent << "ID: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.ID);
    s << indent << "angle: ";
    Printer<float>::stream(s, indent + "  ", v.angle);
    s << indent << "current: ";
    Printer<float>::stream(s, indent + "  ", v.current);
    s << indent << "temperature: ";
    Printer<float>::stream(s, indent + "  ", v.temperature);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WTR_USB2ROS_MESSAGE_MOTOR_MSGS_H
