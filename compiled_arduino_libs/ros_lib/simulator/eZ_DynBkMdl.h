#ifndef _ROS_simulator_eZ_DynBkMdl_h
#define _ROS_simulator_eZ_DynBkMdl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace simulator
{

  class eZ_DynBkMdl : public ros::Msg
  {
    public:
      typedef float _s_type;
      _s_type s;
      typedef float _ey_type;
      _ey_type ey;
      typedef float _epsi_type;
      _epsi_type epsi;
      typedef float _v_x_type;
      _v_x_type v_x;
      typedef float _v_y_type;
      _v_y_type v_y;
      typedef float _psi_dot_type;
      _psi_dot_type psi_dot;

    eZ_DynBkMdl():
      s(0),
      ey(0),
      epsi(0),
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
      } u_s;
      u_s.real = this->s;
      *(outbuffer + offset + 0) = (u_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->s);
      union {
        float real;
        uint32_t base;
      } u_ey;
      u_ey.real = this->ey;
      *(outbuffer + offset + 0) = (u_ey.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ey.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ey.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ey.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ey);
      union {
        float real;
        uint32_t base;
      } u_epsi;
      u_epsi.real = this->epsi;
      *(outbuffer + offset + 0) = (u_epsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_epsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_epsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_epsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->epsi);
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
      } u_s;
      u_s.base = 0;
      u_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->s = u_s.real;
      offset += sizeof(this->s);
      union {
        float real;
        uint32_t base;
      } u_ey;
      u_ey.base = 0;
      u_ey.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ey.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ey.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ey.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ey = u_ey.real;
      offset += sizeof(this->ey);
      union {
        float real;
        uint32_t base;
      } u_epsi;
      u_epsi.base = 0;
      u_epsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_epsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_epsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_epsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->epsi = u_epsi.real;
      offset += sizeof(this->epsi);
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

    const char * getType(){ return "simulator/eZ_DynBkMdl"; };
    const char * getMD5(){ return "19de479b90a68da73ee59a1fb6a50755"; };

  };

}
#endif