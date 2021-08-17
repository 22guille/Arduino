// SlaveSwapRoles

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN   9
#define CSN_PIN 10

const byte slaveAddressBlanco[5] = {'B','l','A','N','C'};
const byte masterAddressBlanco[5] = {'B','L','a','n','c'};

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

//char dataReceived[10]; // must match dataToSend in master
//int replyData[2] = {109, -4000}; // the two values to be sent to the master
int replyData = 0;
bool newData = false;

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second

int luz;
int LED = 2;

#define echoPin 7
#define trigPin 8
long duracion, distancia;

void setup() {

    Serial.begin(9600);

    Serial.println("SlaveSwapRoles Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );

    radio.openWritingPipe(masterAddressBlanco); // NB these are swapped compared to the master
    radio.openReadingPipe(1, slaveAddressBlanco);

    radio.setRetries(3,5); // delay, count
    radio.startListening();

    pinMode(LED, OUTPUT);
    //Sensor de proximidad
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

}

//====================

void loop() {
    getData();
    showData();
    send();
}

//====================

void send() {
    if (newData == true) {
        radio.stopListening();
            bool rslt;
            rslt = radio.write( &replyData, sizeof(replyData) );
        radio.startListening();
        
        Serial.print("Reply Sent ");
        Serial.print(replyData);
        Serial.print(", ");
        //Serial.println(replyData[1]);

        if (rslt) {
            Serial.println("Acknowledge Received");
            updateReplyData();
        }
        else {
            Serial.println("Tx failed");
        }
        Serial.println();
        newData = false;
    }
}

//================

void getData() {

    if ( radio.available() ) {
        radio.read( &luz, sizeof(luz) );
        updateReplyData();
        newData = true;
        radio.stopListening();
    }
}

//================

void showData() {
    if (newData == true) {
        Serial.print("Data received ");
        Serial.println(luz);
    }
}

//================

void updateReplyData() {
  while (luz == 2) {
    radio.stopListening();
    digitalWrite(LED, HIGH);
    //Serial.println(luz);
    digitalWrite(trigPin, LOW);   
    delayMicroseconds(2);           
    digitalWrite(trigPin, HIGH);   
    delayMicroseconds(10);         
    digitalWrite(trigPin, LOW);
     
    duracion = pulseIn(echoPin, HIGH);
    distancia = (duracion/2)/29;
    
    
    if (distancia <=15) {
      Serial.print(double(distancia)); 
      Serial.println(" cm.");
      digitalWrite(LED, LOW); 
      luz = 0;
      Serial.println(luz);
      replyData = 5;
    }
  }
}
