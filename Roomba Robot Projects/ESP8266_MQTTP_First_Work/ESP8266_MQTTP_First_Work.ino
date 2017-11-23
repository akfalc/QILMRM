#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include "roombaDefines.h"
#include <SoftwareSerial.h>

// Roomba Create2 connection
int rxPin=13;
int txPin=15;
SoftwareSerial Roomba(rxPin,txPin);


// Update these with values suitable for your network.

const char* ssid = "SmartHome";
const char* password = "virslibabszalon";
const char* mqtt_server = "iot.eclipse.org";
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
char message_buff[100];
int value = 0;
int right=0;
int left=0;

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
    Roomba.begin(115200);
  
  Serial.begin(115200);
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

   if (msgString.equals("Start")){
      Serial.println("status requested");
      digitalWrite(D6, 1023);
      
   Roomba.write(128);  //Start
  Roomba.write(132);  //Full mode
  drive(100,100);
      
   }
   if (msgString.equals("Turn Left")){
      Serial.println("Turning left");
      digitalWrite(D6, 1023);
      
   Roomba.write(128);//Start
   Roomba.write(132);  //Full mode
   driveLeft(250);
  
delay(1000);
driveStop();
      
   }
      if (msgString.equals("Turn Right")){
      Serial.println("Turning Right requested");
      digitalWrite(D6, 1023);
      
   Roomba.write(128);
   Roomba.write(132);  //Full mode
   driveRight(250);
  
delay(1000);
driveStop();
      
   }
    if (msgString.equals("Go Forward")){
      Serial.println("Turning Right requested");
      digitalWrite(D6, 1023);
   motorSquareTest();
    }
    if (msgString.equals("Turn Back")){
      Serial.println("Turning Back is requested");
      digitalWrite(D6, 1023);
      
   Roomba.write(128);
   Roomba.write(132);  //Full mode
   drive(-50,-50);
  
delay(1000);
driveStop();
      
   }
      if (msgString.equals("Stop")){
      Serial.println("status requested");
      digitalWrite(D6, 0);
      driveStop();
      
      
   }


  
   
  }
     void driveLeft(int left)
{
  driveWheels(left, 0);
}
void driveWheels(int right, int left)
{
  clamp(right, -500, 500);
  clamp(left, -500, 500);
  
  Roomba.write(145);
  Roomba.write(right >> 8);
  Roomba.write(right);
  Roomba.write(left >> 8);
  Roomba.write(left);
  }

//---------------------------------------------------------------
void driveRight(int right)
{
  driveWheels(0, right);
}

void driveWheelsPWM(int rightPWM, int leftPWM)
{
  clamp(rightPWM, -255, 255);
  clamp(leftPWM, -255, 255);
  
  Roomba.write(146);
  Roomba.write(rightPWM >> 8);
  Roomba.write(rightPWM);
  Roomba.write(leftPWM >> 8);
  Roomba.write(leftPWM);
}
  void driveStop(void)
{
  drive(0,0);
}
 void wakeUp (void)
{
  setWarningLED(ON);
  digitalWrite(ddPin, HIGH);
  delay(100);
  digitalWrite(ddPin, LOW);
  delay(500);
  digitalWrite(ddPin, HIGH);
  delay(2000);
}
void setWarningLED(bool enable)
{
  warningLED = enable;
  Roomba.write(139);
  Roomba.write((debrisLED ? 1 : 0) + (spotLED ? 2 : 0) + (dockLED ? 4 : 0) + (warningLED ? 8 : 0));
  Roomba.write((byte)color);
  Roomba.write((byte)intensity);
}
void drive(int velocity, int radius)
{
  clamp(velocity, -500, 500); //def max and min velocity in mm/s
  clamp(radius, -2000, 2000); //def max and min radius in mm
  
  Roomba.write(137);
  Roomba.write(velocity >> 8);
  Roomba.write(velocity);
  Roomba.write(radius >> 8);
  Roomba.write(radius);
}

void motorSquareTest(void)
{  
  setPowerLED(0,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  turnCCW (30, 90);
  
  setPowerLED(64,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  turnCCW (30, 90);
  
  setPowerLED(128,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  turnCCW (30, 90);

  setPowerLED(190,128);
  drive (60, 0);
  delay(5000);
  driveStop();
  setPowerLED(255,128);
  turnCCW (30, 90);
  setPowerLED(0,0);
}
void turnCW(unsigned short velocity, unsigned short degrees)
{
  drive(velocity, -1);
  clamp(velocity, 0, 500);
  delay(6600);
  //delay((1580 + 2.25*velocity)/velocity*degrees);
  //delay((-0.03159720835 * velocity + 21.215270835) * degrees);
  drive(0,0);
}

//---------------------------------------------------------------
void turnCCW(unsigned short velocity, unsigned short degrees)
{
  drive(velocity, 1); 
  clamp(velocity, 0, 500);
  delay(6600);
  //delay(2708.3333/velocity*degrees);
  //delay((1580 + 2.25*velocity)/velocity*degrees);
  //delay((-0.03159720835 * velocity + 21.215270835) * degrees);
  drive(0,0);
}
void setPowerLED(byte setColor, byte setIntensity)
{
  color = setColor;
  intensity = setIntensity;
  Roomba.write(139);
  Roomba.write((byte)0x00);
  Roomba.write((byte)color);
  Roomba.write((byte)intensity);
}

//---------------------------------------------------------------
void setDebrisLED(bool enable)
{
  debrisLED = enable;
  Roomba.write(139);
  Roomba.write((debrisLED ? 1 : 0) + (spotLED ? 2 : 0) + (dockLED ? 4 : 0) + (warningLED ? 8 : 0));
  Roomba.write((byte)color);
  Roomba.write((byte)intensity);
}

//---------------------------------------------------------------
void setSpotLED(bool enable)
{
  spotLED = enable;
  Roomba.write(139);
  Roomba.write((debrisLED ? 1 : 0) + (spotLED ? 2 : 0) + (dockLED ? 4 : 0) + (warningLED ? 8 : 0));
  Roomba.write((byte)color);
  Roomba.write((byte)intensity);
}

//---------------------------------------------------------------
void setDockLED(bool enable)
{
  dockLED = enable;
  Roomba.write(139);
  Roomba.write((debrisLED ? 1 : 0) + (spotLED ? 2 : 0) + (dockLED ? 4 : 0) + (warningLED ? 8 : 0));
  Roomba.write((byte)color);
  Roomba.write((byte)intensity);
}

//---------------------------------------------------------------


/*--------------------------------------------------------------------------
This command controls the four 7 segment displays on the Roomba.*/
void setDigitLEDs(byte digit1, byte digit2, byte digit3, byte digit4)
{
    Roomba.write(163);
    Roomba.write(digit1);
    Roomba.write(digit2);
    Roomba.write(digit3);
    Roomba.write(digit4);
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


  
 



