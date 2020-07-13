;; Auto-generated. Do not edit!


(when (boundp 'wtr_usb2ros::Test)
  (if (not (find-package "WTR_USB2ROS"))
    (make-package "WTR_USB2ROS"))
  (shadow 'Test (find-package "WTR_USB2ROS")))
(unless (find-package "WTR_USB2ROS::TEST")
  (make-package "WTR_USB2ROS::TEST"))

(in-package "ROS")
;;//! \htmlinclude Test.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass wtr_usb2ros::Test
  :super ros::object
  :slots (_header _Target _poseKp _poseKi _poseKd _speedKp _speedKi _speedKd _parameter1 _parameter2 _parameter3 ))

(defmethod wtr_usb2ros::Test
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:Target __Target) 0.0)
    ((:poseKp __poseKp) 0.0)
    ((:poseKi __poseKi) 0.0)
    ((:poseKd __poseKd) 0.0)
    ((:speedKp __speedKp) 0.0)
    ((:speedKi __speedKi) 0.0)
    ((:speedKd __speedKd) 0.0)
    ((:parameter1 __parameter1) 0.0)
    ((:parameter2 __parameter2) 0.0)
    ((:parameter3 __parameter3) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _Target (float __Target))
   (setq _poseKp (float __poseKp))
   (setq _poseKi (float __poseKi))
   (setq _poseKd (float __poseKd))
   (setq _speedKp (float __speedKp))
   (setq _speedKi (float __speedKi))
   (setq _speedKd (float __speedKd))
   (setq _parameter1 (float __parameter1))
   (setq _parameter2 (float __parameter2))
   (setq _parameter3 (float __parameter3))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:Target
   (&optional __Target)
   (if __Target (setq _Target __Target)) _Target)
  (:poseKp
   (&optional __poseKp)
   (if __poseKp (setq _poseKp __poseKp)) _poseKp)
  (:poseKi
   (&optional __poseKi)
   (if __poseKi (setq _poseKi __poseKi)) _poseKi)
  (:poseKd
   (&optional __poseKd)
   (if __poseKd (setq _poseKd __poseKd)) _poseKd)
  (:speedKp
   (&optional __speedKp)
   (if __speedKp (setq _speedKp __speedKp)) _speedKp)
  (:speedKi
   (&optional __speedKi)
   (if __speedKi (setq _speedKi __speedKi)) _speedKi)
  (:speedKd
   (&optional __speedKd)
   (if __speedKd (setq _speedKd __speedKd)) _speedKd)
  (:parameter1
   (&optional __parameter1)
   (if __parameter1 (setq _parameter1 __parameter1)) _parameter1)
  (:parameter2
   (&optional __parameter2)
   (if __parameter2 (setq _parameter2 __parameter2)) _parameter2)
  (:parameter3
   (&optional __parameter3)
   (if __parameter3 (setq _parameter3 __parameter3)) _parameter3)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _Target
    4
    ;; float32 _poseKp
    4
    ;; float32 _poseKi
    4
    ;; float32 _poseKd
    4
    ;; float32 _speedKp
    4
    ;; float32 _speedKi
    4
    ;; float32 _speedKd
    4
    ;; float32 _parameter1
    4
    ;; float32 _parameter2
    4
    ;; float32 _parameter3
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _Target
       (sys::poke _Target (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _poseKp
       (sys::poke _poseKp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _poseKi
       (sys::poke _poseKi (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _poseKd
       (sys::poke _poseKd (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _speedKp
       (sys::poke _speedKp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _speedKi
       (sys::poke _speedKi (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _speedKd
       (sys::poke _speedKd (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _parameter1
       (sys::poke _parameter1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _parameter2
       (sys::poke _parameter2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _parameter3
       (sys::poke _parameter3 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _Target
     (setq _Target (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _poseKp
     (setq _poseKp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _poseKi
     (setq _poseKi (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _poseKd
     (setq _poseKd (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _speedKp
     (setq _speedKp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _speedKi
     (setq _speedKi (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _speedKd
     (setq _speedKd (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _parameter1
     (setq _parameter1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _parameter2
     (setq _parameter2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _parameter3
     (setq _parameter3 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get wtr_usb2ros::Test :md5sum-) "143e124abaeaf23ad065284ea438f5d8")
(setf (get wtr_usb2ros::Test :datatype-) "wtr_usb2ros/Test")
(setf (get wtr_usb2ros::Test :definition-)
      "# motor header
Header header
float32 Target
# Position PID
float32 poseKp
float32 poseKi
float32 poseKd
# Speed PID
float32 speedKp
float32 speedKi
float32 speedKd
# Custom parameter
float32 parameter1
float32 parameter2
float32 parameter3

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :wtr_usb2ros/Test "143e124abaeaf23ad065284ea438f5d8")


