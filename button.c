#include<stdio.h>
#include<wiringPi.h>

#define BtnPin 24
#define Gpin 22
#define Rpin 21

void LED(char* color){
    pinMode(Gpin,OUTPUT);
    pinMode(Rpin,OUTPUT);
    if(color == "RED"){
        digitalWrite(Rpin,HIGH);
        digitalWrite(Gpin,LOW);
        printf("IS RED\n");
    }
    else if (color == "GREEN")
    {
        digitalWrite(Gpin,HIGH);
        digitalWrite(Rpin,LOW);
    }
    else{
        printf("LED Error");
    }


}

int main(){
    if(wiringPiSetup() == -1){
        printf("setup wiringpi failed !");
        return 1;
    }
    pinMode(BtnPin, INPUT);
    LED("GREEN");
    while (1)
    {
        if(digitalRead(BtnPin) == 0){
            delay(10);
            if(digitalRead(BtnPin) == 0){
                LED("RED");
                
            }
        }
        else if(digitalRead(BtnPin) == 1){
            delay(10);
            if(digitalRead(BtnPin) == 1){
                while (!digitalRead(BtnPin));               
                LED("GREEN");
                printf("Button is pressed\n");
            }
        }
    }
   
    return 0;
}
