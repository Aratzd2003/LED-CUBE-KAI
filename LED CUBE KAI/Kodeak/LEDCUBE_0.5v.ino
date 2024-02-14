#include <FastLED.h>  // Libreria principal que vamos a usar para controlar las tiras de LEDs
#include <SoftwareSerial.h>  // Esta librería es especialmente útil para proyectos que requieren comunicación con múltiples dispositivos seriales, como módulos GPS, módulos Bluetooth...

SoftwareSerial Sw(0, 1);  // Pines RX, TX

#define LED_PIN1     2  // Pin que va conectado al pin DIn de la primera matriz de LEDs
#define LED_PIN2     5  // Pin que va conectado al pin DIn de la segunda matriz de LEDs
#define NUM_ROWS1    10  // Número de filas para la primera matriz de LEDs
#define NUM_ROWS2    10  // Número de filas para la segunda matriz de LEDs
#define LEDS_PER_ROW1 40  // Número de LEDs por fila para la primera matriz de LEDs
#define LEDS_PER_ROW2 10  // Número de LEDs por fila para la segunda matriz de LEDs
#define LED_COUNT1   (NUM_ROWS1 * LEDS_PER_ROW1)  // Cantidad de LEDs totales en la primera matriz
#define LED_COUNT2   (NUM_ROWS2 * LEDS_PER_ROW2)  // Cantidad de LEDs totales en la segunda matriz
#define COLOR_ORDER  GRB  // Orden de los colores

// Definir el rango específico de LEDs en cada matriz, el LED 0 es el primer LED en la tira
#define INICIO_RANGO1 0
#define FIN_RANGO1   399  // La primera matriz, que es de 400 LEDs
#define INICIO_RANGO2  0 
#define FIN_RANGO2   99  // La segunda matriz, que es de 100 LEDs

CRGB leds1[LED_COUNT1];
CRGB leds2[LED_COUNT2];  
CRGB color;
String actualColor;

  // Variables para apagado y encendido, atenuacion de los barridos
  int numPasosAtenuacion = 10; 
  int duracionTotal = 100;  

  // Variables para coloresblucle
  int totalDuration = 5000;  
  int delayBetweenColors = 200;  
  int currentColorIndex = 0;  
  int nextColorIndex = 1;  

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN1, GRB>(leds1, LED_COUNT1);  // Declaramos la primera tira de LEDs
  FastLED.addLeds<WS2812B, LED_PIN2, GRB>(leds2, LED_COUNT2);  // Declaramos la segunda tira de LEDs
  Serial.begin(9600);  // Ponemos el seria en velocidad 9600
  Sw.begin(9600);  // Ponemos el sw en velocidad 9600
  color = CRGB::Black;  // Empezamos poniendo el color de los LEDs en negro
}

void loop() {
  FastLED.show();  // Nos hace falta un "FastLED.show();" para mostrar en la tira del LEDs el color que les hemos dado
  if (Sw.available() > 0) {  //Si recibimos algo por el Bluetooth...
    char c = Sw.read();  // El valor de la variable "c" es igual a el valor que recibimos por Bluetooth...
    Serial.print("Received character: ");  // Escribimos esto en el monitor serial...
    Serial.println(c);  // Escribimos el valor de "c" en el monitor serial...
    executeBluetoothCommand(c);  // Y ejecutamos "executeBluetoothCommand" (esta mas abajo en el codigo).
  }
}
void coloresblucle() {  //Aqui lo que hacemos es un bucle de colores, entre color y color hay un transicion en la que el color actual se apaga poco a poco y una vez apagado se enciende poco a poco del siguiente color
  // Colores que aparecen en el bucle
  CRGB Colors[] = {CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::Green, CRGB::Blue, CRGB::Purple};

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
      delayMicroseconds(30);
      delay(transitionDuration / numSteps);
    }

    // Encender gradualmente
    for (int brightness = 0; brightness <= 255; brightness++) {
      // Establecer el color deseado
      CRGB color = Colors[currentColorIndex];
      
      // Establecer el brillo gradualmente
      for (int i = 0; i < LED_COUNT1; i++) {
        leds1[i] = color;
        FastLED.setBrightness(brightness);
      }
      
      FastLED.show();
      delay(transitionDuration / numSteps);
    }

    // Actualizar índices de colores para la siguiente transición
    currentColorIndex = nextColorIndex;
    nextColorIndex = (nextColorIndex + 1) % (sizeof(lavaColors) / sizeof(Colors[0]));

    // Verificar si se ha recibido una "H" por Bluetooth, si lo hace se sale del bucle de colores
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

  void drawCreeperHead() {  // Matriz 10x10 para representar la cara de un Creeper

  int creeperHead[10][40] = {  // Los "1" son los leds que encendera del color elegido
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
    case 'B':  //Poner los LEDs de color Azul
      color = CRGB::Blue;
      actualColor = "Blue";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'R':  //Poner los LEDs de color Rojo
      color = CRGB::Red;
      actualColor = "Red";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'N':  //Poner los LEDs de color Naranja
      color = CRGB(255, 102, 0); // Naranja
      actualColor = "Orange";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'Y':  //Poner los LEDs de color Amarillo
      color = CRGB::Yellow;
      actualColor = "Yellow";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'G':  //Poner los LEDs de color Verde
      color = CRGB::Green;
      actualColor = "Green";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'P':  //Poner los LEDs de color Rosa
      color = CRGB(255, 192, 203); // Rosa
      actualColor = "Pink";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'M':  //Poner los LEDs de color Morado
      color = CRGB::Purple;
      actualColor = "Purple";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
      break;
    case 'Z':  //Poner los LEDs de color Blanco
      color = CRGB(255, 255, 255); // Blanco
      actualColor = "White";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
  FastLED.show();
  
      break;
    case 'K': // APAGAR LEDs
      // Negro (apagar todos los LEDs)
      color = CRGB::Black; // Negro
      actualColor = "Black";
      fill_solid(leds1, LED_COUNT1, color);
      fill_solid(leds2, LED_COUNT2, color);
      FastLED.show();
      break;

    case 'U':  // Hace barridos por la tira de LEDs invididualmente por cada LED
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
  }
  break;

    case 'z':  // Hace un barrido horizontal por la primera matriz de color Blanco
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
    case 'b':  // Hace un barrido horizontal por la primera matriz de color Azul
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
      case 'r':  // Hace un barrido horizontal por la primera matriz de color Rojo
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
  
      case 'n':  // Hace un barrido horizontal por la primera matriz de color Naranja
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
      case 'y':  // Hace un barrido horizontal por la primera matriz de color Amarillo
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
      case 'g':  // Hace un barrido horizontal por la primera matriz de color Verde
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
      case 'p':  // Hace un barrido horizontal por la primera matriz de color Rosa
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
      case 'm':  // Hace un barrido horizontal por la primera matriz de color Morado
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
      case 'Q':  // Dibujar la cabeza del Creeper en el primer bloque 10x10 de la matriz
      drawCreeperHead();
      break;
  case 'L':  // Efecto de cambio de colores gradual
  coloresblucle();
  break;
  }
}


