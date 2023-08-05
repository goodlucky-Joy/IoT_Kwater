### MQTT 설치 및 테스트 for Windows
### https://mosquitto.org/download
#### cd C:\Program Files\mosquitto
---
#### mosquitto.conf
##### #allow_anonymous true
##### #listener 1883
---
#### C:\Program Files\mosquitto>mosquitto -c mosquitto.conf –v

#### C:\Program Files\mosquitto>mosquitto_sub.exe -t "test"
#### C:\Program Files\mosquitto>mosquitto_pub.exe -t "test" -m "hello"

---
#### password.txt
##### myMQTTid1:myMQTTpass1
##### myMQTTid2:myMQTTpass2
---
#### mosquitto.conf
##### #allow_anonymous false
##### #password_file password.txt
---
#### C:\Program Files\mosquitto>mosquitto -c mosquitto.conf –v

#### C:\Program Files\mosquitto>mosquitto_sub -v -t test -p 1883 -h myMQTTserverIP -u myMQTTid -P myMQTTpass
#### C:\Program Files\mosquitto>mosquitto_pub -t test -m "Hi" -p 1883 -h myMQTTserverIP -u myMQTTid -P myMQTTpass
#### C:\Program Files\mosquitto>mosquitto_pub -t temp -m “34.2" -p 1883 -h myMQTTserverIP -u myMQTTid -P myMQTTpass
#### C:\Program Files\mosquitto>mosquitto_pub -t test -m "Hola!" -p 1883 -h myMQTTserverIP -u myMQTTid -P myMQTTpass

