; Auto-generated. Do not edit!


(cl:in-package wtr_usb2ros-msg)


;//! \htmlinclude Test.msg.html

(cl:defclass <Test> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (Target
    :reader Target
    :initarg :Target
    :type cl:float
    :initform 0.0)
   (poseKp
    :reader poseKp
    :initarg :poseKp
    :type cl:float
    :initform 0.0)
   (poseKi
    :reader poseKi
    :initarg :poseKi
    :type cl:float
    :initform 0.0)
   (poseKd
    :reader poseKd
    :initarg :poseKd
    :type cl:float
    :initform 0.0)
   (speedKp
    :reader speedKp
    :initarg :speedKp
    :type cl:float
    :initform 0.0)
   (speedKi
    :reader speedKi
    :initarg :speedKi
    :type cl:float
    :initform 0.0)
   (speedKd
    :reader speedKd
    :initarg :speedKd
    :type cl:float
    :initform 0.0)
   (parameter1
    :reader parameter1
    :initarg :parameter1
    :type cl:float
    :initform 0.0)
   (parameter2
    :reader parameter2
    :initarg :parameter2
    :type cl:float
    :initform 0.0)
   (parameter3
    :reader parameter3
    :initarg :parameter3
    :type cl:float
    :initform 0.0))
)

(cl:defclass Test (<Test>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Test>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Test)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name wtr_usb2ros-msg:<Test> is deprecated: use wtr_usb2ros-msg:Test instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:header-val is deprecated.  Use wtr_usb2ros-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'Target-val :lambda-list '(m))
(cl:defmethod Target-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:Target-val is deprecated.  Use wtr_usb2ros-msg:Target instead.")
  (Target m))

(cl:ensure-generic-function 'poseKp-val :lambda-list '(m))
(cl:defmethod poseKp-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:poseKp-val is deprecated.  Use wtr_usb2ros-msg:poseKp instead.")
  (poseKp m))

(cl:ensure-generic-function 'poseKi-val :lambda-list '(m))
(cl:defmethod poseKi-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:poseKi-val is deprecated.  Use wtr_usb2ros-msg:poseKi instead.")
  (poseKi m))

(cl:ensure-generic-function 'poseKd-val :lambda-list '(m))
(cl:defmethod poseKd-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:poseKd-val is deprecated.  Use wtr_usb2ros-msg:poseKd instead.")
  (poseKd m))

(cl:ensure-generic-function 'speedKp-val :lambda-list '(m))
(cl:defmethod speedKp-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:speedKp-val is deprecated.  Use wtr_usb2ros-msg:speedKp instead.")
  (speedKp m))

(cl:ensure-generic-function 'speedKi-val :lambda-list '(m))
(cl:defmethod speedKi-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:speedKi-val is deprecated.  Use wtr_usb2ros-msg:speedKi instead.")
  (speedKi m))

(cl:ensure-generic-function 'speedKd-val :lambda-list '(m))
(cl:defmethod speedKd-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:speedKd-val is deprecated.  Use wtr_usb2ros-msg:speedKd instead.")
  (speedKd m))

(cl:ensure-generic-function 'parameter1-val :lambda-list '(m))
(cl:defmethod parameter1-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:parameter1-val is deprecated.  Use wtr_usb2ros-msg:parameter1 instead.")
  (parameter1 m))

(cl:ensure-generic-function 'parameter2-val :lambda-list '(m))
(cl:defmethod parameter2-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:parameter2-val is deprecated.  Use wtr_usb2ros-msg:parameter2 instead.")
  (parameter2 m))

(cl:ensure-generic-function 'parameter3-val :lambda-list '(m))
(cl:defmethod parameter3-val ((m <Test>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader wtr_usb2ros-msg:parameter3-val is deprecated.  Use wtr_usb2ros-msg:parameter3 instead.")
  (parameter3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Test>) ostream)
  "Serializes a message object of type '<Test>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Target))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'poseKp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'poseKi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'poseKd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speedKp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speedKi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speedKd))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'parameter1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'parameter2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'parameter3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Test>) istream)
  "Deserializes a message object of type '<Test>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Target) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'poseKp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'poseKi) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'poseKd) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speedKp) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speedKi) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speedKd) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'parameter1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'parameter2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'parameter3) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Test>)))
  "Returns string type for a message object of type '<Test>"
  "wtr_usb2ros/Test")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Test)))
  "Returns string type for a message object of type 'Test"
  "wtr_usb2ros/Test")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Test>)))
  "Returns md5sum for a message object of type '<Test>"
  "143e124abaeaf23ad065284ea438f5d8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Test)))
  "Returns md5sum for a message object of type 'Test"
  "143e124abaeaf23ad065284ea438f5d8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Test>)))
  "Returns full string definition for message of type '<Test>"
  (cl:format cl:nil "# motor header~%Header header~%float32 Target~%# Position PID~%float32 poseKp~%float32 poseKi~%float32 poseKd~%# Speed PID~%float32 speedKp~%float32 speedKi~%float32 speedKd~%# Custom parameter~%float32 parameter1~%float32 parameter2~%float32 parameter3~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Test)))
  "Returns full string definition for message of type 'Test"
  (cl:format cl:nil "# motor header~%Header header~%float32 Target~%# Position PID~%float32 poseKp~%float32 poseKi~%float32 poseKd~%# Speed PID~%float32 speedKp~%float32 speedKi~%float32 speedKd~%# Custom parameter~%float32 parameter1~%float32 parameter2~%float32 parameter3~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Test>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Test>))
  "Converts a ROS message object to a list"
  (cl:list 'Test
    (cl:cons ':header (header msg))
    (cl:cons ':Target (Target msg))
    (cl:cons ':poseKp (poseKp msg))
    (cl:cons ':poseKi (poseKi msg))
    (cl:cons ':poseKd (poseKd msg))
    (cl:cons ':speedKp (speedKp msg))
    (cl:cons ':speedKi (speedKi msg))
    (cl:cons ':speedKd (speedKd msg))
    (cl:cons ':parameter1 (parameter1 msg))
    (cl:cons ':parameter2 (parameter2 msg))
    (cl:cons ':parameter3 (parameter3 msg))
))
