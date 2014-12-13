
(cl:in-package :asdf)

(defsystem "walle-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "gestures" :depends-on ("_package_gestures"))
    (:file "_package_gestures" :depends-on ("_package"))
    (:file "HRI" :depends-on ("_package_HRI"))
    (:file "_package_HRI" :depends-on ("_package"))
    (:file "pointerpos" :depends-on ("_package_pointerpos"))
    (:file "_package_pointerpos" :depends-on ("_package"))
  ))