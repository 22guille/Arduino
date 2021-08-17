long randNumber;
int ledBlanco = 2;
int ledRojo = 3;
int ledVerde = 4;
int ledAmarillo = 5;
#define echoPinBlanco 6
#define trigPinBlanco 7
#define echoPinRojo 8
#define trigPinRojo 9
#define echoPinVerde 10
#define trigPinVerde 11
#define echoPinAmarillo 12 
#define trigPinAmarillo 13
long duracion, distanciaBlanco, distanciaRojo, distanciaVerde, distanciaAmarillo;
unsigned long tiempo;
unsigned long t = 0;
int Dt = 2000;


void setup() {

  Serial.begin(9600);
  pinMode(ledBlanco, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode (ledAmarillo, OUTPUT);
  randomSeed(analogRead(0));
  pinMode(trigPinBlanco, OUTPUT);
  pinMode(echoPinBlanco, INPUT);
  pinMode(trigPinRojo, OUTPUT);
  pinMode(echoPinRojo, INPUT);
  pinMode(trigPinVerde, OUTPUT);
  pinMode(echoPinVerde, INPUT);
  pinMode(trigPinAmarillo, OUTPUT);
  pinMode(echoPinAmarillo, INPUT);
}

void loop() {
//SENSOR BLANCO
  digitalWrite(trigPinBlanco, LOW);   
  delayMicroseconds(2);           
  digitalWrite(trigPinBlanco, HIGH);   
  delayMicroseconds(10);         
  digitalWrite(trigPinBlanco, LOW);
      
  duracion = pulseIn(echoPinBlanco, HIGH);
  distanciaBlanco = (duracion/2)/29;
  Serial.println(String(distanciaBlanco) + " cm.") ;

//SENSOR ROJO
  digitalWrite(trigPinRojo, LOW);   
  delayMicroseconds(2);           
  digitalWrite(trigPinRojo, HIGH);   
  delayMicroseconds(10);         
  digitalWrite(trigPinRojo, LOW);     
   
  duracion = pulseIn(echoPinRojo, HIGH);
  distanciaRojo = (duracion/2)/29;
  Serial.println(String(distanciaRojo) + " cm.") ;

//SENSOR VERDE
  digitalWrite(trigPinVerde, LOW);   
  delayMicroseconds(2);           
  digitalWrite(trigPinVerde, HIGH);   
  delayMicroseconds(10);         
  digitalWrite(trigPinVerde, LOW);     
   
  duracion = pulseIn(echoPinVerde, HIGH);
  distanciaVerde = (duracion/2)/29;
  Serial.println(String(distanciaVerde) + " cm.") ;

//SENSOR AMARILLO
  digitalWrite(trigPinAmarillo, LOW);   
  delayMicroseconds(2);           
  digitalWrite(trigPinAmarillo, HIGH);   
  delayMicroseconds(10);         
  digitalWrite(trigPinAmarillo, LOW);     
   
  duracion = pulseIn(echoPinAmarillo, HIGH);
  distanciaAmarillo = (duracion/2)/29;
  Serial.println(String(distanciaAmarillo) + " cm.") ;

//TIEMPO

  tiempo = millis();
  if (tiempo-t > Dt){
    t = tiempo;
    Serial.print("tiempo: ");
    Serial.print(millis());
  

//RANDNUMBER

  randNumber = random(2,6);
  Serial.println(randNumber);

  digitalWrite (randNumber, HIGH);
  }
//DISTANCIAS
 
  if (distanciaBlanco <= 10) {
    digitalWrite(randNumber, LOW);
  }
  if (distanciaRojo <= 10) {
    digitalWrite(randNumber, LOW);
  }
  if (distanciaVerde <= 10) {
    digitalWrite(randNumber, LOW);
  }
  if (distanciaAmarillo <= 10) {
    digitalWrite(randNumber, LOW);
  }   
}
