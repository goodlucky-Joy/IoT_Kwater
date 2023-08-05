/********************************************************************/
/****** Install DHT sensor library by Adafruit (Install all!!) ******/
/********************************************************************/

#include "DHT.h"
#define DHTPIN D4        // pin D4      
#define DHTTYPE DHT11    // DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  /** 시리얼 모니터 초기화 */
  Serial.begin(9600);

  /** DHT11 초기화 */
  dht.begin();
}

void loop() {

  /** 센서값 읽기 */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  /** 시리얼모니터에 출력 */
  Serial.print("Humidity: ");  Serial.print(h);  Serial.print("[%]\t");
  Serial.print("Temperature: ");  Serial.print(t);  Serial.println("[*C]");

  /** 2초 기다림 */
  delay(2000);
}
