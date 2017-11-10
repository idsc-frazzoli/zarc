#ifndef _ROS_barc_Encoder_h
#define _ROS_barc_Encoder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace barc
{

  class Encoder : public ros::Msg
  {
    public:
      typedef float _FL_type;
      _FL_type FL;
      typedef float _FR_type;
      _FR_type FR;
      typedef float _BL_type;
      _BL_type BL;
      typedef float _BR_type;
      _BR_type BR;

    Encoder():
      FL(0),
      FR(0),
      BL(0),
      BR(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_FL;
      u_FL.real = this->FL;
      *(outbuffer + offset + 0) = (u_FL.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_FL.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_FL.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_FL.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->FL);
      union {
        float real;
        uint32_t base;
      } u_FR;
      u_FR.real = this->FR;
      *(outbuffer + offset + 0) = (u_FR.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_FR.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_FR.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_FR.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->FR);
      union {
        float real;
        uint32_t base;
      } u_BL;
      u_BL.real = this->BL;
      *(outbuffer + offset + 0) = (u_BL.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_BL.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_BL.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_BL.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->BL);
      union {
        float real;
        uint32_t base;
      } u_BR;
      u_BR.real = this->BR;
      *(outbuffer + offset + 0) = (u_BR.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_BR.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_BR.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_BR.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->BR);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_FL;
      u_FL.base = 0;
      u_FL.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_FL.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_FL.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_FL.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->FL = u_FL.real;
      offset += sizeof(this->FL);
      union {
        float real;
        uint32_t base;
      } u_FR;
      u_FR.base = 0;
      u_FR.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_FR.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_FR.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_FR.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->FR = u_FR.real;
      offset += sizeof(this->FR);
      union {
        float real;
        uint32_t base;
      } u_BL;
      u_BL.base = 0;
      u_BL.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_BL.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_BL.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_BL.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->BL = u_BL.real;
      offset += sizeof(this->BL);
      union {
        float real;
        uint32_t base;
      } u_BR;
      u_BR.base = 0;
      u_BR.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_BR.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_BR.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_BR.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->BR = u_BR.real;
      offset += sizeof(this->BR);
     return offset;
    }

    const char * getType(){ return "barc/Encoder"; };
    const char * getMD5(){ return "32ae9320a3544d34b8e4e844525161ab"; };

  };

}
#endif