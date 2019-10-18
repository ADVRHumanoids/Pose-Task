; Auto-generated. Do not edit!


(cl:in-package hi-srv)


;//! \htmlinclude hiGenSer-request.msg.html

(cl:defclass <hiGenSer-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass hiGenSer-request (<hiGenSer-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <hiGenSer-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'hiGenSer-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hi-srv:<hiGenSer-request> is deprecated: use hi-srv:hiGenSer-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <hiGenSer-request>) ostream)
  "Serializes a message object of type '<hiGenSer-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <hiGenSer-request>) istream)
  "Deserializes a message object of type '<hiGenSer-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<hiGenSer-request>)))
  "Returns string type for a service object of type '<hiGenSer-request>"
  "hi/hiGenSerRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'hiGenSer-request)))
  "Returns string type for a service object of type 'hiGenSer-request"
  "hi/hiGenSerRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<hiGenSer-request>)))
  "Returns md5sum for a message object of type '<hiGenSer-request>"
  "d591b6a387f1833506368224b4a25781")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'hiGenSer-request)))
  "Returns md5sum for a message object of type 'hiGenSer-request"
  "d591b6a387f1833506368224b4a25781")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<hiGenSer-request>)))
  "Returns full string definition for message of type '<hiGenSer-request>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'hiGenSer-request)))
  "Returns full string definition for message of type 'hiGenSer-request"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <hiGenSer-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <hiGenSer-request>))
  "Converts a ROS message object to a list"
  (cl:list 'hiGenSer-request
))
;//! \htmlinclude hiGenSer-response.msg.html

(cl:defclass <hiGenSer-response> (roslisp-msg-protocol:ros-message)
  ((srv_JointName
    :reader srv_JointName
    :initarg :srv_JointName
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (srv_JointName_hiTask
    :reader srv_JointName_hiTask
    :initarg :srv_JointName_hiTask
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (srv_JointPos_hiTask
    :reader srv_JointPos_hiTask
    :initarg :srv_JointPos_hiTask
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (srv_ExeTime_hiTask
    :reader srv_ExeTime_hiTask
    :initarg :srv_ExeTime_hiTask
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass hiGenSer-response (<hiGenSer-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <hiGenSer-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'hiGenSer-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hi-srv:<hiGenSer-response> is deprecated: use hi-srv:hiGenSer-response instead.")))

(cl:ensure-generic-function 'srv_JointName-val :lambda-list '(m))
(cl:defmethod srv_JointName-val ((m <hiGenSer-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hi-srv:srv_JointName-val is deprecated.  Use hi-srv:srv_JointName instead.")
  (srv_JointName m))

(cl:ensure-generic-function 'srv_JointName_hiTask-val :lambda-list '(m))
(cl:defmethod srv_JointName_hiTask-val ((m <hiGenSer-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hi-srv:srv_JointName_hiTask-val is deprecated.  Use hi-srv:srv_JointName_hiTask instead.")
  (srv_JointName_hiTask m))

(cl:ensure-generic-function 'srv_JointPos_hiTask-val :lambda-list '(m))
(cl:defmethod srv_JointPos_hiTask-val ((m <hiGenSer-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hi-srv:srv_JointPos_hiTask-val is deprecated.  Use hi-srv:srv_JointPos_hiTask instead.")
  (srv_JointPos_hiTask m))

(cl:ensure-generic-function 'srv_ExeTime_hiTask-val :lambda-list '(m))
(cl:defmethod srv_ExeTime_hiTask-val ((m <hiGenSer-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hi-srv:srv_ExeTime_hiTask-val is deprecated.  Use hi-srv:srv_ExeTime_hiTask instead.")
  (srv_ExeTime_hiTask m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <hiGenSer-response>) ostream)
  "Serializes a message object of type '<hiGenSer-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'srv_JointName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'srv_JointName))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'srv_JointName_hiTask))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'srv_JointName_hiTask))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'srv_JointPos_hiTask))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'srv_JointPos_hiTask))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'srv_ExeTime_hiTask))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'srv_ExeTime_hiTask))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <hiGenSer-response>) istream)
  "Deserializes a message object of type '<hiGenSer-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'srv_JointName) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'srv_JointName)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'srv_JointName_hiTask) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'srv_JointName_hiTask)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'srv_JointPos_hiTask) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'srv_JointPos_hiTask)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'srv_ExeTime_hiTask) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'srv_ExeTime_hiTask)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<hiGenSer-response>)))
  "Returns string type for a service object of type '<hiGenSer-response>"
  "hi/hiGenSerResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'hiGenSer-response)))
  "Returns string type for a service object of type 'hiGenSer-response"
  "hi/hiGenSerResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<hiGenSer-response>)))
  "Returns md5sum for a message object of type '<hiGenSer-response>"
  "d591b6a387f1833506368224b4a25781")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'hiGenSer-response)))
  "Returns md5sum for a message object of type 'hiGenSer-response"
  "d591b6a387f1833506368224b4a25781")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<hiGenSer-response>)))
  "Returns full string definition for message of type '<hiGenSer-response>"
  (cl:format cl:nil "string[]  srv_JointName~%string[]  srv_JointName_hiTask~%float32[] srv_JointPos_hiTask~%float32[] srv_ExeTime_hiTask~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'hiGenSer-response)))
  "Returns full string definition for message of type 'hiGenSer-response"
  (cl:format cl:nil "string[]  srv_JointName~%string[]  srv_JointName_hiTask~%float32[] srv_JointPos_hiTask~%float32[] srv_ExeTime_hiTask~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <hiGenSer-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'srv_JointName) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'srv_JointName_hiTask) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'srv_JointPos_hiTask) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'srv_ExeTime_hiTask) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <hiGenSer-response>))
  "Converts a ROS message object to a list"
  (cl:list 'hiGenSer-response
    (cl:cons ':srv_JointName (srv_JointName msg))
    (cl:cons ':srv_JointName_hiTask (srv_JointName_hiTask msg))
    (cl:cons ':srv_JointPos_hiTask (srv_JointPos_hiTask msg))
    (cl:cons ':srv_ExeTime_hiTask (srv_ExeTime_hiTask msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'hiGenSer)))
  'hiGenSer-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'hiGenSer)))
  'hiGenSer-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'hiGenSer)))
  "Returns string type for a service object of type '<hiGenSer>"
  "hi/hiGenSer")