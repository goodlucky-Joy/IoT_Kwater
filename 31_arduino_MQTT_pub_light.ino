#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>

#include <Wire.h>
#include <BH1750.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  

BH1750 lightMeter;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/** Wifi 접속 설정 */
const char* ssid = "myWifi";
const char* password = "myPass";

WiFiClient espClient;

/** MQTT 접속 설정 */
const char* mqttServer = "myMQTTserverIP";
const int mqttPort = 1883;
const char* mqttUser = "myMQTTid";
const char* mqttPassword = "myMQTTpass";
const char* topic = "light";

PubSubClient client(espClient);

/** NTP 설정 */
WiFiUDP udp;
NTPClient timeClient(udp, "kr.pool.ntp.org", 32400, 900000);
char daysOfTheWeek[7][6] = { "Sun", "Mon", "Tue", "Wed",  "Thu", "Fri",  "Sat" };

void setup() {
  Serial.begin(9600);
  
  /** 센서 초기화 */
  Wire.begin();
  lightMeter.begin();
  Serial.println(F("BH1750 Test begin"));

  /** Wi-Fi 접속 */
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("Local IP address : "); Serial.println(WiFi.localIP());
  
  /** MQTT 접속 */
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  while (!client.connected()) {
    if (client.connect("ESP32Client", mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT Broker");
    } else {
      Serial.print("Failed to connect to MQTT Broker, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }

  /** NTP */
  timeClient.begin( );
  timeClient.update( );

  /**OLED 초기화 */
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED(SSD1306) allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
}//end of setup

void loop() {

  /** 센서 입력 */
  float lux = lightMeter.readLightLevel();

  /** MQTT 밝기정보 전송 */
  char msg[20];
  String str = String(lux);
  str.toCharArray(msg, sizeof(msg));
  client.publish(topic, msg);
  Serial.print(topic); Serial.print(" : "); Serial.println(msg);

  /** 시리얼 출력 */
  Serial.print(", Light: " + (String)lux + " [lx]\n");

  /** OLED 출력 */
  display.clearDisplay();         // OLED 비디오 메모리 삭제
  display.setCursor(0,0);         // 커서의 위치를 0, 0으로 이동
  display.setTextSize(1);         // 폰트 사이즈 2로 변경
  display.println("Sensor Monitor");  // 제목, "Temp&Humi"출력
  display.setTextSize(1);         // 폰트 사이즈 1로 변경
  display.setCursor(0,20);        // 커서의 위치 0, 20으로 변경

  display.print("Light: " + (String)lux + " [lx]\n");
  
  display.print( timeClient.getHours( ) ); display.print(":");
  display.print( timeClient.getMinutes( ) ); display.print(":");
  display.print( timeClient.getSeconds( ) ); display.print("(");
  display.print( daysOfTheWeek[ timeClient.getDay( ) ] ); display.print(")");
   
  display.display();

  delay(5000); // Publish every 5 seconds
}//end of loop

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle incoming MQTT messages if needed
}
