/******************************************************/
/****** Install SparkFun LIS3DH Arduino Library  ******/
/******************************************************/

#include "SparkFunLIS3DH.h"
#include "Wire.h"
#include "SPI.h"

LIS3DH myIMU; //Default constructor is I2C, addr 0x19.

void setup() {
  Serial.begin(9600);

  /** 가속도(진동)센서 초기화 */
  myIMU.begin();
}

void loop()
{
  /** 센서값 읽어서 출력하기 X, Y, Z */
  Serial.print("\nAccelerometer:\n");
  Serial.print(" X = ");
  Serial.print(myIMU.readFloatAccelX(), 4);
  Serial.print(" Y = ");
  Serial.print(myIMU.readFloatAccelY(), 4);
  Serial.print(" Z = ");
  Serial.print(myIMU.readFloatAccelZ(), 4);

  delay(40);
}
