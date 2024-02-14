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
  switch (command) {
    case 'B':
      // Barrido simultáneo desde el primer LED- de cada fila en color azul
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB::Blue;
        }
        
        // Enviar los datos a la tira de LEDs
        FastLED.show();
        
        // Esperar un corto periodo de tiempo
        delay(100); // Ajusta el valor para recorrer 10 LEDs por segundo
        
        // Apagar todos los LEDs
        for (int row = 0; row < NUM_ROWS; row++) {
          int index = row * LEDS_PER_ROW + i;
          leds[index] = CRGB::Black;
        }
      }
      break;
  }
  // Enviar los datos a la tira de LEDs
  FastLED.show();
}
