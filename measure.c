#include "measure.h"
#include "io430.h"

//subroutine to intialize the ADC
void init_ADC10(unsigned int mode){

  ADC10CTL0 |= (1 << 13); //Set (0-1.6V or 0-2.5V reference)
  ADC10CTL0 |= REFON;
  ADC10CTL0 |= REF2_5V;
  //ADC10CTL0 &= ~REF2_5V;
  ADC10AE0 |= BIT4; // enable analog input on channel 4
  ADC10CTL0 |= ADC10SHT0; // set sample & hold time: 16 clock cycles
  if(mode == CONTINUOUS_SAMPLING){ //continuous sampling mode
      ADC10CTL1 = CONSEQ_2+INCH_4; // Repeat single channel measurement
      ADC10CTL0 |= MSC; // causes sample & conversion to happen automatically after first sample & hold
  }
  else if(mode == SINGLE_SAMPLE){ //single sample -> requires software conversion start every ti
      ADC10CTL0 |= CONSEQ_0+INCH_4; // Single channel single conversio
      ADC10CTL0 &= ~MSC; // causes sample & conversion to happen only after software conversion init
  }
  ADC10CTL0 |= ADC10ON; // turn ADC10 on 
  ADC10CTL0 |= ENC; // enable conversions
  ADC10CTL0 |= ADC10SC; // start conversion (i.e. start sample & hold process)
}

//Subroutine to read ADC data
void read_ADC10(unsigned short* v){
  //TODO: test
  //Note: ADC10MEM holds10 bits in 2 bytes of memory (sizeof(unsigned short))
  //Note: 'v' is a pointer to buffer in memory
  //Bit 9 is the MSB (bits 15-10 are always zero)
  
  for(int i=0;i<N_POINTS;i++){
    *(v+i)= ADC10MEM; //buffer option
  }
}

short avg_buffer(unsigned short* v){
  //TODO: test
  short a = 0;
  for(int i=0;i<num_points;i++){
    a += *(v+i);
  }
  a /= num_points;
  return a;
}


void store(short d){
  readBuff[index] = d;
  index = (index) % CAPACITY;
}
