#ifndef _ROS_simulator_Z_DynBkMdl_h
#define _ROS_simulator_Z_DynBkMdl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace simulator
{

  class Z_DynBkMdl : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _psi_type;
      _psi_type psi;
      typedef float _v_x_type;
      _v_x_type v_x;
      typedef float _v_y_type;
      _v_y_type v_y;
      typedef float _psi_dot_type;
      _psi_dot_type psi_dot;

    Z_DynBkMdl():
      x(0),
      y(0),
      psi(0),
      v_x(0),
      v_y(0),
      psi_dot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_psi;
      u_psi.real = this->psi;
      *(outbuffer + offset + 0) = (u_psi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->psi);
      union {
        float real;
        uint32_t base;
      } u_v_x;
      u_v_x.real = this->v_x;
      *(outbuffer + offset + 0) = (u_v_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_x);
      union {
        float real;
        uint32_t base;
      } u_v_y;
      u_v_y.real = this->v_y;
      *(outbuffer + offset + 0) = (u_v_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_y);
      union {
        float real;
        uint32_t base;
      } u_psi_dot;
      u_psi_dot.real = this->psi_dot;
      *(outbuffer + offset + 0) = (u_psi_dot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psi_dot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psi_dot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psi_dot.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->psi_dot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_psi;
      u_psi.base = 0;
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->psi = u_psi.real;
      offset += sizeof(this->psi);
      union {
        float real;
        uint32_t base;
      } u_v_x;
      u_v_x.base = 0;
      u_v_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_x = u_v_x.real;
      offset += sizeof(this->v_x);
      union {
        float real;
        uint32_t base;
      } u_v_y;
      u_v_y.base = 0;
      u_v_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_y = u_v_y.real;
      offset += sizeof(this->v_y);
      union {
        float real;
        uint32_t base;
      } u_psi_dot;
      u_psi_dot.base = 0;
      u_psi_dot.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psi_dot.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psi_dot.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psi_dot.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->psi_dot = u_psi_dot.real;
      offset += sizeof(this->psi_dot);
     return offset;
    }

    const char * getType(){ return "simulator/Z_DynBkMdl"; };
    const char * getMD5(){ return "7fe12764dcdf3a7f6277d8c56c0c723c"; };

  };

}
#endif