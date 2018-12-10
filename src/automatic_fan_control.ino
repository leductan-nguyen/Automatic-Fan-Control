#include <SPI.h>
#include <Wire.h>

// For OLED LCD
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// For DHT temp and humidity sensor
#include <dht.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define DHT11_PIN 2     // DHT 22  (AM2302) - what pin we're connected to

// DHT constant
dht DHT;
// Relay pin
constexpr uint8_t relay = 3;

/* Buzzer est un programme qui joue la gamme musicale */
#define buzzer 4    // affectation des broches
int frequence[] = {262, 294, 330, 349, 370, 392, 440, 494};      // tableau de fréquence des notes

//Variables
int16_t humidity;  //Stores humidity value
int16_t temp; //Stores temperature value

// times to count for relay to be switched
#define MAXCOUNT 5;
uint8_t count = MAXCOUNT;

void setup()   {
  // Relay Pin Configuration
  pinMode(relay, OUTPUT);
  // Make sure the fan is off
  digitalWrite(relay, LOW);
  
  //Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(500);
}

void loop() {
  // Read data and store it to variables hum and temp
  int chk = DHT.read11(DHT11_PIN);
  humidity = DHT.humidity;
  temp = DHT.temperature;

  // Print temp and humidity values to display
  displayTempAndHumidity(temp, humidity);
  if (temp >= 28) {
    digitalWrite(relay, HIGH);
    tone(buzzer, 370, 1000);
  } else {
    digitalWrite(relay, LOW);
  }
  tone(buzzer, 500, 500);
  delay(2000);
}

void displayTempAndHumidity(int16_t t, int16_t h) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.println(" 3DRAION ");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(5,20);
  display.print("T : ");
  display.print(t, DEC);
  display.print(" C");
  display.setCursor(5,40);
  display.print("H : ");
  display.print(h, DEC);
  display.print(" %");
  display.display();
}

void switchRelay(uint8_t value) {
  if (value == HIGH && count == 0) {
    digitalWrite(relay, LOW);
    count = MAXCOUNT;
  } else if (value == LOW && count == 0) {
    digitalWrite(relay, HIGH);
    count = MAXCOUNT;
  }
  count--;
}

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }    
  display.display();
  delay(1);
}

void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("scroll");
  display.display();
  delay(1);
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
