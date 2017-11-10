#ifndef _ROS_data_service_TimeSeries_h
#define _ROS_data_service_TimeSeries_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "data_service/TimeData.h"

namespace data_service
{

  class TimeSeries : public ros::Msg
  {
    public:
      uint32_t series_length;
      typedef data_service::TimeData _series_type;
      _series_type st_series;
      _series_type * series;

    TimeSeries():
      series_length(0), series(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->series_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->series_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->series_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->series_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->series_length);
      for( uint32_t i = 0; i < series_length; i++){
      offset += this->series[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t series_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      series_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      series_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      series_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->series_length);
      if(series_lengthT > series_length)
        this->series = (data_service::TimeData*)realloc(this->series, series_lengthT * sizeof(data_service::TimeData));
      series_length = series_lengthT;
      for( uint32_t i = 0; i < series_length; i++){
      offset += this->st_series.deserialize(inbuffer + offset);
        memcpy( &(this->series[i]), &(this->st_series), sizeof(data_service::TimeData));
      }
     return offset;
    }

    const char * getType(){ return "data_service/TimeSeries"; };
    const char * getMD5(){ return "ecf556e37ef3615e6c95590390588636"; };

  };

}
#endif