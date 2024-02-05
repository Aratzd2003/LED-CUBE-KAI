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


Arazoa: Konexioak eta zirkuitulaburrak

Descripción: Antes de conectar los LEDs a la fuente de alimentación, es crucial verificar minuciosamente todas las conexiones y cables. La confusión en las conexiones puede resultar en cortocircuitos, dañando tanto los LEDs como la fuente de alimentación.

Solución: Realiza una revisión exhaustiva de las conexiones antes de aplicar la alimentación. Asegúrate de que cada conexión sea precisa y que no haya posibilidad de cortocircuitos.



Problema: Desajuste en Ángulos de las Piezas del Cubo

Descripción: Los ángulos de las aristas y esquinas no cuadraban inicialmente. Se solucionó creando primero las piezas de los lados y luego calculando los ángulos de las aristas para garantizar un ajuste preciso al ensamblar el cubo.

Solución: Al construir el cubo, inicia con las piezas de los lados y calcula los ángulos de las aristas para lograr una unión perfecta y evitar desajustes en las esquinas.



Problema: Tira de LED No Funciona

Descripción: Alguna tira de LED no se encendía inicialmente, lo que se atribuyó a un posible problema de conexión. La solución fue retirar las tiras de LED y verificar su funcionamiento utilizando un código básico fuera del circuito para asegurarse de que estuvieran adecuadamente alimentadas.

Solución: Si una tira de LED no se ilumina, retírala y verifica su funcionamiento fuera del circuito. Asegúrate de que esté recibiendo la alimentación adecuada y corrige cualquier problema de conexión.



Problema: Problemas en el Diseño de la PCB

Descripción: Se han experimentado varios problemas al diseñar las placas debido a la falta de planificación en la distribución de elementos y conexiones.

Solución: Antes de fabricar las placas, planifica cuidadosamente la distribución de elementos y conexiones. Asegúrate de tener un diseño claro y revisa todas las conexiones antes de la fabricación.



Problema: Dificultad para Entender el Código con la Librería #fastled

Descripción: Se ha encontrado dificultad en comprender el código al utilizar la librería #fastled. Después de buscar ayuda en internet y realizar varios intentos, se lograron diferentes efectos con los LEDs.

Solución: Para comprender el código con la librería #fastled, busca ayuda en recursos en línea y realiza pruebas. En la carpeta de códigos, se han dejado pruebas y experimentos previos antes de la creación del código definitivo para referencia.



MUNTATZEKO JARRAITU BEHARREKO PAUSOAK

Ezer baino lehen, proiektua egiteko materialak beharko ditugu. "Materialen zerrenda" izeneko karpetan erantsi dizkizuegu. Material batzuen zehaztapen zehatzak, berriz, argazkiak emango dizkizuegu montagean (adibidez, ertzak).

En primer lugar vamos a construir la caja de madera y la rejilla de LED. Las dimensiones del cubo están especificadas por la distancia del píxel en la tira de LED. En este caso los píxeles tienen una distancia de 3,4cm, por lo que el cubo tiene que medir 34 x 34 x 34cm. Ahorrarás mucho tiempo usando estas dimensiones, porque no necesitarás cortar la tira después de cada píxel y volver a unirla con un pequeño cable.


pieza horizontal:
![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/65ff9237-2937-4c65-8f60-021533c2471a)

pieza vertical:
![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/93e37657-535a-41ff-a46d-bf45ebd89b28)

pieza lateral superior:
![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/c3ea5b73-5b88-4f9e-b0b0-bc71ee9dc559)

pieza lateral vertical:
![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/2a73e797-f520-4360-a4bc-63341ca10b05)





parte 6.
![Conexiones foto](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/726f8875-6ce2-4069-a34f-35c12b214ce1)
![PCB foto](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/729b291c-e4c7-4556-aa72-66a4fa98f4b0)


