; Auto-generated. Do not edit!


(cl:in-package walle-msg)


;//! \htmlinclude pointerpos.msg.html

(cl:defclass <pointerpos> (roslisp-msg-protocol:ros-message)
  ((Header
    :reader Header
    :initarg :Header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (positions
    :reader positions
    :initarg :positions
    :type cl:integer
    :initform 0)
   (servo
    :reader servo
    :initarg :servo
    :type cl:integer
    :initform 0))
)

(cl:defclass pointerpos (<pointerpos>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <pointerpos>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'pointerpos)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name walle-msg:<pointerpos> is deprecated: use walle-msg:pointerpos instead.")))

(cl:ensure-generic-function 'Header-val :lambda-list '(m))
(cl:defmethod Header-val ((m <pointerpos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader walle-msg:Header-val is deprecated.  Use walle-msg:Header instead.")
  (Header m))

(cl:ensure-generic-function 'positions-val :lambda-list '(m))
(cl:defmethod positions-val ((m <pointerpos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader walle-msg:positions-val is deprecated.  Use walle-msg:positions instead.")
  (positions m))

(cl:ensure-generic-function 'servo-val :lambda-list '(m))
(cl:defmethod servo-val ((m <pointerpos>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader walle-msg:servo-val is deprecated.  Use walle-msg:servo instead.")
  (servo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <pointerpos>) ostream)
  "Serializes a message object of type '<pointerpos>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'Header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'positions)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'servo)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <pointerpos>) istream)
  "Deserializes a message object of type '<pointerpos>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'Header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'positions) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'servo) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<pointerpos>)))
  "Returns string type for a message object of type '<pointerpos>"
  "walle/pointerpos")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'pointerpos)))
  "Returns string type for a message object of type 'pointerpos"
  "walle/pointerpos")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<pointerpos>)))
  "Returns md5sum for a message object of type '<pointerpos>"
  "98ec36567cc0e5a0b0597d256973a689")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'pointerpos)))
  "Returns md5sum for a message object of type 'pointerpos"
  "98ec36567cc0e5a0b0597d256973a689")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<pointerpos>)))
  "Returns full string definition for message of type '<pointerpos>"
  (cl:format cl:nil "Header Header~%~%int32 positions~%int32 servo~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'pointerpos)))
  "Returns full string definition for message of type 'pointerpos"
  (cl:format cl:nil "Header Header~%~%int32 positions~%int32 servo~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <pointerpos>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'Header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <pointerpos>))
  "Converts a ROS message object to a list"
  (cl:list 'pointerpos
    (cl:cons ':Header (Header msg))
    (cl:cons ':positions (positions msg))
    (cl:cons ':servo (servo msg))
))
