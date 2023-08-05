/****** Download and Install NTPClient-master.zip ( https://github.com/taranais/NTPClient ) ******/

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "myWiFi";  
const char *password = "myPass";

WiFiUDP udp;
//NTPClient timeClient(udp, "kr.pool.ntp.org");
NTPClient timeClient(udp, "kr.pool.ntp.org", 32400, 900000);

char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",  "Saturday" };

void setup( ) {
  Serial.begin(9600);

  /** WiFi 접속 */
  WiFi.begin(ssid, password);
  while( WiFi.status( ) != WL_CONNECTED ) {
    delay(500);    Serial.print(".");
  }

  /** NTP 초기화 */
  timeClient.begin( );
  timeClient.update( );
}

void loop() {
  /** 네트워크 시간 출력 */
  timeClient.update( );
  Serial.println( timeClient.getFormattedTime( ) );

  //Serial.print( daysOfTheWeek[ timeClient.getDay( ) ] );
  //Serial.print(", ");
  //Serial.print( timeClient.getHours( ) );
  //Serial.print(":");
  //Serial.print( timeClient.getMinutes( ) );
  //Serial.print(":");
  //Serial.println( timeClient.getSeconds( ) );
  delay(1000);

}
