#ifndef _ROS_data_service_TimeSignal_h
#define _ROS_data_service_TimeSignal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace data_service
{

  class TimeSignal : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t timestamps_length;
      typedef double _timestamps_type;
      _timestamps_type st_timestamps;
      _timestamps_type * timestamps;
      typedef const char* _signal_type;
      _signal_type signal;

    TimeSignal():
      name(""),
      timestamps_length(0), timestamps(NULL),
      signal("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->timestamps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamps_length);
      for( uint32_t i = 0; i < timestamps_length; i++){
      union {
        double real;
        uint64_t base;
      } u_timestampsi;
      u_timestampsi.real = this->timestamps[i];
      *(outbuffer + offset + 0) = (u_timestampsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timestampsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timestampsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timestampsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_timestampsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_timestampsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_timestampsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_timestampsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->timestamps[i]);
      }
      uint32_t length_signal = strlen(this->signal);
      varToArr(outbuffer + offset, length_signal);
      offset += 4;
      memcpy(outbuffer + offset, this->signal, length_signal);
      offset += length_signal;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t timestamps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      timestamps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      timestamps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      timestamps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->timestamps_length);
      if(timestamps_lengthT > timestamps_length)
        this->timestamps = (double*)realloc(this->timestamps, timestamps_lengthT * sizeof(double));
      timestamps_length = timestamps_lengthT;
      for( uint32_t i = 0; i < timestamps_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_timestamps;
      u_st_timestamps.base = 0;
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_timestamps.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_timestamps = u_st_timestamps.real;
      offset += sizeof(this->st_timestamps);
        memcpy( &(this->timestamps[i]), &(this->st_timestamps), sizeof(double));
      }
      uint32_t length_signal;
      arrToVar(length_signal, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_signal; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_signal-1]=0;
      this->signal = (char *)(inbuffer + offset-1);
      offset += length_signal;
     return offset;
    }

    const char * getType(){ return "data_service/TimeSignal"; };
    const char * getMD5(){ return "242915a951390ccd66bdffda0979a29d"; };

  };

}
#endif