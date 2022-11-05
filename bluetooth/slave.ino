#define Pump1 3
#define Pump2 4
#define Pump3 5
#define Skimmer 13
char state;



//SoftwareSerial mySerial(A1, A0); // RX, TX


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(Pump1 , OUTPUT);
  pinMode(Pump2 , OUTPUT);
  pinMode(Pump3 , OUTPUT);
  pinMode(Skimmer , OUTPUT);
  digitalWrite(Pump1,HIGH);
  digitalWrite(Pump2,HIGH);
  digitalWrite(Pump3,HIGH);
  digitalWrite(Skimmer,HIGH);
}

void Forward() {
  digitalWrite(Pump1, LOW);
  digitalWrite(Pump2, LOW);
  digitalWrite(Pump3, LOW);
  Serial.print("forward\n");
  Serial.print(state);
}

void Right() {
  digitalWrite(Pump1, HIGH);
  digitalWrite(Pump2, LOW);
  Serial.print("right");
}

void Left() {
  digitalWrite(Pump1, LOW);
  digitalWrite(Pump2, HIGH);
  Serial.print("left");
}

void Stop() {
  digitalWrite(Pump1, HIGH);
  digitalWrite(Pump2, HIGH);
  digitalWrite(Pump3, HIGH);  
  digitalWrite(Skimmer, HIGH);
  Serial.print("stop");
}

void Skim() {
  digitalWrite(Skimmer, LOW);
  Serial.print("skimmer");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    state = Serial.read();
    switch(state){
      case 'F':
        Forward();
        break;
      case 'R':
        Right();
        break;
      case 'L':
        Left();
        break;
      case 'X':
        Stop();
        break;
      case 'S':
        Skim();
        break;
      
    }
  }
}
