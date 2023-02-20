int GREEN = 2; 		//ประกาศตัวแปร led กำหนดขาที่ 2 ของบอร์ด (GPIO02)
int YELLOW = 15;		//ประกาศตัวแปร led กำหนดขาที่ 15 ของบอร์ด (GPIO15)
int RED = 35;			//ประกาศตัวแปร led กำหนดขาที่ 35 ของบอร์ด (GPIO35)
int DELAY_GREEN = 3000;
int DELAY_YELLOW = 1500;
int DELAY_RED = 3000;

void setup()
{
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop()
{
  green_light();
  delay(DELAY_GREEN);
  yellow_light();
  delay(DELAY_YELLOW);
  red_light();
  delay(DELAY_RED);
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}

