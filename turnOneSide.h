#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>     // 提供 usleep 和其他 POSIX API
#include<errno.h>      // 提供错误码相关功能
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<time.h>       // 提供时间相关功能
#include<arpa/inet.h>  // 提供 IP 地址转换函数
#include<wiringPi.h>   // Raspberry Pi GPIO 控制库
#include<softPwm.h>    // 提供软件 PWM 功能

// 定义电机控制的 GPIO 引脚
int PWMA=1;  // 电机 A 的 PWM 引脚
int AIN2=2;  // 电机 A 的方向控制引脚 2
int AIN1=3;  // 电机 A 的方向控制引脚 1
int PWMB=4;  // 电机 B 的 PWM 引脚
int BIN2=5;  // 电机 B 的方向控制引脚 2
int BIN1=6;  // 电机 B 的方向控制引脚 1

// 定义前进函数
void t_up(unsigned int speed, unsigned int t_time)
{
    // 控制电机 A 正转
    digitalWrite(AIN2, 0);       // AIN2 写入低电平
    digitalWrite(AIN1, 1);       // AIN1 写入高电平
    softPwmWrite(PWMA, speed);   // 电机 A 设置 PWM 占空比为 speed

    // 控制电机 B 正转
    digitalWrite(BIN2, 0);       // BIN2 写入低电平
    digitalWrite(BIN1, 1);       // BIN1 写入高电平
    softPwmWrite(PWMB, speed);   // 电机 B 设置 PWM 占空比为 speed
    delay(t_time);
}

// 定义停止函数
void t_stop(unsigned int t_time){
    // 停止电机 A
    digitalWrite(AIN2, 0);       // AIN2 写入低电平
    digitalWrite(AIN1, 0);       // AIN1 写入低电平
    softPwmWrite(PWMA, 0);       // 电机 A PWM 设置为 0

    // 停止电机 B
    digitalWrite(BIN2, 0);       // BIN2 写入低电平
    digitalWrite(BIN1, 0);       // BIN1 写入低电平
    softPwmWrite(PWMB, 0);       // 电机 B PWM 设置为 0
    delay(t_time);
}


void t_down(unsigned int speed,unsigned int t_time){
    // 控制电机 A 
    digitalWrite(AIN2, 1);       
    digitalWrite(AIN1, 0);       
    softPwmWrite(PWMA, speed);   // 电机 A 设置 PWM 占空比为 speed

    // 控制电机 B 
    digitalWrite(BIN2, 1);       
    digitalWrite(BIN1, 0);       
    softPwmWrite(PWMB, speed);   // 电机 B 设置 PWM 占空比为 speed

    delay(t_time);

}

void turn_left(unsigned int speed,unsigned int time){
    digitalWrite(AIN1,0);
    digitalWrite(AIN2,0);
    softPwmWrite(PWMA,0);

    digitalWrite(BIN1,1);
    digitalWrite(BIN2,0);
    softPwmWrite(PWMB,speed);

    delay(time);

}
void turn_right(unsigned int speed,unsigned int time){
    digitalWrite(BIN1,0);
    digitalWrite(BIN2,0);
    softPwmWrite(PWMB,0);

    digitalWrite(AIN1,1);
    digitalWrite(AIN2,0);
    softPwmWrite(PWMA,speed);

    delay(time);

}
