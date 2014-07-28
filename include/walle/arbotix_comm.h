#ifndef __ARBOTIX_COMM_H
#define __ARBOTIX_COMM_H

#include <stdlib.h>
#include <stdint.h>

#define NUM_JOINTS              23
#define ARBOTIX_START_FLAG      0x34

#include <string.h>

class ArbotixCommData 
{
  public:
    enum CMDType {
      StandPrep = 0,
      SetJointAngle,    // sent from computer 
      RequestJointAngle,
      SetGain,
      
      GetJointAngle,        // sent from arbotix
      IsReady
    };

    uint8_t start;
    uint8_t cmd;
    uint8_t seq_id;
    uint8_t checkSum;
    int16_t joints[NUM_JOINTS];

    ArbotixCommData() 
    {
      start = ARBOTIX_START_FLAG;
      seq_id = 0;
      cmd = checkSum = 0;
      memset(joints, 0, NUM_JOINTS*sizeof(int16_t));
    }
    
    void genCheckSum()
    {
      checkSum = cmd + seq_id;
      for (int i = 0; i < NUM_JOINTS; i++) {
        checkSum += (uint8_t)(joints[i] >> 8) + (uint8_t)(joints[i]);
      }
    }

    bool validate() const
    {
      uint8_t val = cmd + seq_id;
      for (int i = 0; i < NUM_JOINTS; i++) {
        val += (uint8_t)(joints[i] >> 8) + (uint8_t)(joints[i]);
      }
      return (val == checkSum);
    }
};

#endif
