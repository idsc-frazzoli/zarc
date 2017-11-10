#ifndef _ROS_barc_Ultrasound_h
#define _ROS_barc_Ultrasound_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace barc
{

  class Ultrasound : public ros::Msg
  {
    public:
      typedef float _front_type;
      _front_type front;
      typedef float _back_type;
      _back_type back;
      typedef float _right_type;
      _right_type right;
      typedef float _left_type;
      _left_type left;

    Ultrasound():
      front(0),
      back(0),
      right(0),
      left(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_front;
      u_front.real = this->front;
      *(outbuffer + offset + 0) = (u_front.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front);
      union {
        float real;
        uint32_t base;
      } u_back;
      u_back.real = this->back;
      *(outbuffer + offset + 0) = (u_back.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_back.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_back.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_back.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->back);
      union {
        float real;
        uint32_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right);
      union {
        float real;
        uint32_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_front;
      u_front.base = 0;
      u_front.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front = u_front.real;
      offset += sizeof(this->front);
      union {
        float real;
        uint32_t base;
      } u_back;
      u_back.base = 0;
      u_back.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_back.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_back.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_back.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->back = u_back.real;
      offset += sizeof(this->back);
      union {
        float real;
        uint32_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right = u_right.real;
      offset += sizeof(this->right);
      union {
        float real;
        uint32_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left = u_left.real;
      offset += sizeof(this->left);
     return offset;
    }

    const char * getType(){ return "barc/Ultrasound"; };
    const char * getMD5(){ return "a28144c3266e5b701faa1e4761aa50f9"; };

  };

}
#endif