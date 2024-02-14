// Letras usadas: B, R, N, Y, G, P, M, Z, K

#include <FastLED.h>
#include <SoftwareSerial.h>

SoftwareSerial Sw(0, 1);  // RX, TX

#define LED_PIN      2  
#define NUM_ROWS     10
#define LEDS_PER_ROW 40
#define LED_COUNT    (NUM_ROWS * LEDS_PER_ROW)
#define COLOR_ORDER  GRB

CRGB leds[LED_COUNT];
CRGB color;
String actualColor;

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  Serial.begin(9600);
  Sw.begin(9600);
  color = CRGB::Black;
}

void loop() {
  if (Sw.available() > 0) {
    char c = Sw.read();
    Sw.print(c);
    executeBluetoothCommand(c);
  }
}

  void drawCreeperHead() {
  // Matriz 10x10 para representar la cabeza del Creeper
  int creeperHead[10][40] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

  // Aplicar los colores correspondientes en la matriz de LEDs
  for (int row = 0; row < 10; row++) {
    for (int col = 0; col < 40; col++) {
      int index = row * LEDS_PER_ROW + col;
      if (creeperHead[row][col] == 1) {
        // Colorear todos los píxeles en verde
        leds[index] = CRGB::Green;
      }
    }
  }

  // Mostrar la cabeza del Creeper en las primeras 10 columnas de la matriz de LEDs
  FastLED.show();
}

void executeBluetoothCommand(char command) {
  

  switch (command) {
    case 'B':
      // Azul
      color = CRGB::Blue;
      actualColor = "Blue";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'R':
      // Rojo
      color = CRGB::Red;
      actualColor = "Red";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'N':
      // Naranja
      color = CRGB(255, 102, 0); // Naranja
      actualColor = "Orange";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'Y':
      // Amarillo
      color = CRGB::Yellow;
      actualColor = "Yellow";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'G':
      // Verde
      color = CRGB::Green;
      actualColor = "Green";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'P':
      // Rosa
      color = CRGB(255, 192, 203); // Rosa
      actualColor = "Pink";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'M':
      // Morado
      color = CRGB::Purple;
      actualColor = "Purple";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'Z':
      // Blanco
      color = CRGB(255, 255, 255); // Blanco
      actualColor = "White";
      fill_solid(leds, LED_COUNT, color);
  FastLED.show();
      break;
    case 'K': // APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR 
      // Negro (apagar todos los LEDs)
      color = CRGB::Black; // Negro
      actualColor = "Black";
      fill_solid(leds, LED_COUNT, CRGB::Black);
      FastLED.show();
      return; // No es necesario mostrar nuevamente si todos están apagados

    // BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS

    case 'z':
      // Barrido simultáneo desde el primer LED- de cada fila en color blanco
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB(255, 255, 255); // Blanco
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
      FastLED.show();
      break;
    case 'b':
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
      FastLED.show();
      break;
      case 'r':
      // Barrido simultáneo desde el primer LED- de cada fila en color rojo
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB::Red;
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
      FastLED.show();
      break;
      case 'n':
      // Barrido simultáneo desde el primer LED- de cada fila en color naranja
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB(255, 102, 0); // Naranja
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
      FastLED.show();
      break;
      case 'y':
      // Barrido simultáneo desde el primer LED- de cada fila en color amarillo
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB::Yellow;
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
      FastLED.show();
      break;
      case 'g':
      // Barrido simultáneo desde el primer LED- de cada fila en color verde
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB::Green;
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
      FastLED.show();
      break;
      case 'p':
      // Barrido simultáneo desde el primer LED- de cada fila en color rosa
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB(255, 192, 203); // Rosa
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
      FastLED.show();
      break;
      case 'm':
      // Barrido simultáneo desde el primer LED- de cada fila en color morado
      for (int i = 0; i < LEDS_PER_ROW; i++) {
        for (int row = 0; row < NUM_ROWS; row++) {
          // Calcular el índice global del LED
          int index = row * LEDS_PER_ROW + i;
          
          // Cambiar el color del LED actual a Azul
          leds[index] = CRGB::Purple;
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
      FastLED.show();
      break;
      case 'Q':
      // Dibujar la cabeza del Creeper en el primer bloque 10x10 de la matriz
      drawCreeperHead();
      break;
  }
}


