; Auto-generated. Do not edit!


(cl:in-package wtr_usb2ros-msg)


;//! \htmlinclude motor_msgs.msg.html

(cl:defclass <motor_msgs> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (mode
    :reader mode
    :initarg :mode
    :type cl:fixnum
    :initform 0)
   (ID
    :reader ID
    :initarg :ID
    :type cl:fixnum
    :initform 0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0)
   (current
    :reader current
    :initarg :current
    :type cl:float
    :initform 0.0)
   (temperature
    :reader temperature
    :initarg :temperature
    :type cl:float
    :initform 0.0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass motor_msgs (<motor_msgs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motor_msgs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motor_msgs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name wtr_usb2ros-msg:<motor_msgs> is deprecated: use wtr_usb2ros-msg:motor_msgs instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:header-val is deprecated.  Use wtr_usb2ros-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'mode-val :lambda-list '(m))
(cl:defmethod mode-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:mode-val is deprecated.  Use wtr_usb2ros-msg:mode instead.")
  (mode m))

(cl:ensure-generic-function 'ID-val :lambda-list '(m))
(cl:defmethod ID-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:ID-val is deprecated.  Use wtr_usb2ros-msg:ID instead.")
  (ID m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:angle-val is deprecated.  Use wtr_usb2ros-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'current-val :lambda-list '(m))
(cl:defmethod current-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:current-val is deprecated.  Use wtr_usb2ros-msg:current instead.")
  (current m))

(cl:ensure-generic-function 'temperature-val :lambda-list '(m))
(cl:defmethod temperature-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:temperature-val is deprecated.  Use wtr_usb2ros-msg:temperature instead.")
  (temperature m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <motor_msgs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:speed-val is deprecated.  Use wtr_usb2ros-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motor_msgs>) ostream)
  "Serializes a message object of type '<motor_msgs>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ID)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ID)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'current))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'temperature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motor_msgs>) istream)
  "Deserializes a message object of type '<motor_msgs>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'mode)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'ID)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'ID)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'current) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'temperature) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motor_msgs>)))
  "Returns string type for a message object of type '<motor_msgs>"
  "wtr_usb2ros/motor_msgs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motor_msgs)))
  "Returns string type for a message object of type 'motor_msgs"
  "wtr_usb2ros/motor_msgs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motor_msgs>)))
  "Returns md5sum for a message object of type '<motor_msgs>"
  "109b30478e8baae9b5a5e30d9f70c28f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motor_msgs)))
  "Returns md5sum for a message object of type 'motor_msgs"
  "109b30478e8baae9b5a5e30d9f70c28f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motor_msgs>)))
  "Returns full string definition for message of type '<motor_msgs>"
  (cl:format cl:nil "Header header       # motor header~%uint8 mode          # mode 1 means position servo, mode 2 means speed servo~%uint16 ID           # CAN ID of a motor~%float32 angle       # motor angle~%float32 current     # motor current~%float32 temperature # motor temperature~%float32 speed       # motor speed~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motor_msgs)))
  "Returns full string definition for message of type 'motor_msgs"
  (cl:format cl:nil "Header header       # motor header~%uint8 mode          # mode 1 means position servo, mode 2 means speed servo~%uint16 ID           # CAN ID of a motor~%float32 angle       # motor angle~%float32 current     # motor current~%float32 temperature # motor temperature~%float32 speed       # motor speed~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motor_msgs>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     2
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motor_msgs>))
  "Converts a ROS message object to a list"
  (cl:list 'motor_msgs
    (cl:cons ':header (header msg))
    (cl:cons ':mode (mode msg))
    (cl:cons ':ID (ID msg))
    (cl:cons ':angle (angle msg))
    (cl:cons ':current (current msg))
    (cl:cons ':temperature (temperature msg))
    (cl:cons ':speed (speed msg))
))
