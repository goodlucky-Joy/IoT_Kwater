from influxdb_client import InfluxDBClient, Point
from influxdb_client.client.write_api import SYNCHRONOUS
from datetime import datetime
import paho.mqtt.client as mqtt

## InfluxDB 연결 정보
url = "http://localhost:8086"
token = "DB_TOKEN"
bucket = "kwater"
org = "DB_ORG"

## InfluxDB 클라이언트 생성
client = InfluxDBClient(url=url, token=token)
write_api = client.write_api(write_options=SYNCHRONOUS) 

## MQTT 접속
def on_connect( client, userdata, flags, rc ):
    print("Connect with result code " + str(rc) )
    client.subscribe("kwater01/#")
    

## MQTT 메시지 수신
def on_message( client, userdata, msg ):
    print(msg.topic)
    print(msg.payload)
    data = msg.topic +" "+str(msg.payload)
#     print(data)
    
    ## 데이터 쓰기
    try:
        topic_parts = msg.topic.split('/')
        
        topic1 = topic_parts[0]
        topic2 = topic_parts[1]
        
        print("Topic 1:", topic1)
        print("Topic 2:", topic2)
        
        val = float(msg.payload)
        print("tmp:", val)
        
        
        # 데이터 생성
        if topic2 == 'temp':
            point = Point("kwater_IoT").tag("kwater_ch",topic1).field("temp",val).time(datetime.utcnow())
        elif topic2 == 'humid':
            point = Point("kwater_IoT").tag("kwater_ch",topic1).field("humid",val).time(datetime.utcnow())
        elif topic2 == 'light':
            point = Point("kwater_IoT").tag("kwater_ch",topic1).field("light",val).time(datetime.utcnow())
        else:
            print("No matching topic name", topic2)
        
        print(point)
        write_api.write(bucket=bucket, org=org, record=point)
        print("Success Insert data!")

    except ValueError:
        print("Invalid value:", msg.payload)

## MQTT Client 구독
client = mqtt.Client( )
client.username_pw_set(username="myMQTTid", password="myMQTTpass")
client.on_connect = on_connect
client.on_message = on_message

client.connect("localhost", 1883, 60)
client.loop_forever( )
