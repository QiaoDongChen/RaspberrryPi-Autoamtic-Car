#include<stdio.h>
#include<wiringPi.h>

#include"FollowLine.h"

#define LeftTCRPin 25
#define MidTCRPin 24
#define RightTCRPin 23

#define SPEED 22
#define DELAY 20

int status = 0;
void straight(){
    // status = 0;
    t_up(SPEED ,DELAY);
    printf("zhi\n");
}

void turnLeft(){
    status = 1;
    delay(30);
    t_stop(15);
    turn_left(SPEED+5, DELAY);
    printf("left\n");
}

void turnRight(){
    status = 2;
    delay(30);
    t_stop(15);
    turn_right(SPEED+5, DELAY);
    printf("right\n");
}


int main()
{
    wiringPiSetup();
    pinMode(LeftTCRPin, INPUT);
    pinMode(MidTCRPin, INPUT);
    pinMode(RightTCRPin, INPUT);

    pinMode(PWMA, OUTPUT);  // 设置电机 A 的 PWM 引脚为输出
    pinMode(AIN1, OUTPUT);  // 设置电机 A 的方向引脚 1 为输出
    pinMode(AIN2, OUTPUT);  // 设置电机 A 的方向引脚 2 为输出
    pinMode(PWMB, OUTPUT);  // 设置电机 B 的 PWM 引脚为输出
    pinMode(BIN1, OUTPUT);  // 设置电机 B 的方向引脚 1 为输出
    pinMode(BIN2, OUTPUT);  // 设置电机 B 的方向引脚 2 为输出

    // 初始化 PWM 信号
    softPwmCreate(PWMA, 0, 100);  // 初始化电机 A 的 PWM，占空比初始为 0，最大为 100
    softPwmCreate(PWMB, 0, 100);  // 初始化电机 B 的 PWM，占空比初始为 0，最大为 100
    
    while (1)
    {
        int LFT = digitalRead(LeftTCRPin);
        int RIT = digitalRead(RightTCRPin);
        int MID = digitalRead(MidTCRPin);

        if(MID&&!LFT&&!RIT) straight();
        else if(MID&&!LFT&&RIT) turnRight();
        else if(MID&&LFT&&!RIT) turnLeft();
        else if (MID&&LFT&&RIT);
        else if(!MID&&LFT&&RIT);
        else if(!MID&&LFT&&!RIT) turnLeft();
        else if(!MID&&!LFT&&RIT) turnRight();
        else {
            if (status==1) turnLeft();
            else if(status==2) turnRight();  
        }




    }
    
    return 0;
}