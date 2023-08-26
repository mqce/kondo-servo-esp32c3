#include <math.h>
#include <Arduino.h>
#include <HardwareSerial.h>
#include <IcsHardSerialClass.h>

HardwareSerial MySerial0(0);

const byte EN_PIN = 2;
long BAUDRATE = 115200;
const int TIMEOUT = 1000;
IcsHardSerialClass krs(&MySerial0,EN_PIN,BAUDRATE,TIMEOUT);

const int ID_LEG1_TOP = 3;
const int ID_LEG1_BOTTOM = 4;

void setup()
{
    Serial.begin(BAUDRATE);
    Serial.println("hello.");

    // Configure MySerial0 on pins TX=D6 and RX=D7 (-1, -1 means use the default)
    MySerial0.begin(BAUDRATE, SERIAL_8N1, -1, -1);
    delay(100);

    krs.begin();
    krs.setSpd(ID_LEG1_BOTTOM, 64);// 1～127  1(遅い)     127(速い)
    krs.setPos(ID_LEG1_TOP, 7500);
    //krs.setPos(ID_LEG1_BOTTOM, 7000); 
}

float t = 0;

void loop(){
    double pos = 6800.0 + 700.0 * sin(t/100*M_PI);
    //Serial.println(sin(t/10*M_PI));
    krs.setPos(ID_LEG1_BOTTOM, pos);
    //Serial.println(pos);
    t ++;
    delay(10);
/*
    int id = krs.getID();
    Serial.print("id:");
    Serial.println(id);

    krs.setPos(id,7500); //位置指令　ID:0サーボを7500へ 中央
    delay(500); //0.5秒待つ
    krs.setPos(id,9500); //位置指令　ID:0サーボを9500へ 右
    delay(500); //0.5秒待つ
    krs.setPos(id,7500); //位置指令　ID:0サーボを7500へ 中央
    delay(500); //0.5秒待つ
    krs.setPos(id,5500); //位置指令　ID:0サーボを5500へ 左
    delay(500); 
    //while(true);
    */
}