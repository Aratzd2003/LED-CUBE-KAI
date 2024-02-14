#include <FastLED.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1);  // RX, TX

#define LED_PIN    2  
#define LED_COUNT  300 
#define COLOR_ORDER GRB

// Definir el rango específico de LEDs
#define INICIO_RANGO 1
#define FIN_RANGO 299
#define LED_ESPECIAL 0

char val;

CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);

  // Inicializar la comunicación serial para el módulo Bluetooth
  BT.begin(9600);

  Serial.begin(9600);
}

void loop() {
  if (BT.available()) {
    val = BT.read();
    executeBluetoothCommand(val);
  }

  if (BT.available()) {
    Serial.write(BT.read());
  }

  if (Serial.available()) {
    BT.write(Serial.read());
  }

  // Otro código de manejo de LEDs puede ir aquí si es necesario
}

// Función para ejecutar comandos Bluetooth
void executeBluetoothCommand(char command) {
  // Puedes definir tus propios comandos y acciones aquí
  switch (command) {
    case 'A':
      // Encender LEDs de color Azul
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Blue);
      FastLED.show();
      break;
    case 'R':
      // Encender LEDs de color Rojo
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Red);
      FastLED.show();
      break;
    case 'G':
      // Encender LEDs de color Verde
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Green);
      FastLED.show();
      break;
    case 'M':
      // Encender LEDs de color Morado
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Purple);
      FastLED.show();
      break;
    case 'P':
      // Cambiar el color a un color personalizado y realizar barrido
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB(255, 192, 203));
      FastLED.show();
      break;
    case 'N':
      // Encender LEDs de color Naranja
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Orange);
      FastLED.show();
      break;
    case 'Y':
      // Encender LEDs de color Amarillo
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Yellow);
      FastLED.show();
      break;
    // Agrega más casos según tus necesidades
    // ...
    case 'Z':
      // Apagar LEDs si se recibe un comando no reconocido
      fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB(0, 0, 0));
      FastLED.show();
      break;
  }
}
