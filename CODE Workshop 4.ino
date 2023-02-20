#include <WiFi.h>

#define WIFI_SSID "Firstt"
#define WIFI_PASS "Firstt28"

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(500);
  Serial.println("");
  Serial.print("กำลังเชื่อมต่อไปยัง");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");    
  }

    Serial.println("");
    Serial.println("เชื่อมต่อสำเร็จ");
    Serial.print("IP Address คือ");
    Serial.println(WiFi.localIP());
}

void loop(){
  
}