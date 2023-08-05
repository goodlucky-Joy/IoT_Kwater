#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "DHT.h"
#define DHTPIN D4     
#define DHTTYPE DHT11

#include <Wire.h>
#include <BH1750.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char *ssid = "myWifi";  
const char *password = "myPass";

WiFiUDP udp;
NTPClient timeClient(udp, "kr.pool.ntp.org", 32400, 900000);
char daysOfTheWeek[7][6] = { "Sun", "Mon", "Tue", "Wed",  "Thu", "Fri",  "Sat" };


void setup( ) {
  Serial.begin(9600);

  /** 온습도 센서 초기화 */
  dht.begin();

  /** 조도 센서 초기화 */
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

  /** WiFi 접속 */
  WiFi.begin(ssid, password);
  while( WiFi.status( ) != WL_CONNECTED ) {
    delay(500);    Serial.print(".");
  }

  /** NTP 초기화 */
  timeClient.begin( );
  timeClient.update( );

  /** OLED 초기화 */
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED(SSD1306) allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
}//end of setup

void loop() {

  /** NTP 시간 출력 */
  timeClient.update( );
  Serial.print( timeClient.getHours( ) );
  Serial.print(":");
  Serial.print( timeClient.getMinutes( ) );
  Serial.print(":");
  Serial.print( timeClient.getSeconds( ) );
  Serial.print("(");
  Serial.print( daysOfTheWeek[ timeClient.getDay( ) ] );
  //Serial.println( timeClient.getFormattedTime( ) );

  /** 온습도 센서 입력 */
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  /** 조도 센서 입력 */
  float lux = lightMeter.readLightLevel();

  /** 시리얼 출력 */
  Serial.print("), Temperature: ");  Serial.print(t);  Serial.print("[*C]");
  Serial.print(", Humidity: ");  Serial.print(h);  Serial.print("[%]");
  Serial.print(", Light: "); Serial.print(lux); Serial.println(" [lx]");

  /** OLED 출력 */
  display.clearDisplay();         // OLED 비디오 메모리 삭제
  display.setCursor(0,0);         // 커서의 위치를 0, 0으로 이동
  display.setTextSize(1);         // 폰트 사이즈 2로 변경
  display.println("Sensor Monitor");  // 제목, "Temp&Humi"출력
  display.setTextSize(1);         // 폰트 사이즈 1로 변경
  display.setCursor(0,20);        // 커서의 위치 0, 20으로 변경
  display.print("Temp: "); display.print(t); display.println(" [*C]");
  display.print("Humid: "); display.print(h); display.println(" [%]");
  display.print("Light: "); display.print(lux); display.println(" [lx]\n");
  
  display.print( timeClient.getHours( ) );
  display.print(":");
  display.print( timeClient.getMinutes( ) );
  display.print(":");
  display.print( timeClient.getSeconds( ) );
  display.print("(");
  display.print( daysOfTheWeek[ timeClient.getDay( ) ] );
  display.print(")");
  display.display();

  delay(1000);

}//end of loop
