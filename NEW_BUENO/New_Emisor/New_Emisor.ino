// MasterSwapRoles

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


#define CE_PIN   9
#define CSN_PIN 10

const byte slaveAddressVerde[5] = {'V','e','R','D','E'};
const byte masterAddressVerde[5] = {'V','E','r','d','e'};

const byte slaveAddressRojo[5] = {'R','o','J','O','O'};
const byte masterAddressRojo[5] = {'R','O','j','o','o'};

const byte slaveAddressAzul[5] = {'A','z','U','L','L'};
const byte masterAddressAzul[5] = {'A','Z','u','l','l'};


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[10] = "Message 0";
char txNum = '0';
//int dataReceived[2]; // to hold the data from the slave - must match replyData[] in the slave
int dataReceivedV;
int dataReceivedR;
int dataReceivedA;
bool newData = false;

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 2000; // send once per second

int randNumber = 0;
int randNumber2 =0;
//============

void setup() {

    Serial.begin(9600);

    Serial.println("MasterSwapRoles Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    


    radio.setRetries(3,5); // delay, count
    send(); // to get things started
    prevMillis = millis(); // set clock
}

//=============

void loop() {
    currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
        send();
        prevMillis = millis();
    }
   //getData();
   //showData();
}

//====================

void send() {

randNumber = random(2,5);
Serial.print("RANDOM: ");
Serial.println(randNumber);
  while (randNumber == 2){
    radio.openWritingPipe(slaveAddressVerde);
    radio.openReadingPipe(1, masterAddressVerde);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(randNumber);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            randNumber = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            randNumber = 0;
          }
            }
        }
  }
 while (randNumber == 3){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(randNumber);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            randNumber = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            randNumber = 0;
          }
            }
        }
  }
  while (randNumber == 4){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(randNumber);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            randNumber = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            randNumber = 0;
          }
            }
        }
  }
}
