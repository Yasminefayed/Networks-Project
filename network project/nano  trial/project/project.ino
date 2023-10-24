#include <PubSubClient.h>
//https://docs.arduino.cc/tutorials/uno-wifi-rev2/uno-wifi-r2-mqtt-device-to-device
//#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
#include <SPI.h>

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = "WE_CE18AB";       // your network SSID (name)
char pass[] = "k8a15001"  ;  // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

const char broker[] = "test.mosquitto.org";
int        port     = 1883;
const char topic[]  = "this is";
const char topic2[]  = "a trial";
const char topic3[]  = "by yasmeen";

//set interval for sending messages (milliseconds)
const long interval = 8000;
unsigned long previousMillis = 0;

int count = 0;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  // attempt to connect to Wifi network:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }
 while (WiFi.begin(ssid, pass) == WL_CONNECTED) 
 {
    Serial.print("Connected to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);
    delay(10000);
  }

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);
  mqttClient.setServer(broker, port);
 while(1){
  if (!mqttClient.connect("ard","chehab","123456789")) {
    Serial.println("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.state());
  }
  else  break; 
  }
  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
}

void loop() {

  {
Serial.println("publishing string ");
  boolean rc = mqttClient.publish("test","test Message");
  /*byte outmsg[]={0xff,0xfe};
  Serial.println("publishing bytes");
   rc = mqttClient.publish("testbyte", outmsg,2);
    delay(1000); //wait*/
    mqttClient.loop(); //call loop
  }

}

