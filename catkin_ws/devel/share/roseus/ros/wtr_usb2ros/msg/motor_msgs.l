;; Auto-generated. Do not edit!


(when (boundp 'wtr_usb2ros::motor_msgs)
  (if (not (find-package "WTR_USB2ROS"))
    (make-package "WTR_USB2ROS"))
  (shadow 'motor_msgs (find-package "WTR_USB2ROS")))
(unless (find-package "WTR_USB2ROS::MOTOR_MSGS")
  (make-package "WTR_USB2ROS::MOTOR_MSGS"))

(in-package "ROS")
;;//! \htmlinclude motor_msgs.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass wtr_usb2ros::motor_msgs
  :super ros::object
  :slots (_header _mode _ID _angle _current _temperature _speed ))

(defmethod wtr_usb2ros::motor_msgs
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:mode __mode) 0)
    ((:ID __ID) 0)
    ((:angle __angle) 0.0)
    ((:current __current) 0.0)
    ((:temperature __temperature) 0.0)
    ((:speed __speed) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _mode (round __mode))
   (setq _ID (round __ID))
   (setq _angle (float __angle))
   (setq _current (float __current))
   (setq _temperature (float __temperature))
   (setq _speed (float __speed))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:ID
   (&optional __ID)
   (if __ID (setq _ID __ID)) _ID)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:current
   (&optional __current)
   (if __current (setq _current __current)) _current)
  (:temperature
   (&optional __temperature)
   (if __temperature (setq _temperature __temperature)) _temperature)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _mode
    1
    ;; uint16 _ID
    2
    ;; float32 _angle
    4
    ;; float32 _current
    4
    ;; float32 _temperature
    4
    ;; float32 _speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _mode
       (write-byte _mode s)
     ;; uint16 _ID
       (write-word _ID s)
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _current
       (sys::poke _current (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _temperature
       (sys::poke _temperature (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _mode
     (setq _mode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint16 _ID
     (setq _ID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _current
     (setq _current (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _temperature
     (setq _temperature (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _speed
     (setq _speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get wtr_usb2ros::motor_msgs :md5sum-) "109b30478e8baae9b5a5e30d9f70c28f")
(setf (get wtr_usb2ros::motor_msgs :datatype-) "wtr_usb2ros/motor_msgs")
(setf (get wtr_usb2ros::motor_msgs :definition-)
      "Header header       # motor header
uint8 mode          # mode 1 means position servo, mode 2 means speed servo
uint16 ID           # CAN ID of a motor
float32 angle       # motor angle
float32 current     # motor current
float32 temperature # motor temperature
float32 speed       # motor speed

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
# 0: no frame
# 1: global frame
string frame_id

")



(provide :wtr_usb2ros/motor_msgs "109b30478e8baae9b5a5e30d9f70c28f")


