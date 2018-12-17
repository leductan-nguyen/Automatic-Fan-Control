/**
 * 3DRaion 2018
 */

#include <SPI.h>
#include <Wire.h>

// For OLED LCD
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// For DHT temp and humidity sensor
#include "dht.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define DHT11_PIN 2       // DHT 22  (AM2302) - what pin we're connected to
#define TEMP_THRESHOLD 28 // defines at which temperature should we trigger the fan
#define TEXT_SIZE 2       // define text size

// DHT constant
dht DHT;
// Relay pin
constexpr uint8_t relay = 3;

// Variables
int16_t humidity; //Stores humidity value
int16_t temp;     //Stores temperature value

/**
 * This function runs 1 time when the board turns on
 */
void setup()
{
  // Relay Pin Configuration
  pinMode(relay, OUTPUT);
  // Make sure the fan is off
  digitalWrite(relay, LOW);

  Serial.begin(9600);
  Serial.println("3DRaion Automatic Fan Control");

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x64)

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(3000);
}

/**
 * This function loops infinitely
 */
void loop()
{
  // Read data and store it to variables hum and temp
  int chk = DHT.read11(DHT11_PIN);
  humidity = DHT.humidity;
  temp = DHT.temperature;

  // Print temp and humidity values to display
  displayTempAndHumidity(temp, humidity);
  if (temp >= TEMP_THRESHOLD)
  {
    digitalWrite(relay, HIGH);
    displayFanOnIndicator(true);
  }
  else
  {
    digitalWrite(relay, LOW);
    // displayFanOnIndicator(false);
  }
  delay(2000);
}

/**
 * This function read inputs values (t, h) and 
 * display these values, also adding the title
 * 
 * @param t : input temperature
 * @param h : input humidity
 */
void displayTempAndHumidity(int16_t t, int16_t h)
{
  display.clearDisplay();
  display.setTextSize(TEXT_SIZE);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(" 3DRAION ");
  display.setTextSize(TEXT_SIZE);
  display.setTextColor(WHITE);
  display.setCursor(5, 20);
  display.print("T : ");
  display.print(t, DEC);
  display.print(" C");
  display.setCursor(5, 40);
  display.print("H : ");
  display.print(h, DEC);
  display.print(" %");
  display.display();
}

/**
 * Display a line at the end of the screen to indicate the fan is ON
 */
void displayFanOnIndicator(bool on)
{
  if (on)
  {
    display.drawLine(0, 63, 128, 63, WHITE);
    display.display();
  }
  else
  {
    display.drawLine(0, 63, 128, 63, BLACK);
    display.display();
  }
}