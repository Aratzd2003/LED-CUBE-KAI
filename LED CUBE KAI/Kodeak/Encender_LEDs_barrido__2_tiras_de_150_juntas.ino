#include <FastLED.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(4, 5);  // RX, TX

#define LED_PIN    2  
#define LED_COUNT  300 
#define COLOR_ORDER GRB

// Definir el rango específico de LEDs
#define INICIO_RANGO 0
#define FIN_RANGO 299

CRGB leds[LED_COUNT];

/*WiFiClient espClient;
PubSubClient client(espClient);

ESP8266WebServer server(80);*/

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);

  // Inicializar la comunicación serial para el módulo Bluetooth
  bluetoothSerial.begin(9600);
}

void loop() {
  // Barrido hacia la derecha en el rango específico
  for (int i = INICIO_RANGO; i <= FIN_RANGO; i++) {
    // Encender el LED actual en blanco
    leds[i] = CRGB::White;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un breve periodo de tiempo para visualizar el barrido
    delayMicroseconds(60);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }

  // Barrido hacia la izquierda en el rango específico
  for (int i = FIN_RANGO; i >= INICIO_RANGO; i--) {
    // Encender el LED actual en blanco
    leds[i] = CRGB::White;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un breve periodo de tiempo para visualizar el barrido
    delayMicroseconds(60);
    // Apagar el LED actual
    leds[i] = CRGB::Black;
  }
}

