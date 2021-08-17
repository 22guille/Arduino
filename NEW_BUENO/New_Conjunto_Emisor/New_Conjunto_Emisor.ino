// MasterSwapRoles

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <SoftwareSerial.h>


#define CE_PIN   9
#define CSN_PIN 10

const byte slaveAddressVerde[5] = {'V','e','R','D','E'};
const byte masterAddressVerde[5] = {'V','E','r','d','e'};

const byte slaveAddressRojo[5] = {'R','o','J','O','O'};
const byte masterAddressRojo[5] = {'R','O','j','o','o'};

const byte slaveAddressAzul[5] = {'A','z','U','L','L'};
const byte masterAddressAzul[5] = {'A','Z','u','l','l'};

const byte slaveAddressBlanco[5] = {'B','l','A','N','C'};
const byte masterAddressBlanco[5] = {'B','L','a','n','c'};

const byte slaveAddressAmarillo[5] = {'A','m','A','R','I'};
const byte masterAddressAmarillo[5] = {'A','M','a','r','i'};


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[10] = "Message 0";
char txNum = '0';
//int dataReceived[2]; // to hold the data from the slave - must match replyData[] in the slave
int dataReceivedV;
int dataReceivedR;
int dataReceivedA;
int dataReceivedB;
int dataReceivedAm;
bool newData = false;

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis;// = 2000; // send once per second

int randNumber = 0;
int randNumber2 = 0;

//SoftwareSerial miBT(6,7); //Rx | Tx
char BT;
char tiempo;
char color;
//============

void setup() {
    
    Serial.begin(9600);

    Serial.println("MasterSwapRoles Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    


    radio.setRetries(3,5); // delay, count
    //colores();
    //send(); // to get things started
    //dobles();
    prevMillis = millis(); // set clock
}

//=============

void progTime(){
  if (Serial.available()){
      tiempo = (char)Serial.read();
      Serial.print("Tiempo =");
      Serial.println(tiempo);
   } else {
    txIntervalMillis = 2000;
    send();
   }
     while (tiempo == 'A') {
      txIntervalMillis = 0;
      programa();
     } 
     while (tiempo == 'B') {
      txIntervalMillis = 1000;
      programa();
     } 
     while (tiempo == 'C') {
      txIntervalMillis = 2000;
      programa();
     } 
     while (tiempo == 'E') {
      txIntervalMillis = 3000;
      programa();
     } 
     while (tiempo == 'F') {
      txIntervalMillis = 4000;
      programa();
     } 
     while (tiempo == 'G') {
      txIntervalMillis = 5000;
      programa();
     }
}
void programa(){
   if (Serial.available()){
      BT = (char)Serial.read();
      Serial.print("BT =");
      Serial.println(BT);
      Serial.println(txIntervalMillis);
   }
     while (BT == 'S') {
      send();
     } 
     while (BT == 'D') {
      dobles();
     } 
     while (BT == '1'){
      colores();
     }
}
void loop() {
    progTime();
    currentMillis = millis();
    /*if (currentMillis - prevMillis >= txIntervalMillis) {
        //programa();
        send();
        //dobles();
        prevMillis = millis();
    }
   //getData();
   //showData();*/
   /*if (Serial.available()){
      BT = (char)Serial.read();
      Serial.print("BT =");
      Serial.println(BT);
   }
    if (BT == 'S') {
    send();
   } else if (BT == 'D') {
    dobles();
   }*/
}

//====================
void colores(){
if (Serial.available()){
      color = (char)Serial.read();
      Serial.print("Color =");
      Serial.println(color);
   }
//VERDE
  while (color == '2'){
    radio.openWritingPipe(slaveAddressVerde);
    radio.openReadingPipe(1, masterAddressVerde);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(color);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            color = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            color = 0;
          }
            }
        }
    }
    while (color == '3'){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(color);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            color = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            color = 0;
          }
            }
        }
  }
//AZUL
  while (color == '4'){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(color);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            color = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            color = 0;
          }
            }
        }
  }
//BLANCO
  while (color == '5'){
    radio.openWritingPipe(slaveAddressBlanco);
    radio.openReadingPipe(1, masterAddressBlanco);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(color);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            color = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            color = 0;
          }
            }
        }
  }
/*//AMARILLO
  while (color == '6'){
    radio.openWritingPipe(slaveAddressAmarillo);
    radio.openReadingPipe(1, masterAddressAmarillo);
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
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            color = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            color = 0;
          }
            }
        }
  }*/
}

void send() {
currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
      
randNumber = random(2,6);
Serial.print("RANDOM: ");
Serial.println(randNumber);
//VERDE
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
//ROJO
 while (randNumber == 3){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
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
//AZUL
  while (randNumber == 4){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
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
//BLANCO
  while (randNumber == 5){
    radio.openWritingPipe(slaveAddressBlanco);
    radio.openReadingPipe(1, masterAddressBlanco);
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
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            randNumber = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            randNumber = 0;
          }
            }
        }
  }
/*//AMARILLO
  while (randNumber == 6){
    radio.openWritingPipe(slaveAddressAmarillo);
    radio.openReadingPipe(1, masterAddressAmarillo);
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
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            randNumber = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            randNumber = 0;
          }
            }
        }
  }*/
  prevMillis = millis();
    }
}

//=======

void dobles(){
currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {

  randNumber = random(2,12);
Serial.print("RANDOM: ");
Serial.println(randNumber);
//VERDE-ROJO
if (randNumber == 2){
  int verde = 1;
  int rojo = 2;
  while ((verde == 1 && rojo == 2)||(verde == 0 && rojo == 2)||(verde == 1 && rojo == 0)){
    if (verde == 1){
    radio.openWritingPipe(slaveAddressVerde);
    radio.openReadingPipe(1, masterAddressVerde);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(verde);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
  }
 if (rojo == 2){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(rojo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
       }
     }
  }
//VERDE-AZUL
if (randNumber == 3){
  int verde = 1;
  int azul = 2;
  while ((verde == 1 && azul == 2)||(verde == 0 && azul == 2)||(verde == 1 && azul == 0)){
    if (verde == 1){
    radio.openWritingPipe(slaveAddressVerde);
    radio.openReadingPipe(1, masterAddressVerde);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(verde);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
  }
 if (azul == 2){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(azul);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
       }
     }
  }
//VERDE-BLANCO
if (randNumber == 4){
  int verde = 1;
  int blanco = 2;
  while ((verde == 1 && blanco == 2)||(verde == 0 && blanco == 2)||(verde == 1 && blanco == 0)){
    if (verde == 1){
    radio.openWritingPipe(slaveAddressVerde);
    radio.openReadingPipe(1, masterAddressVerde);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(verde);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
  }
 if (blanco == 2){
    radio.openWritingPipe(slaveAddressBlanco);
    radio.openReadingPipe(1, masterAddressBlanco);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(blanco);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
       }
     }
  }
/*//VERDE-AMARILLO
if (randNumber == 5){
  int verde = 1;
  int azul = 2;
  while ((verde == 1 && azul == 2)||(verde == 0 && azul == 2)||(verde == 1 && azul == 0)){
    if (verde == 1){
    radio.openWritingPipe(slaveAddressVerde);
    radio.openReadingPipe(1, masterAddressVerde);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(verde);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedV, sizeof(dataReceivedV) );
        Serial.println(dataReceivedV);
          if(dataReceivedV == 2){
            verde = 0;
          }
            }
        }
  }
 if (amarillo == 2){
    radio.openWritingPipe(slaveAddressAmarillo);
    radio.openReadingPipe(1, masterAddressAmarillo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(amarillo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
       }
     }
  }*/
//ROJO-AZUL
if (randNumber == 6){
  int rojo = 1;
  int azul = 2;
  while ((rojo == 1 && azul == 2)||(rojo == 0 && azul == 2)||(rojo == 1 && azul == 0)){
    if (rojo == 1){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(rojo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
  }
 if (azul == 2){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(azul);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
       }
     }
  }
//ROJO-BLANCO
if (randNumber == 7){
  int rojo = 1;
  int blanco = 2;
  while ((rojo == 1 && blanco == 2)||(rojo == 0 && blanco == 2)||(rojo == 1 && blanco == 0)){
    if (rojo == 1){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(rojo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedV == 3){
            rojo = 0;
          }
            }
        }
  }
 if (blanco == 2){
    radio.openWritingPipe(slaveAddressBlanco);
    radio.openReadingPipe(1, masterAddressBlanco);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(blanco);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
       }
     }
  }
/*//ROJO-AMARILLO
if (randNumber == 8){
  int rojo = 1;
  int amarillo = 2;
  while ((rojo == 1 && amarillo == 2)||(rojo == 0 && amarillo == 2)||(rojo == 1 && amarillo == 0)){
    if (rojo == 1){
    radio.openWritingPipe(slaveAddressRojo);
    radio.openReadingPipe(1, masterAddressRojo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(rojo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedR, sizeof(dataReceivedR) );
        Serial.println(dataReceivedR);
          if(dataReceivedR == 3){
            rojo = 0;
          }
            }
        }
  }
 if (amarillo == 2){
    radio.openWritingPipe(slaveAddressAmarillo);
    radio.openReadingPipe(1, masterAddressAmarillo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(amarillo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
       }
     }
  }*/
//AZUL-BLANCO
if (randNumber == 9){
  int azul = 1;
  int blanco = 2;
  while ((azul == 1 && blanco == 2)||(azul == 0 && blanco == 2)||(azul == 1 && blanco == 0)){
    if (azul == 1){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(azul);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
  }
 if (blanco == 2){
    radio.openWritingPipe(slaveAddressBlanco);
    radio.openReadingPipe(1, masterAddressBlanco);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(blanco);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
       }
     }
  }
/*//AZUL-AMARILLO
if (randNumber == 10){
  int azul = 1;
  int amarillo = 2;
  while ((azul == 1 && amarillo == 2)||(azul == 0 && amarillo == 2)||(azul == 1 && amarillo == 0)){
    if (azul == 1){
    radio.openWritingPipe(slaveAddressAzul);
    radio.openReadingPipe(1, masterAddressAzul);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.println(azul);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedA, sizeof(dataReceivedA) );
        Serial.println(dataReceivedA);
          if(dataReceivedA == 4){
            azul = 0;
          }
            }
        }
  }
 if (amarillo == 2){
    radio.openWritingPipe(slaveAddressAmarillo);
    radio.openReadingPipe(1, masterAddressAmarillo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(amarillo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
       }
     }
  }*/
/*//BLANCO-AMARILLO
if (randNumber == 11){
  int blanco = 1;
  int amarillo = 2;
  while ((blanco == 1 && amarillo == 2)||(blanco == 0 && amarillo == 2)||(blanco == 1 && amarillo == 0)){
    if (blanco == 2){
    radio.openWritingPipe(slaveAddressBlanco);
    radio.openReadingPipe(1, masterAddressBlanco);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(blanco);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedB, sizeof(dataReceivedB) );
        Serial.println(dataReceivedB);
          if(dataReceivedB == 5){
            blanco = 0;
          }
            }
        }
       }
 if (amarillo == 2){
    radio.openWritingPipe(slaveAddressAmarillo);
    radio.openReadingPipe(1, masterAddressAmarillo);
        radio.stopListening();
        int luz = 2;
            bool rslt;
            rslt = radio.write( &luz, sizeof(luz) );
        radio.startListening();
        Serial.print("Data Sent ");
        Serial.print(amarillo);
        if (rslt) {
            Serial.println("  Acknowledge received");
            //updateMessage();
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
        else {
            Serial.println("  Tx failed");
            if ( radio.available() ) {
        radio.read( &dataReceivedAm, sizeof(dataReceivedAm) );
        Serial.println(dataReceivedAm);
          if(dataReceivedAm == 6){
            amarillo = 0;
          }
            }
        }
       }
     }
  }*/
    prevMillis = millis();
    }
}
