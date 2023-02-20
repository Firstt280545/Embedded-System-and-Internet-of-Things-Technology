int rotary = 4;             // สร้างตัวแปรชื่อ rotary สำหรับจ่ายไฟไปยัง potentiometer เป็น GPIO 04

const byte sig = A0;      // สร้างตัวแปรชื่อ sig สำหรับกำหนดขาที่รับสัญญาณจาก SIG เป็นขา Analog 0
int value = 0;            // สร้างตัวแปรชื่อ value เก็บค่าที่ได้จาก sig โดยจะรับมาเป็นตัวเลข
float voltageValue = 0;   // สร้างตัวแปรชื่อ voltageValue เก็บค่ากำลังไฟฟ้าที่ได้จาก SIG เป็นตัวเลขแบบมีจุดทศนิยม มีหน่วยเป็นโวลต์

void setup() {
  Serial.begin(115200);
  analogReadResolution(10);     // กำหนดระดับค่าที่อ่านได้จากขา A0
  pinMode(rotary, OUTPUT);      // กำหนดขา GPIO 04 ให้เป็นขาสัญญาณขาออก

}

void loop() {
  digitalWrite(rotary, HIGH);               // เขียนค่า 1 ส่งออกจาก GPIO 04
  value = analogRead(sig);                  // กำหนดค่าในตัวแปร value เป็นค่าจากการอ่านค่า analog จากขา SIG
  voltageValue =  value * (3.3 / 1024);     // กำหนดค่ากำลังไฟฟ้าโดยคำนวณจาก 3.3/1024
  
  // โค้ดด้านล่างนี้เป็นการแสดงค่าจากเซ็นเซอร์และค่ากำลังไฟที่คำนวณได้
  
  Serial.print("sensor value = ");
  Serial.print(value);
  Serial.print(" voltage value = ");
  Serial.println(voltageValue);
  
  
  if (voltageValue > 2.00){                 // สร้างเงื่อนไข หากกำลังไฟฟ้ามากกว่า 2.00โวลต์
    Serial.println("LED is on");            // ให้ทำการแสดงข้อความผ่าน serial monitor ว่า "lED is on"
  }
  else{
    Serial.println("LED is off");           // หาก if เป็นเท็จ ให้ทำการแสดงข้อความผ่าน serial monitor ว่า "lED is off"
  }
  delay(500);        // กำหนดดีเลย์หน่วงเวลาไว้ 0.5 วินาที

}
