#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.

const char* ssid = "Semih";
const char* password = "128199sb";
const char* mqtt_server = "iot.eclipse.org";
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
char message_buff[100];
int value = 0;

void setup_wifi() {

  delay(10);
  pinMode(D6,OUTPUT);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
    int i = 0;
  for(i=0; i<length; i++) {
     Serial.print((char)payload[i]);
    message_buff[i] = payload[i];
  }
  message_buff[i] = '\0';
  String msgString = String(message_buff);

   if (msgString.equals("Turn Right")){
      Serial.println("status requested");
      digitalWrite(D6, 1023);
      
   }
      if (msgString.equals("Turn Left")){
      Serial.println("status requested");
      digitalWrite(D6, 0);
      
   }
  
   
  }
 

  // Switch on the LED if an 1 was received as first character
 



void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "SemihBAL215122589";
    char msg;
   
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello semih ");
      // ... and resubscribe
      client.subscribe("mqtt.spy/1", msg);
       
     // if (msg =="Turn Right") {
//digitalWrite(D6, 1023);
//}
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  

  long now = millis();
  if (now - lastMsg > 20000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 75, "hello amcik #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("mqtt.spy/1", msg);
  }
  
  }


  
 



