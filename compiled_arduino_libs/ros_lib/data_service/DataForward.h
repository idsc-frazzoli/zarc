#ifndef _ROS_SERVICE_DataForward_h
#define _ROS_SERVICE_DataForward_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "data_service/TimeSignal.h"
#include "data_service/CustomSignal.h"

namespace data_service
{

static const char DATAFORWARD[] = "data_service/DataForward";

  class DataForwardRequest : public ros::Msg
  {
    public:
      typedef data_service::TimeSignal _time_signal_type;
      _time_signal_type time_signal;
      typedef data_service::CustomSignal _custom_signal_type;
      _custom_signal_type custom_signal;
      typedef const char* _experiment_name_type;
      _experiment_name_type experiment_name;

    DataForwardRequest():
      time_signal(),
      custom_signal(),
      experiment_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->time_signal.serialize(outbuffer + offset);
      offset += this->custom_signal.serialize(outbuffer + offset);
      uint32_t length_experiment_name = strlen(this->experiment_name);
      varToArr(outbuffer + offset, length_experiment_name);
      offset += 4;
      memcpy(outbuffer + offset, this->experiment_name, length_experiment_name);
      offset += length_experiment_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->time_signal.deserialize(inbuffer + offset);
      offset += this->custom_signal.deserialize(inbuffer + offset);
      uint32_t length_experiment_name;
      arrToVar(length_experiment_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_experiment_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_experiment_name-1]=0;
      this->experiment_name = (char *)(inbuffer + offset-1);
      offset += length_experiment_name;
     return offset;
    }

    const char * getType(){ return DATAFORWARD; };
    const char * getMD5(){ return "66879b37a6a1d948514d4b887d4a03a9"; };

  };

  class DataForwardResponse : public ros::Msg
  {
    public:
      typedef const char* _response_type;
      _response_type response;

    DataForwardResponse():
      response("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_response = strlen(this->response);
      varToArr(outbuffer + offset, length_response);
      offset += 4;
      memcpy(outbuffer + offset, this->response, length_response);
      offset += length_response;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_response;
      arrToVar(length_response, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response-1]=0;
      this->response = (char *)(inbuffer + offset-1);
      offset += length_response;
     return offset;
    }

    const char * getType(){ return DATAFORWARD; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class DataForward {
    public:
    typedef DataForwardRequest Request;
    typedef DataForwardResponse Response;
  };

}
#endif
