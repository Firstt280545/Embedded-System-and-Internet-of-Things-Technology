#define trigPin 12 //แก้ไขที่ pin echo
#define echoPin 15
#define LED_PIN 10
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  int distance = Ultrasonic();
  Serial.println("ระยะ " + String(distance) + " cm");
  if(distance<10){
    digitalWrite(LED_PIN,HIGH);
  }
  else{
    digitalWrite(LED_PIN,LOW);
  }
  delay(1000);
}

int Ultrasonic() {
  long duration, Distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Distance = duration / 58.2;
  return Distance;
}