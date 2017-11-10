#ifndef _ROS_SERVICE_RegisterExperiment_h
#define _ROS_SERVICE_RegisterExperiment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace data_service
{

static const char REGISTEREXPERIMENT[] = "data_service/RegisterExperiment";

  class RegisterExperimentRequest : public ros::Msg
  {
    public:
      typedef const char* _experiment_type;
      _experiment_type experiment;

    RegisterExperimentRequest():
      experiment("")
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
     return offset;
    }

    const char * getType(){ return REGISTEREXPERIMENT; };
    const char * getMD5(){ return "d5af7b7e6b332ce1133c33bfeadc80af"; };

  };

  class RegisterExperimentResponse : public ros::Msg
  {
    public:
      typedef int32_t _experiment_id_type;
      _experiment_id_type experiment_id;

    RegisterExperimentResponse():
      experiment_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_experiment_id;
      u_experiment_id.real = this->experiment_id;
      *(outbuffer + offset + 0) = (u_experiment_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_experiment_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_experiment_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_experiment_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->experiment_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_experiment_id;
      u_experiment_id.base = 0;
      u_experiment_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_experiment_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_experiment_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_experiment_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->experiment_id = u_experiment_id.real;
      offset += sizeof(this->experiment_id);
     return offset;
    }

    const char * getType(){ return REGISTEREXPERIMENT; };
    const char * getMD5(){ return "9bc044b3b8998aa44c7343356570fb87"; };

  };

  class RegisterExperiment {
    public:
    typedef RegisterExperimentRequest Request;
    typedef RegisterExperimentResponse Response;
  };

}
#endif
