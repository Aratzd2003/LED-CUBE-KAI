#include <FastLED.h>
#include <SoftwareSerial.h>

SoftwareSerial Sw(0, 1);  // RX, TX

#define LED_PIN      2  
#define NUM_ROWS     10
#define LEDS_PER_ROW 40
#define LED_COUNT    (NUM_ROWS * LEDS_PER_ROW)
#define COLOR_ORDER  GRB

CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  Sw.begin(9600);
}

void loop() {
  if (Sw.available() > 0) {
    char c = Sw.read();
    Sw.print(c);
    executeBluetoothCommand(c);
  }
}

void executeBluetoothCommand(char command) {
  CRGB color;

  switch (command) {
    case 'B':
      // Azul
      color = CRGB::Blue;
      break;
    case 'R':
      // Rojo
      color = CRGB::Red;
      break;
    case 'N':
      // Naranja
      color = CRGB(255, 102, 0); // Naranja
      break;
    case 'Y':
      // Amarillo
      color = CRGB::Yellow;
      break;
    case 'G':
      // Verde
      color = CRGB::Green;
      break;
    case 'P':
      // Rosa
      color = CRGB(255, 192, 203); // Rosa
      break;
    case 'M':
      // Morado
      color = CRGB::Purple;
      break;
    case 'Z':
      // Blanco
      color = CRGB(255, 255, 255); // Blanco
      break;
    case 'K':
      // Negro (apagar todos los LEDs)
      fill_solid(leds, LED_COUNT, CRGB::Black);
      FastLED.show();
      return; // No es necesario mostrar nuevamente si todos están apagados
    default:
      return; // Comando no reconocido
  }

  // Encender todos los LEDs del color correspondiente
  fill_solid(leds, LED_COUNT, color);
  FastLED.show();
}

