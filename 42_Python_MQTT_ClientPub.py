import paho.mqtt.client as mqtt

mqtt = mqtt.Client( )
#mqtt.username_pw_set("myMQTTid", "myMQTTpass")
mqtt.connect("localhost", 1883)

mqtt.publish("temp", "37.4")
print(“Success!")

mqtt.loop()
print("Exit")
