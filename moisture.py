import paho.mqtt.client as mqtt
import time
import random

# MQTT Settings
BROKER = "broker.hivemq.com"
PORT = 1883
TOPIC = "khilal/moisture"

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.connect(BROKER, PORT, 60)

print("Sending moisture data... Press Ctrl+C to stop")

while True:
    moisture = random.randint(0, 100)
    client.publish(TOPIC, moisture)
    print(f"Sent: {moisture}%")
    time.sleep(2)
