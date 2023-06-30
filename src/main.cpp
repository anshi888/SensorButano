#include <Arduino.h>
#define Vinput (3.3)
#define resol_adc (4096)
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}
///SENSORES DE GAS
double sensor_MQ(int RL,int pin, float RO, float eje_y,float eje_x, float curva){
   int adc_mq= analogRead(pin); //Leo adc del pin
   float voltaje = adc_mq * (Vinput/resol_adc); //convierto voltaje
   float RS = RL * ((3.3-voltaje)/voltaje); //RL esta Kohm
   float ratio= RS/RO;
   float exponente=(log(ratio)- eje_y)/(curva);
   float concentracion= pow(10,exponente) + eje_x ;
   return concentracion;
}

void loop() {
  
/* double q8 = sensor_MQ(1000,35,139.43,0.932474,2.301030,-1.453867) ; //mq8
  Serial.print("Value mq8:   ");
 Serial.println(q8-2.95);
  //Lemos la salida analógica  del MQ
  ///SENSOR MQ6

  double q6 = sensor_MQ(5000,34,357.14,0.3,2.301030,-0.6984594690587614) ; //mq8
Serial.print("Value mq6:   ");
 Serial.println(q6-2.3); */
 int adc_MQ = analogRead(34);
  //Convertimos la lectura en un valor de voltaje
  float voltaje = adc_MQ * (3.3 / 4096);
  Serial.print("adc:");
  Serial.print(adc_MQ);
  Serial.print("    voltaje:");
  Serial.println(voltaje,6);
  delay(100);


  delay(2000);


}