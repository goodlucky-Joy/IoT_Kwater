#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup()   {                
  /** SSD1306 OLED 초기화 */
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // I2C Address : 0x3C
    Serial.println(F("OLED(SSD1306) allocation failed"));
    while(1){} // OLED 초기화에 실패했을 경우 여기서 대기.
  }

  /** OLED 폰트색, 크기 지정, 테스트 문장 출력 */
  display.clearDisplay();
  display.setTextColor(WHITE, BLACK);              // BLACK, WHITE
  display.setTextSize(1);                          // 1 to 8
  display.println("Phi board v1.0");
  display.display();

}

int count = 0;
void loop() {  
  display.clearDisplay();
  display.setCursor(0,0);                         // 128*64 Pixels
  display.println(count++);
  display.display();
  delay(1000);
}
