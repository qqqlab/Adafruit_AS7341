/* This example will use the GPIO pin to blink an led */

#include <Adafruit_AS7341.h>

Adafruit_AS7341 as7341;


void setup() {
  Serial.begin(115200);

  // Wait for communication with the host computer serial monitor
  while (!Serial) {
    delay(1);
  }

  if (!as7341.begin()){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }
  // set the GPIO direction to input so we can read the input
  if (!as7341.setGPIODirection(AS7341_GPIO_INPUT)){
    Serial.println("Could not set the GPIO direction to true to enable");
  }
}

void loop() {
  bool gpio_value = as7341.getGPIOValue();
  Serial.print("gpio: ");Serial.println(gpio_value);
  Serial.print("gpio direction: ");Serial.println(as7341.getGPIODirection());
  Serial.print("GPIO pin is ");
  if (gpio_value){
    Serial.println("high");
  } else {
    Serial.println("Low");
  }
  delay(500);
}
