
(cl:in-package :asdf)

(defsystem "wtr_usb2ros-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Test" :depends-on ("_package_Test"))
    (:file "_package_Test" :depends-on ("_package"))
    (:file "motor_msgs" :depends-on ("_package_motor_msgs"))
    (:file "_package_motor_msgs" :depends-on ("_package"))
  ))