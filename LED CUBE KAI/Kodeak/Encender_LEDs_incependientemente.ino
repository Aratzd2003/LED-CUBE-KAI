#include <FastLED.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(4, 5);  // RX, TX

#define LED_PIN    2  
#define LED_COUNT  150 
#define COLOR_ORDER GRB

// Definir el rango específico de LEDs
#define INICIO_RANGO 10
#define FIN_RANGO 50
#define LED_ESPECIAL 0

CRGB leds[LED_COUNT];

void setup() {

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);

  // Inicializar la comunicación serial para el módulo Bluetooth
  bluetoothSerial.begin(9600);
}

void loop() {

  // Encender el rango específico de LEDs en blanco
  fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::White);
  // Encender el LED especial en rojo
  leds[LED_ESPECIAL] = CRGB::Red;
  // Enviar los datos a la tira de LEDs
  FastLED.show();
  // Esperar un segundo
  delay(1000);

  // Apagar el rango específico de LEDs y el LED especial
  fill_solid(leds + INICIO_RANGO, FIN_RANGO - INICIO_RANGO + 1, CRGB::Black);
  leds[LED_ESPECIAL] = CRGB::Black;
  // Enviar los datos a la tira de LEDs
  FastLED.show();
  // Esperar un segundo
  delay(1000);

  // Leer comandos Bluetooth
  while (bluetoothSerial.available() > 0) {
    char command = bluetoothSerial.read();
    executeBluetoothCommand(command);
  }
}

// Función para ejecutar comandos Bluetooth
void executeBluetoothCommand(char command) {
  // Puedes definir tus propios comandos y acciones aquí
  switch (command) {
    case 'A':
      // Realiza alguna acción cuando se recibe el comando 'A'
      // Por ejemplo, encender LEDs
      fill_solid(leds, LED_COUNT, CRGB(255, 255, 255));
      FastLED.show();
      break;
    case 'B':
      // Realiza alguna acción cuando se recibe el comando 'B'
      // Por ejemplo, apagar LEDs
      fill_solid(leds, LED_COUNT, CRGB(0, 0, 0));
      FastLED.show();
      break;
    // Agrega más casos según tus necesidades
  }
}