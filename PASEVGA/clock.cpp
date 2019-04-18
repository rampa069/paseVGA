
#include "Arduino.h"
#include "Z80.h"


#define CPU_SPEED 3580000 


byte Z80_RDMEM(uint16_t A);
void Z80_WRMEM(uint16_t A,byte V);
void Z80_GetRegs (Z80_Regs *Regs);
extern int Z80_IPeriod;
extern int Z80_ICount;
int IFreq = 1;
int CpuSpeed=80;

void measure_clock()
{
  Z80_Regs i;
  Z80_Reset();
  Z80_WRMEM (0x4000 ,0xc3); //c3
  Z80_WRMEM (0x4001 ,0x00);
  Z80_WRMEM (0x4002 ,0x40);
  i.R=0;
  i.PC.D=0x4000;
  Z80_SetRegs (&i);
  
  uint32_t opcodes =0;
  uint32_t tstates =0;
  uint32_t ts1 = micros();
  Z80_Execute();
  uint32_t ts2 = micros();
  opcodes=Z80_ICount;
  
  tstates=opcodes*10;
  Z80_GetRegs(&i);
  Serial.printf("clock frequency = %5.3f Mhz\n", ((float) tstates/(ts2-ts1)));
  
  Serial.printf("Measured time: %d\n",ts2-ts1);
  Serial.printf("OpCodes executed: %d\n",opcodes);
  Serial.printf("Z80_Count: %d\n",Z80_ICount);
 }

void setup_cpuspeed(int per) {
  int _iperiod;
  int a;

  _iperiod = (CPU_SPEED*CpuSpeed)/(100*IFreq);

  a = (per * 256) / 100;

  _iperiod *= a;
  _iperiod >>= 8;

  Z80_IPeriod = _iperiod;
  Z80_ICount = _iperiod;

}