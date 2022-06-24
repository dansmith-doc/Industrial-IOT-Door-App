#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//IO Config//
#define openCMD 14 //No need to have a close CMD Pin, Door Auto closes.
#define openLimit 4
#define closeLimit 5

String nodeID = "ESP";

//Topics//
const char* statusTopic = "ADD_TOPIC"; //Add your topic here
const char* cmdTopic = "ADD_TOPIC"; //Add your topic here

const char* ssid = "IP_ADDRESS_HERE"; //Add your IP here
const char* password = "PASSWORD"; // Add your Password here

//MQTT//
const char* mqtt_server = "MQTT_IP"; //Add your IP here
const char* pass = "PASSWORD"; // Add your Password here
const char* user = "USERNAME"; // Add your Username here

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  WiFi.hostname("nodeID");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}

void callback(char* topic, byte* payload, unsigned int length) {
  if ((char)payload[0] == '1') {
    digitalWrite(openCMD, HIGH);
  } else {
    digitalWrite(openCMD, LOW);
  }

}

void reconnect() {
    String clientId = "nodeID";
    clientId += String(random(0xffff), HEX);
    client.connect(clientId.c_str(), user, pass);
    client.subscribe(cmdTopic);
    delay(5000);
}

void logic(){
  if (digitalRead(openLimit) == LOW) {
    client.publish(statusTopic, "OPEN");
  }
  if (digitalRead(closeLimit) == LOW) {
    client.publish(statusTopic, "CLOSED");
  }
  if ( (digitalRead(openLimit) == HIGH) && (digitalRead(closeLimit) == HIGH) ){
    client.publish(statusTopic, "WAITING...");
  }
  if ( (digitalRead(openLimit) == LOW) && (digitalRead(closeLimit) == LOW) ){
    client.publish(statusTopic, "ERROR");
}
}

void setup() {
  //Pin Setup//
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(openCMD, OUTPUT);
  pinMode(openLimit, INPUT);
  pinMode(closeLimit, INPUT);

  //Services//
  setup_wifi();
  client.setServer(mqtt_server, 1900);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
    digitalWrite(BUILTIN_LED, LOW);
  }

  if (client.connected()) {
    digitalWrite(BUILTIN_LED, HIGH);
  }
  
  client.loop();

  logic();

  delay(2000);
  }
