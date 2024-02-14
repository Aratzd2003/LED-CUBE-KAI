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

  if (Serial.available()) {
    BT.write(Serial.read());
  }
}

// Función para ejecutar comandos Bluetooth
void executeBluetoothCommand(char command) {
  // Puedes definir tus propios comandos y acciones aquí
  switch (command) {
    case 'A':
      // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Blue;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Blue;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
    case 'R':
      // Cambiar el color a Rojo y realizar barrido
      // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Red;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Red;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
    case 'G':
      // Cambiar el color a Verde y realizar barrido
      // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Green;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Green;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
    case 'M':
      // Cambiar el color a Morado y realizar barrido
      // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Purple;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Purple;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
    case 'P':
      // Cambiar el color a un color personalizado y realizar barrido
      // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB(255, 192, 203); //Rosa
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB(255, 192, 203); //Rosa
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
    case 'N':
      // Cambiar el color a Naranja y realizar barrido
            // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB(255, 102, 0); //Naranja
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB(255, 102, 0); //Naranja
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
    case 'Y':
      // Cambiar el color a Amarillo y realizar barrido
            // Realizar el barrido de ida y vuelta
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Yellow;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Cambiar el color del LED actual
    leds[i] = CRGB::Yellow;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un corto periodo de tiempo
    delay(10);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
      break;
  }
  // Enviar los datos a la tira de LEDs
  FastLED.show();
}
