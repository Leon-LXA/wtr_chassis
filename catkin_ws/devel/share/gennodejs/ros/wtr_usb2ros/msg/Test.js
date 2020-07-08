// Auto-generated. Do not edit!

// (in-package wtr_usb2ros.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Test {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.Target = null;
      this.poseKp = null;
      this.poseKi = null;
      this.poseKd = null;
      this.speedKp = null;
      this.speedKi = null;
      this.speedKd = null;
      this.parameter1 = null;
      this.parameter2 = null;
      this.parameter3 = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('Target')) {
        this.Target = initObj.Target
      }
      else {
        this.Target = 0.0;
      }
      if (initObj.hasOwnProperty('poseKp')) {
        this.poseKp = initObj.poseKp
      }
      else {
        this.poseKp = 0.0;
      }
      if (initObj.hasOwnProperty('poseKi')) {
        this.poseKi = initObj.poseKi
      }
      else {
        this.poseKi = 0.0;
      }
      if (initObj.hasOwnProperty('poseKd')) {
        this.poseKd = initObj.poseKd
      }
      else {
        this.poseKd = 0.0;
      }
      if (initObj.hasOwnProperty('speedKp')) {
        this.speedKp = initObj.speedKp
      }
      else {
        this.speedKp = 0.0;
      }
      if (initObj.hasOwnProperty('speedKi')) {
        this.speedKi = initObj.speedKi
      }
      else {
        this.speedKi = 0.0;
      }
      if (initObj.hasOwnProperty('speedKd')) {
        this.speedKd = initObj.speedKd
      }
      else {
        this.speedKd = 0.0;
      }
      if (initObj.hasOwnProperty('parameter1')) {
        this.parameter1 = initObj.parameter1
      }
      else {
        this.parameter1 = 0.0;
      }
      if (initObj.hasOwnProperty('parameter2')) {
        this.parameter2 = initObj.parameter2
      }
      else {
        this.parameter2 = 0.0;
      }
      if (initObj.hasOwnProperty('parameter3')) {
        this.parameter3 = initObj.parameter3
      }
      else {
        this.parameter3 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Test
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [Target]
    bufferOffset = _serializer.float32(obj.Target, buffer, bufferOffset);
    // Serialize message field [poseKp]
    bufferOffset = _serializer.float32(obj.poseKp, buffer, bufferOffset);
    // Serialize message field [poseKi]
    bufferOffset = _serializer.float32(obj.poseKi, buffer, bufferOffset);
    // Serialize message field [poseKd]
    bufferOffset = _serializer.float32(obj.poseKd, buffer, bufferOffset);
    // Serialize message field [speedKp]
    bufferOffset = _serializer.float32(obj.speedKp, buffer, bufferOffset);
    // Serialize message field [speedKi]
    bufferOffset = _serializer.float32(obj.speedKi, buffer, bufferOffset);
    // Serialize message field [speedKd]
    bufferOffset = _serializer.float32(obj.speedKd, buffer, bufferOffset);
    // Serialize message field [parameter1]
    bufferOffset = _serializer.float32(obj.parameter1, buffer, bufferOffset);
    // Serialize message field [parameter2]
    bufferOffset = _serializer.float32(obj.parameter2, buffer, bufferOffset);
    // Serialize message field [parameter3]
    bufferOffset = _serializer.float32(obj.parameter3, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Test
    let len;
    let data = new Test(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [Target]
    data.Target = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [poseKp]
    data.poseKp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [poseKi]
    data.poseKi = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [poseKd]
    data.poseKd = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [speedKp]
    data.speedKp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [speedKi]
    data.speedKi = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [speedKd]
    data.speedKd = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [parameter1]
    data.parameter1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [parameter2]
    data.parameter2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [parameter3]
    data.parameter3 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'wtr_usb2ros/Test';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '143e124abaeaf23ad065284ea438f5d8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # motor header
    Header header
    float32 Target
    # Position PID
    float32 poseKp
    float32 poseKi
    float32 poseKd
    # Speed PID
    float32 speedKp
    float32 speedKi
    float32 speedKd
    # Custom parameter
    float32 parameter1
    float32 parameter2
    float32 parameter3
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Test(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.Target !== undefined) {
      resolved.Target = msg.Target;
    }
    else {
      resolved.Target = 0.0
    }

    if (msg.poseKp !== undefined) {
      resolved.poseKp = msg.poseKp;
    }
    else {
      resolved.poseKp = 0.0
    }

    if (msg.poseKi !== undefined) {
      resolved.poseKi = msg.poseKi;
    }
    else {
      resolved.poseKi = 0.0
    }

    if (msg.poseKd !== undefined) {
      resolved.poseKd = msg.poseKd;
    }
    else {
      resolved.poseKd = 0.0
    }

    if (msg.speedKp !== undefined) {
      resolved.speedKp = msg.speedKp;
    }
    else {
      resolved.speedKp = 0.0
    }

    if (msg.speedKi !== undefined) {
      resolved.speedKi = msg.speedKi;
    }
    else {
      resolved.speedKi = 0.0
    }

    if (msg.speedKd !== undefined) {
      resolved.speedKd = msg.speedKd;
    }
    else {
      resolved.speedKd = 0.0
    }

    if (msg.parameter1 !== undefined) {
      resolved.parameter1 = msg.parameter1;
    }
    else {
      resolved.parameter1 = 0.0
    }

    if (msg.parameter2 !== undefined) {
      resolved.parameter2 = msg.parameter2;
    }
    else {
      resolved.parameter2 = 0.0
    }

    if (msg.parameter3 !== undefined) {
      resolved.parameter3 = msg.parameter3;
    }
    else {
      resolved.parameter3 = 0.0
    }

    return resolved;
    }
};

module.exports = Test;
