
(cl:in-package :asdf)

(defsystem "walle-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "HRI" :depends-on ("_package_HRI"))
    (:file "_package_HRI" :depends-on ("_package"))
  ))