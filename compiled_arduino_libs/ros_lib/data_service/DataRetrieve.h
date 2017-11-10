#ifndef _ROS_SERVICE_DataRetrieve_h
#define _ROS_SERVICE_DataRetrieve_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "data_service/CustomSignal.h"

namespace data_service
{

static const char DATARETRIEVE[] = "data_service/DataRetrieve";

  class DataRetrieveRequest : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef bool _is_time_type;
      _is_time_type is_time;

    DataRetrieveRequest():
      id(""),
      is_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        bool real;
        uint8_t base;
      } u_is_time;
      u_is_time.real = this->is_time;
      *(outbuffer + offset + 0) = (u_is_time.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        bool real;
        uint8_t base;
      } u_is_time;
      u_is_time.base = 0;
      u_is_time.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_time = u_is_time.real;
      offset += sizeof(this->is_time);
     return offset;
    }

    const char * getType(){ return DATARETRIEVE; };
    const char * getMD5(){ return "75d582623a3182fcdab95d52c5168aba"; };

  };

  class DataRetrieveResponse : public ros::Msg
  {
    public:
      typedef data_service::CustomSignal _signal_type;
      _signal_type signal;

    DataRetrieveResponse():
      signal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->signal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->signal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DATARETRIEVE; };
    const char * getMD5(){ return "ed8e16fd675a2c47988d9dbfca608537"; };

  };

  class DataRetrieve {
    public:
    typedef DataRetrieveRequest Request;
    typedef DataRetrieveResponse Response;
  };

}
#endif
