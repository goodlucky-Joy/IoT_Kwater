#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/** WiFi 접속 설정 */
const char* ssid = "myWifi";
const char* password = "myPass";

/** MQTT 접속 설정 */
const char* userId = "myMQTTid";
const char* userPw = "myMQTTpass";
const char* clientId = userId;
char* topic = "temp";
char* server = "myMQTTserverIP";

WiFiClient wifiClient; 
PubSubClient client(server, 1883, wifiClient);

void setup() {
  Serial.begin(9600);

  /** Wifi 접속 */
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nWiFi Connected");
  Serial.print("Local IP address : ");
  Serial.println(WiFi.localIP());

  /** MQTT 접속 */
  Serial.println("Connecting to broker");
  while ( !client.connect(clientId, userId, userPw) ){ 
    Serial.print("*");
    delay(1000);
  }
  Serial.println("\nConnected to broker");
}

void loop() {
  /** Topic(토픽)과 Message(메시지) 보내기 */
  client.publish(topic, "32.32");
  Serial.println(String(topic) + " : 32.32");
  delay(2000);
}
