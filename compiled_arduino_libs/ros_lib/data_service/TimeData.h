#ifndef _ROS_data_service_TimeData_h
#define _ROS_data_service_TimeData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace data_service
{

  class TimeData : public ros::Msg
  {
    public:
      typedef double _timestamp_type;
      _timestamp_type timestamp;
      uint32_t value_length;
      typedef double _value_type;
      _value_type st_value;
      _value_type * value;

    TimeData():
      timestamp(0),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_timestamp;
      u_timestamp.real = this->timestamp;
      *(outbuffer + offset + 0) = (u_timestamp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestamp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestamp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestamp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_timestamp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_timestamp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_timestamp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_timestamp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestamp);
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      union {
        double real;
        uint64_t base;
      } u_valuei;
      u_valuei.real = this->value[i];
      *(outbuffer + offset + 0) = (u_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valuei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_valuei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_valuei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_valuei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_valuei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_timestamp;
      u_timestamp.base = 0;
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_timestamp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->timestamp = u_timestamp.real;
      offset += sizeof(this->timestamp);
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (double*)realloc(this->value, value_lengthT * sizeof(double));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_value;
      u_st_value.base = 0;
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_value.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_value = u_st_value.real;
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "data_service/TimeData"; };
    const char * getMD5(){ return "806316970232f83725326f09cc93bc8a"; };

  };

}
#endif