// Auto-generated. Do not edit!

// (in-package hi.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class hiGenSerRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type hiGenSerRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type hiGenSerRequest
    let len;
    let data = new hiGenSerRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'hi/hiGenSerRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new hiGenSerRequest(null);
    return resolved;
    }
};

class hiGenSerResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.srv_JointName = null;
      this.srv_JointName_hiTask = null;
      this.srv_JointPos_hiTask = null;
      this.srv_ExeTime_hiTask = null;
    }
    else {
      if (initObj.hasOwnProperty('srv_JointName')) {
        this.srv_JointName = initObj.srv_JointName
      }
      else {
        this.srv_JointName = [];
      }
      if (initObj.hasOwnProperty('srv_JointName_hiTask')) {
        this.srv_JointName_hiTask = initObj.srv_JointName_hiTask
      }
      else {
        this.srv_JointName_hiTask = [];
      }
      if (initObj.hasOwnProperty('srv_JointPos_hiTask')) {
        this.srv_JointPos_hiTask = initObj.srv_JointPos_hiTask
      }
      else {
        this.srv_JointPos_hiTask = [];
      }
      if (initObj.hasOwnProperty('srv_ExeTime_hiTask')) {
        this.srv_ExeTime_hiTask = initObj.srv_ExeTime_hiTask
      }
      else {
        this.srv_ExeTime_hiTask = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type hiGenSerResponse
    // Serialize message field [srv_JointName]
    bufferOffset = _arraySerializer.string(obj.srv_JointName, buffer, bufferOffset, null);
    // Serialize message field [srv_JointName_hiTask]
    bufferOffset = _arraySerializer.string(obj.srv_JointName_hiTask, buffer, bufferOffset, null);
    // Serialize message field [srv_JointPos_hiTask]
    bufferOffset = _arraySerializer.float32(obj.srv_JointPos_hiTask, buffer, bufferOffset, null);
    // Serialize message field [srv_ExeTime_hiTask]
    bufferOffset = _arraySerializer.float32(obj.srv_ExeTime_hiTask, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type hiGenSerResponse
    let len;
    let data = new hiGenSerResponse(null);
    // Deserialize message field [srv_JointName]
    data.srv_JointName = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [srv_JointName_hiTask]
    data.srv_JointName_hiTask = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [srv_JointPos_hiTask]
    data.srv_JointPos_hiTask = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [srv_ExeTime_hiTask]
    data.srv_ExeTime_hiTask = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.srv_JointName.forEach((val) => {
      length += 4 + val.length;
    });
    object.srv_JointName_hiTask.forEach((val) => {
      length += 4 + val.length;
    });
    length += 4 * object.srv_JointPos_hiTask.length;
    length += 4 * object.srv_ExeTime_hiTask.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'hi/hiGenSerResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd591b6a387f1833506368224b4a25781';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string[]  srv_JointName
    string[]  srv_JointName_hiTask
    float32[] srv_JointPos_hiTask
    float32[] srv_ExeTime_hiTask
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new hiGenSerResponse(null);
    if (msg.srv_JointName !== undefined) {
      resolved.srv_JointName = msg.srv_JointName;
    }
    else {
      resolved.srv_JointName = []
    }

    if (msg.srv_JointName_hiTask !== undefined) {
      resolved.srv_JointName_hiTask = msg.srv_JointName_hiTask;
    }
    else {
      resolved.srv_JointName_hiTask = []
    }

    if (msg.srv_JointPos_hiTask !== undefined) {
      resolved.srv_JointPos_hiTask = msg.srv_JointPos_hiTask;
    }
    else {
      resolved.srv_JointPos_hiTask = []
    }

    if (msg.srv_ExeTime_hiTask !== undefined) {
      resolved.srv_ExeTime_hiTask = msg.srv_ExeTime_hiTask;
    }
    else {
      resolved.srv_ExeTime_hiTask = []
    }

    return resolved;
    }
};

module.exports = {
  Request: hiGenSerRequest,
  Response: hiGenSerResponse,
  md5sum() { return 'd591b6a387f1833506368224b4a25781'; },
  datatype() { return 'hi/hiGenSer'; }
};
