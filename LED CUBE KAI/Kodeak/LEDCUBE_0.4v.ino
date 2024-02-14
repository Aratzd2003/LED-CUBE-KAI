#include <FastLED.h>
#include <SoftwareSerial.h>

SoftwareSerial Sw(0, 1);  // RX, TX

#define LED_PIN1     2
#define LED_PIN2     5  // Agregado para la segunda tira de LEDs
#define NUM_ROWS1    10
#define NUM_ROWS2    10  // Número de filas para la segunda tira de LEDs
#define LEDS_PER_ROW1 40
#define LEDS_PER_ROW2 10  // Número de LEDs por fila para la segunda tira de LEDs
#define LED_COUNT1   (NUM_ROWS1 * LEDS_PER_ROW1)
#define LED_COUNT2   (NUM_ROWS2 * LEDS_PER_ROW2)
#define COLOR_ORDER  GRB

// Definir el rango específico de LEDs
#define INICIO_RANGO1 0
#define FIN_RANGO1   399
#define INICIO_RANGO2  0 // El rango para la segunda tira comienza después de la primera
#define FIN_RANGO2   99  // Ajusta según sea necesario

int columna1[] = {0, 40, 80, 120, 160, 200, 240, 280, 320, 360};

CRGB leds1[LED_COUNT1];
CRGB leds2[LED_COUNT2];  // Arreglo para la segunda tira de LEDs
CRGB color;
String actualColor;

  // Variables para apagado y encendido con atenuacion de los barridos
  int numPasosAtenuacion = 10; 
  int duracionTotal = 100;  

  // Variables para lavaLampEffect
  int totalDuration = 5000;  // 5 segundos
  int delayBetweenColors = 200;  // Retardo entre cambios de color
  int currentColorIndex = 0;  // Índices de colores actuales
  int nextColorIndex = 1;  //y siguientes

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN1, GRB>(leds1, LED_COUNT1);
  FastLED.addLeds<WS2812B, LED_PIN2, GRB>(leds2, LED_COUNT2);
  Serial.begin(9600);
  Sw.begin(9600);
  color = CRGB::Black;
}

void loop() {
  if (Sw.available() > 0) {
    char c = Sw.read();
    Serial.print("Received character: ");
    Serial.println(c);
    executeBluetoothCommand(c);
  }
}
void lavaLampEffect() {
  // Colores de la lámpara de lava
  CRGB lavaColors[] = {CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Blue, CRGB::Purple};

// Índices de colores actuales y siguientes
  int currentColorIndex = 0;
  int nextColorIndex = 1;

  // Tiempo de inicio del efecto
  unsigned long startTime = millis();

  // Bucle que se ejecuta indefinidamente hasta recibir una "H" por Bluetooth
  while (true) {
    // Duración total de la transición gradual entre colores
    int transitionDuration = 100;  // 2 segundos
    // Número de pasos para la transición gradual
    int numSteps = 100;

    // Apagar gradualmente
    for (int i = 255; i >= 165; i--) {
      fadeToBlackBy(leds1, LED_COUNT1, 10);  // Ajusta el valor de atenuación según sea necesario
      FastLED.show();
      delay(transitionDuration / numSteps);
    }

    // Transición gradual entre colores actuales y siguientes
    for (int step = 0; step < numSteps; step++) {
      float ratio = float(step) / float(numSteps);
      CRGB currentColor = blend(lavaColors[currentColorIndex], lavaColors[nextColorIndex], ratio);

      // Aplicar el color gradualmente a todos los LEDs
      fill_solid(leds1, LED_COUNT1, currentColor);

      // Mostrar los datos en la tira de LEDs
      FastLED.show();

      // Retardo entre pasos de la transición gradual
      delay(transitionDuration / numSteps);
    }

    // Actualizar índices de colores para la siguiente transición
    currentColorIndex = nextColorIndex;
    nextColorIndex = (nextColorIndex + 1) % (sizeof(lavaColors) / sizeof(lavaColors[0]));

    // Verificar si se ha recibido una "H" por Bluetooth
    if (Sw.available() > 0) {
      char c = Sw.read();
      if (c == 'H') {
        // Detener el efecto y apagar los LEDs
        fill_solid(leds1, LED_COUNT1, CRGB::Black);
        FastLED.show();
        break;
      }
    }
  }
}

  void drawCreeperHead() {
  // Matriz 10x10 para representar la cabeza del Creeper
  int creeperHead[10][40] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };
  fill_solid(leds2, LED_COUNT2, CRGB::Green);
  // Aplicar los colores correspondientes en la matriz de LEDs
  for (int row = 0; row < 10; row++) {
    for (int col = 0; col < 40; col++) {
      int index = row * LEDS_PER_ROW1 + col;
      if (creeperHead[row][col] == 1) {
        // Colorear todos los píxeles en verde
        leds1[index] = CRGB::Green;
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
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'R':
      // Rojo
      color = CRGB::Red;
      actualColor = "Red";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'N':
      // Naranja
      color = CRGB(255, 102, 0); // Naranja
      actualColor = "Orange";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'Y':
      // Amarillo
      color = CRGB::Yellow;
      actualColor = "Yellow";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'G':
      // Verde
      color = CRGB::Green;
      actualColor = "Green";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'P':
      // Rosa
      color = CRGB(255, 192, 203); // Rosa
      actualColor = "Pink";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'M':
      // Morado
      color = CRGB::Purple;
      actualColor = "Purple";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'Z':
/* // Encender primera columna
  leds1[0]= CRGB::White;
  leds1[40]= CRGB::White;
  leds1[80]= CRGB::White;
  leds1[120]= CRGB::White;
  leds1[160]= CRGB::White;
  leds1[200]= CRGB::White;
  leds1[240]= CRGB::White;
  leds1[280]= CRGB::White;
  leds1[320]= CRGB::White;
  leds1[360]= CRGB::White;

 FastLED.show();
*/    
    
  for (int i = 0; i < sizeof(columna1); i++) {
    // Encender el LED actual en blanco
    leds1[columna1[i]] = CRGB::White;
    }

      // Blanco
      color = CRGB(255, 255, 255); // Blanco
      actualColor = "White";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
  
      break;
    case 'K': // APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR APAGAR 
      // Negro (apagar todos los LEDs)
      color = CRGB::Black; // Negro
      actualColor = "Black";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
      FastLED.show();
      break;

    // BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS BARRIDOS

    case 'U':
    // Barrido hacia la derecha en el rango específico
  for (int i = INICIO_RANGO1; i <= FIN_RANGO1; i++) {
    // Encender el LED actual en blanco
    leds1[i] = CRGB::White;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un breve periodo de tiempo para visualizar el barrido
    delayMicroseconds(60);
    // Apagar el LED actual
    //leds[i] = CRGB::Black;
  }
  fill_solid(leds2, LED_COUNT2, CRGB::White);
  FastLED.show();
  delay(500);
  fill_solid(leds2, LED_COUNT2, CRGB::Black);
  FastLED.show();
  // Barrido hacia la izquierda en el rango específico
  for (int i = FIN_RANGO1; i >= INICIO_RANGO1; i--) {
    // Encender el LED actual en blanco
    leds1[i] = CRGB::Black;
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    // Esperar un breve periodo de tiempo para visualizar el barrido
    delayMicroseconds(60);
    // Apagar el LED actual
    //leds[i] = CRGB::Black;
  }
  break;

    case 'z':
    fill_solid(leds2, LED_COUNT2, color);
// Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::White;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
    case 'b':
    fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Blue;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
      case 'r':
      fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Red;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
  
      case 'n':CRGB(255, 102, 0); // Naranja
      fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB(255, 102, 0); // Naranja
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
      case 'y':
      fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Yellow;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
      case 'g':
      fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Green;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
      case 'p':
      fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB(255, 192, 203); // Rosa
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
      case 'm':
      fill_solid(leds2, LED_COUNT2, color);
      // Barrido simultáneo desde el primer LED de cada fila en color especificado
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Purple;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
    }
  for (int i = 0; i < LEDS_PER_ROW1; i++) {
    for (int row = 0; row < NUM_ROWS1; row++) {
      // Calcular el índice global del LED
      int index = row * LEDS_PER_ROW1 + i;
      
      // Encender el LED actual con el color especificado
      leds1[index] = CRGB::Black;
    }
    
    // Enviar los datos a la tira de LEDs
    FastLED.show();
    delay(duracionTotal / numPasosAtenuacion);
  }
  break;
      case 'Q':
      // Dibujar la cabeza del Creeper en el primer bloque 10x10 de la matriz
      drawCreeperHead();
      break;
  case 'L':
  // Efecto de lámpara de lava con todos los colores
  lavaLampEffect();
  break;
  }
}


