
(cl:in-package :asdf)

(defsystem "hi-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "hiGenSer" :depends-on ("_package_hiGenSer"))
    (:file "_package_hiGenSer" :depends-on ("_package"))
  ))