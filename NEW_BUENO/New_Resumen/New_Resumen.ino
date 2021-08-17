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

char BT;
char tiempo;
char color;

int verde;
int rojo;
int azul;
int blanco;
int amarillo;
//============

void setup() {
    
    Serial.begin(9600);

    Serial.println("MasterSwapRoles Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    
    radio.setRetries(3,5); // delay, count
    //colores();
    //single(); // to get things started
    //dobles();
    //progTime();
    prevMillis = millis(); // set clock
}

//=============

void progTime(){
  if (Serial.available()){
      tiempo = (char)Serial.read();
      Serial.print("Tiempo =");
      Serial.println(tiempo);
   } /*else {
    txIntervalMillis = 2000;
    single();
   }*/
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
     if (BT == 'S') {
      single();
     } 
     if (BT == 'D') {
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
        single();
        //dobles();
        prevMillis = millis();
    }

   /*if (Serial.available()){
      BT = (char)Serial.read();
      Serial.print("BT =");
      Serial.println(BT);
   }
    if (BT == 'S') {
    single();
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
  if (color == '2'){
    Verde();
    }
//ROJO
  if (color == '3'){
    Rojo();   
  }
//AZUL
  if (color == '4'){
    Azul();
  }
//BLANCO
  if (color == '5'){
    Blanco();
  }
//AMARILLO
  if (color == '6'){
    Amarillo();
  }
  /*if (color != 0 && color != '2' && color != '3' && color != '4' && color!= '5' && color != '6'){
    programa();
  }*/
}

void single() {
currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
      randNumber = random(2,7);
      Serial.print("RANDOM: ");
      Serial.println(randNumber);
      //VERDE
      while (randNumber == 2){
        Verde();
      }
      //ROJO
      while (randNumber == 3){
        Rojo();
      }
      //AZUL
      while (randNumber == 4){
        Azul();
      }
      //BLANCO
      while (randNumber == 5){
        Blanco();
      }
      //AMARILLO
      while (randNumber == 6){
        Amarillo();
      }
      prevMillis = millis();
    }
}

//=======

void dobles(){
currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {

  randNumber2 = random(2,12);
Serial.print("RANDOM: ");
Serial.println(randNumber2);
//VERDE-ROJO
if (randNumber2 == 2){
  verde = 1;
  rojo = 2;
  while ((verde == 1 && rojo == 2)||(verde == 0 && rojo == 2)||(verde == 1 && rojo == 0)){
    if (verde == 1){
      Verde();
    }
    if (rojo == 2){
      Rojo();
    }
  }
}
//VERDE-AZUL
if (randNumber2 == 3){
  verde = 1;
  azul = 2;
  while ((verde == 1 && azul == 2)||(verde == 0 && azul == 2)||(verde == 1 && azul == 0)){
    if (verde == 1){
      Verde();
    }
    if (azul == 2){
      Azul();
    }
  }
}
//VERDE-BLANCO
if (randNumber2 == 4){
  verde = 1;
  blanco = 2;
  while ((verde == 1 && blanco == 2)||(verde == 0 && blanco == 2)||(verde == 1 && blanco == 0)){
    if (verde == 1){
      Verde();
    }
    if (blanco == 2){
      Blanco();
    }
  }
}
//VERDE-AMARILLO
if (randNumber2 == 5){
  verde = 1;
  amarillo = 2;
  while ((verde == 1 && amarillo == 2)||(verde == 0 && amarillo == 2)||(verde == 1 && amarillo == 0)){
    if (verde == 1){
      Verde();
    }
    if (amarillo == 2){
      Amarillo();
    }
   }
}
//ROJO-AZUL
if (randNumber2 == 6){
  rojo = 1;
  azul = 2;
  while ((rojo == 1 && azul == 2)||(rojo == 0 && azul == 2)||(rojo == 1 && azul == 0)){
    if (rojo == 1){
      Rojo();
    }
    if (azul == 2){
      Azul();
    }
  }
}
//ROJO-BLANCO
if (randNumber2 == 7){
  rojo = 1;
  blanco = 2;
  while ((rojo == 1 && blanco == 2)||(rojo == 0 && blanco == 2)||(rojo == 1 && blanco == 0)){
    if (rojo == 1){
      Rojo();
    }
    if (blanco == 2){
      Blanco();
    }
  }
}
//ROJO-AMARILLO
if (randNumber2 == 8){
  rojo = 1;
  amarillo = 2;
  while ((rojo == 1 && amarillo == 2)||(rojo == 0 && amarillo == 2)||(rojo == 1 && amarillo == 0)){
    if (rojo == 1){
      Rojo();
    }
    if (amarillo == 2){
      Amarillo();
    }
  }
}
//AZUL-BLANCO
if (randNumber2 == 9){
  azul = 1;
  blanco = 2;
  while ((azul == 1 && blanco == 2)||(azul == 0 && blanco == 2)||(azul == 1 && blanco == 0)){
    if (azul == 1){
      Azul();
    }
    if (blanco == 2){
      Blanco();
    }
  }
}
//AZUL-AMARILLO
if (randNumber2 == 10){
  azul = 1;
  amarillo = 2;
  while ((azul == 1 && amarillo == 2)||(azul == 0 && amarillo == 2)||(azul == 1 && amarillo == 0)){
    if (azul == 1){
      Azul();
    }
    if (amarillo == 2){
      Amarillo();
    }
  }
}
//BLANCO-AMARILLO
if (randNumber2 == 11){
  blanco = 1;
  amarillo = 2;
  while ((blanco == 1 && amarillo == 2)||(blanco == 0 && amarillo == 2)||(blanco == 1 && amarillo == 0)){
    if (blanco == 1){
      Blanco();
    }
    if (amarillo == 2){
      Amarillo();
    }
  }
}
    prevMillis = millis();
    }
}
//----------------------------------------DEFINICIÓN COLORES------------------------------------//
void Verde(){
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
            randNumber = 0;
            verde = 0;
            Serial.print("COLOR: ");
            Serial.println(verde);
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
            randNumber = 0;
            verde = 0;
            Serial.print("COLOR: ");
            Serial.println(verde);
          }
            }
        }
}

void Rojo(){
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
            randNumber = 0;
            rojo = 0;
            Serial.print("COLOR: ");
            Serial.println(rojo);
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
            randNumber = 0;
            rojo = 0;
            Serial.print("COLOR: ");
            Serial.println(rojo);
          }
            }
        }
}

void Azul(){
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
            randNumber = 0;
            azul = 0;
            Serial.print("COLOR: ");
            Serial.println(azul);
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
            randNumber = 0;
            azul = 0;
            Serial.print("COLOR: ");
            Serial.println(azul);
          }
            }
        }
}

void Blanco(){
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
            randNumber = 0;
            blanco = 0;
            Serial.print("COLOR: ");
            Serial.println(blanco);
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
            randNumber = 0;
            blanco = 0;
            Serial.print("COLOR: ");
            Serial.println(blanco);
          }
            }
        }
}

void Amarillo(){
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
            randNumber = 0;
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
            color = 0;
            randNumber = 0;
            amarillo = 0;
          }
            }
        }
}
