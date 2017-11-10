#ifndef _ROS_SERVICE_RegisterVideo_h
#define _ROS_SERVICE_RegisterVideo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace data_service
{

static const char REGISTERVIDEO[] = "data_service/RegisterVideo";

  class RegisterVideoRequest : public ros::Msg
  {
    public:
      typedef const char* _experiment_type;
      _experiment_type experiment;
      typedef const char* _path_type;
      _path_type path;

    RegisterVideoRequest():
      experiment(""),
      path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_experiment = strlen(this->experiment);
      varToArr(outbuffer + offset, length_experiment);
      offset += 4;
      memcpy(outbuffer + offset, this->experiment, length_experiment);
      offset += length_experiment;
      uint32_t length_path = strlen(this->path);
      varToArr(outbuffer + offset, length_path);
      offset += 4;
      memcpy(outbuffer + offset, this->path, length_path);
      offset += length_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_experiment;
      arrToVar(length_experiment, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_experiment; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_experiment-1]=0;
      this->experiment = (char *)(inbuffer + offset-1);
      offset += length_experiment;
      uint32_t length_path;
      arrToVar(length_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_path-1]=0;
      this->path = (char *)(inbuffer + offset-1);
      offset += length_path;
     return offset;
    }

    const char * getType(){ return REGISTERVIDEO; };
    const char * getMD5(){ return "baad6537a8fac26f3bc46b1b86efbaac"; };

  };

  class RegisterVideoResponse : public ros::Msg
  {
    public:
      typedef const char* _response_type;
      _response_type response;

    RegisterVideoResponse():
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

    const char * getType(){ return REGISTERVIDEO; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class RegisterVideo {
    public:
    typedef RegisterVideoRequest Request;
    typedef RegisterVideoResponse Response;
  };

}
#endif
