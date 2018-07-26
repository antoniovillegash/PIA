#include <VirtualWire.h>
int rojo=8;
int amarillo=12; 
int verde=13;
const int dataPin = 9;


void setup() {
  pinMode(verde,OUTPUT);  
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);
  vw_setup(2000);
  vw_set_tx_pin(dataPin);
}
char data[1];
void loop() {
  
 for(int x=0; x<50; x++){
 data[0] = '1';
 digitalWrite(verde,HIGH);
 vw_send((uint8_t*)data,sizeof(data)); 
 vw_wait_tx();
 delay(100); 
 digitalWrite(verde,LOW);}
        
 for(int x=0; x<30; x++){
 data[0] = '2';
 digitalWrite(amarillo,HIGH);
 vw_send((uint8_t*)data,sizeof(data));
 vw_wait_tx(); 
 delay(100);           
 digitalWrite(amarillo,LOW);}

 for(int x=0; x<50; x++){
 data[0] = '3';
 digitalWrite(rojo,HIGH);
 vw_send((uint8_t*)data,sizeof(data));
 vw_wait_tx(); 
 delay(100);         
 digitalWrite(rojo,LOW);}}
