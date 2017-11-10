#ifndef _ROS_barc_ECU_h
#define _ROS_barc_ECU_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace barc
{

  class ECU : public ros::Msg
  {
    public:
      typedef float _motor_type;
      _motor_type motor;
      typedef float _servo_type;
      _servo_type servo;

    ECU():
      motor(0),
      servo(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_motor;
      u_motor.real = this->motor;
      *(outbuffer + offset + 0) = (u_motor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor);
      union {
        float real;
        uint32_t base;
      } u_servo;
      u_servo.real = this->servo;
      *(outbuffer + offset + 0) = (u_servo.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_servo.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_servo.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->servo);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_motor;
      u_motor.base = 0;
      u_motor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor = u_motor.real;
      offset += sizeof(this->motor);
      union {
        float real;
        uint32_t base;
      } u_servo;
      u_servo.base = 0;
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_servo.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->servo = u_servo.real;
      offset += sizeof(this->servo);
     return offset;
    }

    const char * getType(){ return "barc/ECU"; };
    const char * getMD5(){ return "e60fd3690167c0df782fc50cceb5ce82"; };

  };

}
#endif