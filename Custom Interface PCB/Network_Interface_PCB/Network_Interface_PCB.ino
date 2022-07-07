#include <PCF8575.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>


#define input1 #
#define input2 #
#define input3 #
#define input4 #
#define input5 #
#define input6 #
#define input7 #
#define input8 #
#define input9 #
#define input10 #

#define output1 #
#define output2 #
#define output3 #
#define output4 #
#define output5 #
#define output6 #
#define output7 #
#define output8 #
#define output9 #
#define output10 #

//Mapped Topics
const char* topic_1 = "#";
const char* topic_2 = "#";
const char* topic_3 = "#";
const char* topic_4 = "#";
const char* topic_5 = "#";

const char* topic_6 = "#";
const char* topic_7 = "#";
const char* topic_8 = "#";
const char* topic_9 = "#";
const char* topic_10 = "#";

const char* topic_11 = "#";
const char* topic_12 = "#";
const char* topic_13 = "#";
const char* topic_14 = "#";
const char* topic_15 = "#";

const char* topic_16 = "#";
const char* topic_17 = "#";
const char* topic_18 = "#";
const char* topic_19 = "#";
const char* topic_20 = "#";


//wifi network
const char* ssid = "#";
const char* password = "#";


//mqtt network
const char* mqtt_server = "#";
const char* pass = "#";
const char* user = "#";

WiFiClient espClient;
PubSubClient client(espClient);

//functions
void setup_wifi() {
  delay(10);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
}


void setup() {
pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
