# LED-CUBE-KAI

PROIEKTUAREN DESKRIBAPENA

"LED-CUBE KAI" proiektua LEDen hiru dimentsioko kuboa da, sormena, ingeniaritza eta programazioa konbinatzen dituena, ikusizko erakustaldi liluragarri bat sortzeko. Kubo formako egurrezko oinarri baten gainean eraikia, gailuak estrategikoki jarritako LED zerrendak erabiltzen ditu argien bi matrize osatzeko. Kuboaren alboetan 40 LEDeko hamar zerrenda horizontaletan eta goiko aldean 10 LEDeko hamar zerrendatan antolatuta, kuboak patroiak eta argi-efektuak sortzeko aukera zabala eskaintzen du.

5V-ko eta 30Ako bi elikadura-iturrik hornidura elektriko sendoa bermatzen dute, energia modu eraginkorrean banatuz LED matrizeen, Teensy mikrokontrolagailuaren eta Bluetooth moduluaren artean. Gainera, ikuspena hobetzeko eta LED bakoitza argi eta garbi bereizteko, argia bereizteko gelaxkak eta akriliko opakuzko estaldura gehitu dira. Estaldura horri esker, argia dardarka sortzen da, kuboaren barne-egitura agerian utzi gabe, eta ikusizko efektu liluragarria sortzen da.

Kuboaren beheko aldean, barnean, zirkuitu inprimatuko plaka batek (PCB) Teensy, Bluetooth modulua eta konexio elektrikoak gordetzen ditu, proiektuaren elektronika zentralerako plataforma antolatu eta trinkoa eskainiz. Gordailu honetan zehaztutako dokumentazioak "LED-CUBE KAI" ren erreplikazioa errazten du, zale sutsu eta zaleei beren hiru dimentsioko LED kuboaren sorreran murgiltzeko aukera emanez.

JATORRIZKO IDEIA: Inspirazioa eta Egokitzapena

"LED-CUBE KAI" proiektua Moekoeren lan miresgarrian eta "500 LED-Pixel RGB-Brick" proiektuan oinarritzen da. Bere ideia berritzaileen inspirazioa hartu dugu, diseinua eta ikuspegia gure LED kuboa sortzeko.

https://www.instructables.com/500-LED-Pixel-RGB-Brick/


![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/156079021/2b86d054-cdec-4552-8639-533a5f465c9f)


Jatorrizko proiektuaren inspirazioa:

Kuboaren diseinua:
Kuboaren hiru dimentsioko egitura hartu genuen, hainbat geruzatan banatutako LEDen zerrendekin, jatorrizko proiektuan agertzen zen bezala. Alboetan 40 LEDeko 10 zerrenda horizontal eta goiko aldean 10 LEDeko 10 zerrenda jartzea funtsezko ezaugarria izan zen.

LEDen banaketa:
LEDen banaketa eta bereizketa espezifikoari jarraitzen diogu, jatorrizko proiektuan emandako jarraibideen arabera. Erabaki horrek argi uniformea eta itxura bisualki erakargarria bermatu zituen.

Oinarriaren egitura eta PCB: Kuboaren egiturarako egurrezko oinarri bat erabiltzeko aukeran oinarritzen gara.

Egokitzapena eta hobekuntzak:

Dimentsio pertsonalizatuak:
Jatorrizko sortzaileak emandako neurrietan oinarritzen bagara ere, kuboaren dimentsioetan doikuntzak egin ditugu gure lehentasun estetikoetara eta eskuragarri ditugun materialetara egokitzeko; adibidez, ertzen dimentsioetan doikuntzak egin behar izan genituen.


![20240111_124037](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/156079021/2911d6ae-e0c4-486e-bb4a-7161eaff6cef)



Elementu berriak sartzea:
Ezaugarri berriak gehitu ditugu, hala nola kuboaren barruko osagaien banaketa edo kuboaren egurrezko oinarria, orain kuboaren plakan marraztutako gure logoa ikusten uzten diguna.



Inspirazio-iturria ezagutzean eta jatorrizko sortzaileari eskerrak ematean, haren lana aitortzeaz gain, LEDen eta proiektu elektronikoen zale sutsuen komunitatearen barruan ezagutzak trukatzen laguntzea ere bilatzen dugu. Jatorrizko proiektuaren ikuspegi, egokitzapen eta hedapen berri hori "LED-CUBE KAI" delakoan islatzen da, eta orain beste sortzaile eta zale batzuk inspiratzea espero da, LEDen kuboak eraikitzeko esperientzia pertsonalizatuan murgiltzeko.


ARAZOAK ETA KONPONBIDEAK PROIEKTUAN


Arazoa 1: Konexioak eta zirkuitulaburrak

Descripción: Antes de conectar los LEDs a la fuente de alimentación, es crucial verificar minuciosamente todas las conexiones y cables. La confusión en las conexiones puede resultar en cortocircuitos, dañando tanto los LEDs como la fuente de alimentación.

Solución: Realizar una revisión exhaustiva de las conexiones antes de aplicar la alimentación. Asegurarse de que cada conexión sea precisa y que no haya posibilidad de cortocircuitos.



Problema 2: Desajuste en Ángulos de las Piezas del Cubo

Descripción: Los ángulos de las aristas y esquinas no cuadraban inicialmente. Se solucionó creando primero las piezas de los lados y luego calculando los ángulos de las aristas para garantizar un ajuste preciso al ensamblar el cubo.

Solución: Al construir el cubo, inicia con las piezas de los lados y calcula los ángulos de las aristas para lograr una unión perfecta y evitar desajustes en las esquinas.



Problema 3: Tira de LED No Funciona

Descripción: Alguna tira de LED no se encendía inicialmente, lo que se atribuyó a un posible problema de conexión. La solución fue retirar las tiras de LED y verificar su funcionamiento utilizando un código básico fuera del circuito para asegurarse de que estuvieran adecuadamente alimentadas.

Solución: Si una tira de LED no se ilumina, retírala y verifica su funcionamiento fuera del circuito. Asegúrate de que esté recibiendo la alimentación adecuada y corrige cualquier problema de conexión.



Problema 4: Problemas en el Diseño de la PCB

Descripción: Se han experimentado varios problemas al diseñar las placas debido a la falta de planificación en la distribución de elementos y conexiones.

Solución: Antes de fabricar las placas, planifica cuidadosamente la distribución de elementos y conexiones. Asegúrate de tener un diseño claro y revisa todas las conexiones antes de la fabricación.



Problema 5: Dificultad para Entender el Código con la Librería #fastled

Descripción: Se ha encontrado dificultad en comprender el código al utilizar la librería #fastled. Después de buscar ayuda en internet y realizar varios intentos, se lograron diferentes efectos con los LEDs.

Solución: Para comprender el código con la librería #fastled, busca ayuda en recursos en línea y realiza pruebas. En la carpeta de códigos, se han dejado pruebas y experimentos previos antes de la creación del código definitivo para referencia.



MUNTATZEKO JARRAITU BEHARREKO PAUSOAK

Ezer baino lehen, proiektua egiteko materialak beharko ditugu. "Materialen zerrenda" izeneko karpetan erantsi dizkizuegu. Material batzuen zehaztapen zehatzak, berriz, argazkiak emango dizkizuegu montagean (adibidez, ertzak).

En primer lugar vamos a construir la caja de madera y la rejilla de los LEDs. La caja de madera esta compuesta por 5 piezas de madera (aparte de la base, que es la pieza mas grande)

Piezas de los lados:
x2 piezas de 25,2cm x 29,6cm x 1,0cm (la piezas "pequeñas")

x2 piezas de 29,6cm x 27,2cm x 1,0cm (la piezas "grandes")

x1 pieza de 27,2cm x 27,2cm x 1,0cm (la pieza de "arriba")

x1 pieza de 34,0cm x 34,0cm x 1,5cm (la pieza de la "base")
![20240117_131805](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/975da80e-79b9-4ddc-a92e-8cd2279c1975)
![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/278afd6b-e386-463a-a739-4b93bc5f915a)

![20240111_123909](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/76f7f9c3-6173-40e8-aa7a-d72733c7ff0c)

![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/0f9e9cf6-db2f-4f61-a3ed-9f5c8aa19648)
![IMG20240206104117](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/23152192-f9eb-48a9-ba30-83726dce2e07)


Las dimensiones del cubo (las exteriores, no las del cubo interior) están especificadas por la distancia del los píxeles en la tira de LEDs (10 pixeles de ancho en cada cara. En este caso los píxeles tienen una distancia de 3,4cm, por lo que el cubo tiene que medir 34 x 34 x 34cm. Ahorrarás mucho tiempo usando estas dimensiones, porque no necesitarás cortar la tira después de cada píxel y volver a unirla con un pequeño cable.

Tienes que trabajar correctamente porque la caja de acrílico encaja perfectamente en la parte superior de la caja de madera. Se vuelve mucho más fácil con algunos voluntarios a tu alrededor, o simplemente usa un tensor de marco como hicimos nosotros. Con pegamento de madera pegaremos las "ARISTAS" que hacen "LAS ESQUINAS del cubo", es bastante complicado conseguir 45 grados en el angulo de las puntas de las aristas que cmponen las celdas, asique hay que estar atento y diseñar y hacer bien cada pieza.

Para hacer las aristas necesitaremos las piezas con las medidas adecuadas, en nuestro caso no hemos utilizado las mismas medidas que la del proyecto que hemos utilizado como referencia, asique dejamos un archivo adjunto con las piezas que hemos utilizado para la cortar con la cortadora laser (XTOOL D1 PRO) y las medidas de las piezas son estas de acontinuación:![IMG20240206100735](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/b32921a3-e380-4c07-98eb-e1f8b6972bab)


Cuando toda la cola esta seca (la de las aristas del borde del cubo) y se hayan montado aparte de eso las aristas de las celdas vamos a colocar las leds en el cubo con mucho cuidado para que queden en la mitad teniendo en cuenta los cuadrados de las celdas para que quede en medio como en esta esta foto![IMG20240205120410](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/cc7cd842-7e0f-490a-b649-8122589fa1da)
(la foto no es el resultado final hemos puesto las aristas para que se pueda ver como ejemplo)

Para las tiras hace falta cortar 10 tiras de led de 40 pixeles para los lados y es importante tener cuidado con la colocacion de ellas ya que todas las flechas de las leds tienen que estar en el mismo sentido como en esta foto![IMG20240205121105](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/df096929-9a6f-4e73-abc8-791f336a49b8)

Hay un archivo llamado LEDen banaketa en el que se puede ver mas detalladamente la distribuicion y conexion de los LEDs.

A continuacion hemos colocado las fuentes de alimentacion en dos esquinas en diagonal para equilibrar el peso en el cubo, y despues de eso debemos hacer las conexiones a los leds(SIEMPRE EN PARALELO CON LAS FUENTES, si las haceis en SERIE no se iluminaran todas las LEDs con la misma intensidad). Los cables de alimentación de los LED salen de la caja a través de unos pequeños orificios cerca de cada tira de LED.![IMG20240205124517](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/dc0d17b4-7ce8-4f86-8b25-5118c9992abc)
![20240206_104944](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/91cb4a8a-024e-4e83-8a30-1b1e1d7a28c9)


Este seria el esquema electrico con todo, el tensy,bluetooth, fuente de alimentacion y las matrizes de leds![IMG_20240205_123355](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/7a47a3b9-10eb-4214-a8e2-0726fabffdd4)

parte 6.
![Conexiones foto](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/726f8875-6ce2-4069-a34f-35c12b214ce1)
![PCB foto](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/729b291c-e4c7-4556-aa72-66a4fa98f4b0)


![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/0f9e9cf6-db2f-4f61-a3ed-9f5c8aa19648)



