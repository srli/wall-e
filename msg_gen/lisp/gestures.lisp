; Auto-generated. Do not edit!


(cl:in-package walle-msg)


;//! \htmlinclude gestures.msg.html

(cl:defclass <gestures> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (wave
    :reader wave
    :initarg :wave
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass gestures (<gestures>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <gestures>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'gestures)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name walle-msg:<gestures> is deprecated: use walle-msg:gestures instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <gestures>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader walle-msg:header-val is deprecated.  Use walle-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'wave-val :lambda-list '(m))
(cl:defmethod wave-val ((m <gestures>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader walle-msg:wave-val is deprecated.  Use walle-msg:wave instead.")
  (wave m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <gestures>) ostream)
  "Serializes a message object of type '<gestures>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'wave) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <gestures>) istream)
  "Deserializes a message object of type '<gestures>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'wave) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<gestures>)))
  "Returns string type for a message object of type '<gestures>"
  "walle/gestures")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'gestures)))
  "Returns string type for a message object of type 'gestures"
  "walle/gestures")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<gestures>)))
  "Returns md5sum for a message object of type '<gestures>"
  "550b3e68ec2eb11e4ec54790dcf97aff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'gestures)))
  "Returns md5sum for a message object of type 'gestures"
  "550b3e68ec2eb11e4ec54790dcf97aff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<gestures>)))
  "Returns full string definition for message of type '<gestures>"
  (cl:format cl:nil "Header header~%~%bool wave~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'gestures)))
  "Returns full string definition for message of type 'gestures"
  (cl:format cl:nil "Header header~%~%bool wave~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <gestures>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <gestures>))
  "Converts a ROS message object to a list"
  (cl:list 'gestures
    (cl:cons ':header (header msg))
    (cl:cons ':wave (wave msg))
))
