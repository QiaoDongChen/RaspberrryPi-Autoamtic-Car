#include<stdio.h>
#include<wiringPi.h>

#define Gpin 21
#define Rpin 22

void led_init()
{
    pinMode(Gpin,OUTPUT);
    pinMode(Rpin,OUTPUT);
}

void led_on(){
    digitalWrite(Gpin,HIGH);
    digitalWrite(Rpin,HIGH);
}
void led_off(){
    digitalWrite(Gpin,LOW);
    digitalWrite(Rpin,LOW);
}
int main()
{
    wiringPiSetup();
    led_init();
    while(1){
        led_on();
        delay(1000);
        led_off();
        delay(1000);
    }

    return 0;
}