#ifndef _ROS_marvelmind_nav_hedge_pos_h
#define _ROS_marvelmind_nav_hedge_pos_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace marvelmind_nav
{

  class hedge_pos : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _timestamp_ms_type;
      _timestamp_ms_type timestamp_ms;
      typedef double _x_m_type;
      _x_m_type x_m;
      typedef double _y_m_type;
      _y_m_type y_m;
      typedef double _z_m_type;
      _z_m_type z_m;
      typedef uint8_t _flags_type;
      _flags_type flags;

    hedge_pos():
      header(),
      timestamp_ms(0),
      x_m(0),
      y_m(0),
      z_m(0),
      flags(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_timestamp_ms;
      u_timestamp_ms.real = this->timestamp_ms;
      *(outbuffer + offset + 0) = (u_timestamp_ms.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestamp_ms.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestamp_ms.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestamp_ms.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_timestamp_ms.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_timestamp_ms.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_timestamp_ms.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_timestamp_ms.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestamp_ms);
      union {
        double real;
        uint64_t base;
      } u_x_m;
      u_x_m.real = this->x_m;
      *(outbuffer + offset + 0) = (u_x_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x_m.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x_m.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x_m.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x_m.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x_m.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x_m);
      union {
        double real;
        uint64_t base;
      } u_y_m;
      u_y_m.real = this->y_m;
      *(outbuffer + offset + 0) = (u_y_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y_m.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y_m.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y_m.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y_m.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y_m.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y_m);
      union {
        double real;
        uint64_t base;
      } u_z_m;
      u_z_m.real = this->z_m;
      *(outbuffer + offset + 0) = (u_z_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z_m.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z_m.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z_m.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z_m.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z_m.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z_m);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_timestamp_ms;
      u_timestamp_ms.base = 0;
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_timestamp_ms.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->timestamp_ms = u_timestamp_ms.real;
      offset += sizeof(this->timestamp_ms);
      union {
        double real;
        uint64_t base;
      } u_x_m;
      u_x_m.base = 0;
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x_m.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x_m = u_x_m.real;
      offset += sizeof(this->x_m);
      union {
        double real;
        uint64_t base;
      } u_y_m;
      u_y_m.base = 0;
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y_m.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y_m = u_y_m.real;
      offset += sizeof(this->y_m);
      union {
        double real;
        uint64_t base;
      } u_z_m;
      u_z_m.base = 0;
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z_m.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z_m = u_z_m.real;
      offset += sizeof(this->z_m);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
     return offset;
    }

    const char * getType(){ return "marvelmind_nav/hedge_pos"; };
    const char * getMD5(){ return "29d7a738a044fe2e89bd305ae8fa5f2b"; };

  };

}
#endif