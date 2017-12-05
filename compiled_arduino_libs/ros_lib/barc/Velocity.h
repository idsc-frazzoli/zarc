#ifndef _ROS_barc_Velocity_h
#define _ROS_barc_Velocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace barc
{

  class Velocity : public ros::Msg
  {
    public:
      typedef float _v_FL_type;
      _v_FL_type v_FL;
      typedef float _v_FR_type;
      _v_FR_type v_FR;
      typedef float _v_BL_type;
      _v_BL_type v_BL;
      typedef float _v_BR_type;
      _v_BR_type v_BR;
      typedef double _v_time_type;
      _v_time_type v_time;

    Velocity():
      v_FL(0),
      v_FR(0),
      v_BL(0),
      v_BR(0),
      v_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_v_FL;
      u_v_FL.real = this->v_FL;
      *(outbuffer + offset + 0) = (u_v_FL.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_FL.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_FL.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_FL.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_FL);
      union {
        float real;
        uint32_t base;
      } u_v_FR;
      u_v_FR.real = this->v_FR;
      *(outbuffer + offset + 0) = (u_v_FR.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_FR.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_FR.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_FR.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_FR);
      union {
        float real;
        uint32_t base;
      } u_v_BL;
      u_v_BL.real = this->v_BL;
      *(outbuffer + offset + 0) = (u_v_BL.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_BL.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_BL.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_BL.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_BL);
      union {
        float real;
        uint32_t base;
      } u_v_BR;
      u_v_BR.real = this->v_BR;
      *(outbuffer + offset + 0) = (u_v_BR.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_BR.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_BR.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_BR.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_BR);
      union {
        double real;
        uint64_t base;
      } u_v_time;
      u_v_time.real = this->v_time;
      *(outbuffer + offset + 0) = (u_v_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_v_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_v_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_v_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_v_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->v_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_v_FL;
      u_v_FL.base = 0;
      u_v_FL.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_FL.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_FL.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_FL.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_FL = u_v_FL.real;
      offset += sizeof(this->v_FL);
      union {
        float real;
        uint32_t base;
      } u_v_FR;
      u_v_FR.base = 0;
      u_v_FR.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_FR.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_FR.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_FR.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_FR = u_v_FR.real;
      offset += sizeof(this->v_FR);
      union {
        float real;
        uint32_t base;
      } u_v_BL;
      u_v_BL.base = 0;
      u_v_BL.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_BL.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_BL.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_BL.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_BL = u_v_BL.real;
      offset += sizeof(this->v_BL);
      union {
        float real;
        uint32_t base;
      } u_v_BR;
      u_v_BR.base = 0;
      u_v_BR.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_BR.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_BR.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_BR.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_BR = u_v_BR.real;
      offset += sizeof(this->v_BR);
      union {
        double real;
        uint64_t base;
      } u_v_time;
      u_v_time.base = 0;
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_v_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->v_time = u_v_time.real;
      offset += sizeof(this->v_time);
     return offset;
    }

    const char * getType(){ return "barc/Velocity"; };
    const char * getMD5(){ return "6d8c60015747e4d75e7e72e36a33d1b3"; };

  };

}
#endif