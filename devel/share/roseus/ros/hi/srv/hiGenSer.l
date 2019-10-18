;; Auto-generated. Do not edit!


(when (boundp 'hi::hiGenSer)
  (if (not (find-package "HI"))
    (make-package "HI"))
  (shadow 'hiGenSer (find-package "HI")))
(unless (find-package "HI::HIGENSER")
  (make-package "HI::HIGENSER"))
(unless (find-package "HI::HIGENSERREQUEST")
  (make-package "HI::HIGENSERREQUEST"))
(unless (find-package "HI::HIGENSERRESPONSE")
  (make-package "HI::HIGENSERRESPONSE"))

(in-package "ROS")





(defclass hi::hiGenSerRequest
  :super ros::object
  :slots ())

(defmethod hi::hiGenSerRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass hi::hiGenSerResponse
  :super ros::object
  :slots (_srv_JointName _srv_JointName_hiTask _srv_JointPos_hiTask _srv_ExeTime_hiTask ))

(defmethod hi::hiGenSerResponse
  (:init
   (&key
    ((:srv_JointName __srv_JointName) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:srv_JointName_hiTask __srv_JointName_hiTask) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:srv_JointPos_hiTask __srv_JointPos_hiTask) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:srv_ExeTime_hiTask __srv_ExeTime_hiTask) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _srv_JointName __srv_JointName)
   (setq _srv_JointName_hiTask __srv_JointName_hiTask)
   (setq _srv_JointPos_hiTask __srv_JointPos_hiTask)
   (setq _srv_ExeTime_hiTask __srv_ExeTime_hiTask)
   self)
  (:srv_JointName
   (&optional __srv_JointName)
   (if __srv_JointName (setq _srv_JointName __srv_JointName)) _srv_JointName)
  (:srv_JointName_hiTask
   (&optional __srv_JointName_hiTask)
   (if __srv_JointName_hiTask (setq _srv_JointName_hiTask __srv_JointName_hiTask)) _srv_JointName_hiTask)
  (:srv_JointPos_hiTask
   (&optional __srv_JointPos_hiTask)
   (if __srv_JointPos_hiTask (setq _srv_JointPos_hiTask __srv_JointPos_hiTask)) _srv_JointPos_hiTask)
  (:srv_ExeTime_hiTask
   (&optional __srv_ExeTime_hiTask)
   (if __srv_ExeTime_hiTask (setq _srv_ExeTime_hiTask __srv_ExeTime_hiTask)) _srv_ExeTime_hiTask)
  (:serialization-length
   ()
   (+
    ;; string[] _srv_JointName
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _srv_JointName)) 4
    ;; string[] _srv_JointName_hiTask
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _srv_JointName_hiTask)) 4
    ;; float32[] _srv_JointPos_hiTask
    (* 4    (length _srv_JointPos_hiTask)) 4
    ;; float32[] _srv_ExeTime_hiTask
    (* 4    (length _srv_ExeTime_hiTask)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _srv_JointName
     (write-long (length _srv_JointName) s)
     (dolist (elem _srv_JointName)
       (write-long (length elem) s) (princ elem s)
       )
     ;; string[] _srv_JointName_hiTask
     (write-long (length _srv_JointName_hiTask) s)
     (dolist (elem _srv_JointName_hiTask)
       (write-long (length elem) s) (princ elem s)
       )
     ;; float32[] _srv_JointPos_hiTask
     (write-long (length _srv_JointPos_hiTask) s)
     (dotimes (i (length _srv_JointPos_hiTask))
       (sys::poke (elt _srv_JointPos_hiTask i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _srv_ExeTime_hiTask
     (write-long (length _srv_ExeTime_hiTask) s)
     (dotimes (i (length _srv_ExeTime_hiTask))
       (sys::poke (elt _srv_ExeTime_hiTask i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _srv_JointName
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _srv_JointName (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _srv_JointName i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; string[] _srv_JointName_hiTask
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _srv_JointName_hiTask (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _srv_JointName_hiTask i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; float32[] _srv_JointPos_hiTask
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _srv_JointPos_hiTask (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _srv_JointPos_hiTask i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _srv_ExeTime_hiTask
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _srv_ExeTime_hiTask (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _srv_ExeTime_hiTask i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(defclass hi::hiGenSer
  :super ros::object
  :slots ())

(setf (get hi::hiGenSer :md5sum-) "d591b6a387f1833506368224b4a25781")
(setf (get hi::hiGenSer :datatype-) "hi/hiGenSer")
(setf (get hi::hiGenSer :request) hi::hiGenSerRequest)
(setf (get hi::hiGenSer :response) hi::hiGenSerResponse)

(defmethod hi::hiGenSerRequest
  (:response () (instance hi::hiGenSerResponse :init)))

(setf (get hi::hiGenSerRequest :md5sum-) "d591b6a387f1833506368224b4a25781")
(setf (get hi::hiGenSerRequest :datatype-) "hi/hiGenSerRequest")
(setf (get hi::hiGenSerRequest :definition-)
      "
---
string[]  srv_JointName
string[]  srv_JointName_hiTask
float32[] srv_JointPos_hiTask
float32[] srv_ExeTime_hiTask
")

(setf (get hi::hiGenSerResponse :md5sum-) "d591b6a387f1833506368224b4a25781")
(setf (get hi::hiGenSerResponse :datatype-) "hi/hiGenSerResponse")
(setf (get hi::hiGenSerResponse :definition-)
      "
---
string[]  srv_JointName
string[]  srv_JointName_hiTask
float32[] srv_JointPos_hiTask
float32[] srv_ExeTime_hiTask
")



(provide :hi/hiGenSer "d591b6a387f1833506368224b4a25781")


