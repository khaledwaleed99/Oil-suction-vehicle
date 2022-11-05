#define BUTTON_FORWARD 2

#define BUTTON_RIGHT 3

#define BUTTON_DOWN 4

#define BUTTON_LEFT 5

#define Skimmer 6

#define Stop 7

#define BUTTON_K 8

#define PIN_ANALOG_X 0

#define PIN_ANALOG_Y 1




#define DELAY 200

char data;

void setup() {

 Serial.begin(9600);



 // to enable pull up resistors first write pin mode

 // and then make that pin HIGH

 pinMode(BUTTON_FORWARD, INPUT);

 digitalWrite(BUTTON_FORWARD, HIGH);



 pinMode(BUTTON_RIGHT, INPUT);

 digitalWrite(BUTTON_RIGHT, HIGH);



 pinMode(BUTTON_DOWN, INPUT);

 digitalWrite(BUTTON_DOWN, HIGH);



 pinMode(BUTTON_LEFT, INPUT);

 digitalWrite(BUTTON_LEFT, HIGH);



 pinMode(Skimmer, INPUT);

 digitalWrite(Skimmer, HIGH);



 pinMode(Stop, INPUT);

 digitalWrite(Stop, HIGH);


  pinMode(BUTTON_K, INPUT);

 digitalWrite(BUTTON_K, HIGH);

}



void loop() {

 if(digitalRead(BUTTON_FORWARD) == LOW) {

    data = 'F';
    Serial.write(data);
   
   delay(DELAY);

 }

 else if(digitalRead(BUTTON_RIGHT) == LOW) {

    data = 'R';
    Serial.write(data);

   delay(DELAY);

 }

 else if(digitalRead(BUTTON_DOWN) == LOW) {

    data = 'D';
    Serial.write(data);
   delay(DELAY);

 }

 else if(digitalRead(BUTTON_LEFT) == LOW) {

    data = 'L';
    Serial.write(data);
   delay(DELAY);

 }

 else if(digitalRead(Skimmer) == LOW) {

   data = 'S';
    Serial.write(data);

   delay(DELAY);

 }

 else if(digitalRead(Stop) == LOW) {

    data = 'X';
    Serial.write(data);



 }

 
}
