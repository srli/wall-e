; Auto-generated. Do not edit!


(cl:in-package walle-msg)


;//! \htmlinclude HRI.msg.html

(cl:defclass <HRI> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass HRI (<HRI>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HRI>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HRI)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name walle-msg:<HRI> is deprecated: use walle-msg:HRI instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HRI>) ostream)
  "Serializes a message object of type '<HRI>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HRI>) istream)
  "Deserializes a message object of type '<HRI>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HRI>)))
  "Returns string type for a message object of type '<HRI>"
  "walle/HRI")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HRI)))
  "Returns string type for a message object of type 'HRI"
  "walle/HRI")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HRI>)))
  "Returns md5sum for a message object of type '<HRI>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HRI)))
  "Returns md5sum for a message object of type 'HRI"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HRI>)))
  "Returns full string definition for message of type '<HRI>"
  (cl:format cl:nil "#basically a list of gestures as noted in config file~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HRI)))
  "Returns full string definition for message of type 'HRI"
  (cl:format cl:nil "#basically a list of gestures as noted in config file~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HRI>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HRI>))
  "Converts a ROS message object to a list"
  (cl:list 'HRI
))
