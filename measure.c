#include "measure.h"
#include "io430.h"

//subroutine to intialize the ADC
void init_ADC10(unsigned int mode){

  ADC10CTL0 |= REFON; //Enable internal voltage reference
  ADC10CTL0 |= (1 << 13); //Utilize V+=VRef and V- = Vss (turn off to use VCC as positive reference)
  ADC10CTL0 |= REF2_5V; //Set Internal referencetos 2.5 V
  //ADC10CTL0 &= ~REF2_5V; //Set Internal referencetos 1.5 V
  ADC10AE0 |= BIT4; // enable analog input on channel 4
  ADC10CTL0 |= ADC10SHT0; // set sample & hold time: 16 clock cycles
  if(mode == CONTINUOUS_SAMPLING){ //continuous sampling mode
      ADC10CTL1 = CONSEQ_2+INCH_4; // Repeat single channel measurement
      ADC10CTL0 |= MSC; // causes sample & conversion to happen automatically after first sample & hold
  }
  else if(mode == SINGLE_SAMPLE){ //single sample -> requires software conversion start every ti
      ADC10CTL0 |= CONSEQ_0+INCH_4; // Single channel single conversion
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
  for(int i=0;i<N_POINTS;i++){
    a += *(v+i);
  }
  a /= N_POINTS;
  return a;
}

float convert_temp(short meas){
  //TODO: test
  /* Apply calibration curve to convert ADC value->voltage->Temperature */
  
  /* Convert ADC10MEM read to voltage */
  float Vmeas = ((float)meas / 1023.0) * (VREFP-VSS) + VSS;
  
  /* Derive thermistor resistance from voltage */
  float resistance = (Vmeas*R1)/(VCC-Vmeas);
  
  /* Apply calibration curve -> derive temperature from resistance */
  float temp = 0.0446*pow(resistance,2)-3.2772*resistance+56.407;
  
  /* Return temperature value */
  return temp;
}


void store(short d){
  readBuff[index] = d;
  index = (index) % CAPACITY;
}
