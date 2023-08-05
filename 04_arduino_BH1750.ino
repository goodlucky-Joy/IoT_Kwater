/*******************************************/
/****** BH1750 (0x23 or 0x5C)         ******/
/****** Install BH1750 by Christopher ******/
/*******************************************/

#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup(){
  Serial.begin(9600);

  /** 조도센서 초기화 */
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));
}

void loop() {

  /** 조도센서값 읽기 */
  float lux = lightMeter.readLightLevel();

  /** 시리얼 모니터에 출력 */
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" [lx]");
  delay(1000);
}
