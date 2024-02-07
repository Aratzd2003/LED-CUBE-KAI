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


Elementu berriak sartzea:
Ezaugarri berriak gehitu ditugu, hala nola kuboaren barruko osagaien banaketa edo kuboaren egurrezko oinarria, orain kuboaren plakan marraztutako gure logoa ikusten uzten diguna.



Inspirazio-iturria ezagutzean eta jatorrizko sortzaileari eskerrak ematean, haren lana aitortzeaz gain, LEDen eta proiektu elektronikoen zale sutsuen komunitatearen barruan ezagutzak trukatzen laguntzea ere bilatzen dugu. Jatorrizko proiektuaren ikuspegi, egokitzapen eta hedapen berri hori "LED-CUBE KAI" delakoan islatzen da, eta orain beste sortzaile eta zale batzuk inspiratzea espero da, LEDen kuboak eraikitzeko esperientzia pertsonalizatuan murgiltzeko.


ARAZOAK ETA KONPONBIDEAK PROIEKTUAN


1. Arazoa: Konexioak eta zirkuitulaburrak

Deskribapena: Led-ak elikatze iturrira konektatu aurretik beharrezkoa da zehatz mehatz begiratzea ea ondo dauden konexioak, bestela zierkuito laburra gerta liteke eta ondorioz led-ak hautsi daitezke.

Konponbidea: Elikatze iturria ezarri aurretik berrikuspen zehatz bat egin eta konexioak guztiak ziurtatu behar dira. 

2. Arazoa: Koboko anguluen neurri txarra

Deskribapena: Hasiera baten aristen anguluek eta ixki ez zuten bat egiten.Se solucionó creando primero las piezas de los lados y luego calculando los ángulos de las aristas para garantizar un ajuste preciso al ensamblar el cubo.

Konponbidea: Kuboa montatzekoan, alboko piezekin eta aristen alguluen neurtzen hasi horrela biak batzerakoan elkarketa bikaina lortuko da.  

3. Arazoa : Led tira ez dabil

Deskribapena: Hasiera baten LED tira ez zen piztutzen, non konexio arazoekin liteke.  La solución fue retirar las tiras de LED y verificar su funcionamiento utilizando un código básico fuera del circuito para asegurarse de que estuvieran adecuadamente alimentadas.

Konponbidea: LED tira kendu eta kodigoaren bitartez ziurtatu ea funtzionamendua ondo dijoala, horrekin ikusi daiteke badijoazten edo ez.


4. Arazoa: PCB-ren diseinua

Deskribapena: Hainbat arazo egon daitezke plakako elemntuak ondo ez badira neurtzen edo haien konexioak zein espazioak kontuan hartzen.

Konponbidea: Plakak fresatu aurretik, planifikatu arretaz elementuen eta konexioen banaketa. Ziurtatu diseinu argia duzula eta berrikusi konexio guztiak fabrikazioaren aurretik.


5. arazoa: #fastled liburutegiko kodea ulertzeko zailtasuna.

deskribapena: #fastled liburudenda erabiltzean kodea ulertzeko zailtasuna aurkitu da. Interneten laguntza bilatu eta hainbat saiakera egin ondoren, LEDekin efektu desberdinak lortu ziren.


Konponbidea: #fastled liburu-dendarekin kodea ulertzeko, bilatu laguntza online baliabideetan eta egin probak. Kodeen karpetan, erreferentziako behin betiko kodea sortu aurretik probak eta esperimentuak utzi dira.

¡¡¡GARRANTZITSUA!!!
5. arazoa: Goiko metriza

Deskribapena: Konexio guztiak amaituzean eta PCB edukita, arazoak izaten hasi ginen goiko led-en matrizearekin, esaterako kolore urdinez jartzea eskatzen genionean beste kolore batzuetako ezartzen zen.

Konponbidea: Proba asko egin eta zirkuitu elektriko guztia eta kodea modu exaustiboan aztertu ondoren, elikadura-iturrien arazoa zela ondorioztatu genuen, eta LEDak elikatzen zituen iturria aldatu eta beste bat jarri genuen. Aldaketa hori egitean, ondo funtzionatzen zuen. Beraz, ez dizuegu gomendatzen guk erosten ditugun elikadura-iturri berberak erostea, ezaugarri berberak dituzten iturri batzuk bilatzea (5V eta 30A) eta kuboaren barruko espazioarekin bat datorren tamaina dutenak.


MUNTATZEKO JARRAITU BEHARREKO PAUSOAK

Ezer baino lehen, proiektua egiteko materialak beharko ditugu. "Materialen zerrenda" izeneko karpetan erantsi dizkizuegu. Material batzuen zehaztapen zehatzak, berriz, argazkiak emango dizkizuegu montagean (adibidez, ertzak).

Lehendabizi kaxa eta xaflak montatuko ditugu. Kaxa egurrezko bost piezataz osatuta dago (basea gehituta, pieza handiena dela). 

Alboko aldeak:
x2 pieza 25,2cm x 29,6cm x 1,0cm (pieza "txikiak")

x2 pieza 29,6cm x 27,2cm x 1,0cm (pieza "handiak")

x1 pieza 27,2cm x 27,2cm x 1,0cm ("goiko" pieza)

x1 pieza  34,0cm x 34,0cm x 1,5cm ("baseko" pieza)

![20240117_131805](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/975da80e-79b9-4ddc-a92e-8cd2279c1975)
![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/278afd6b-e386-463a-a739-4b93bc5f915a)

![20240111_123909](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/76f7f9c3-6173-40e8-aa7a-d72733c7ff0c)

![image](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/0f9e9cf6-db2f-4f61-a3ed-9f5c8aa19648)
![IMG20240206104117](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/23152192-f9eb-48a9-ba30-83726dce2e07)


Kuboaren neurriak (kanpokoak, ez barruko kuboarenak) pixelek LEDen zerrendan duten distantziaren arabera zehazten dira (10 pixel zabal alde bakoitzean). Kasu honetan pixelek 3,4cm-ko distantzia dute, beraz, kuboak 34 x 34 x 34cm neurtu behar ditu. Denbora asko aurreztuko duzu dimentsio horiek erabiliz, ez baituzu pixel bakoitzaren ondoren zerrenda moztu eta kable txiki batekin berriro lotu beharko.


Behar bezala lan egin behar duzu, akriliko-kaxa ezin hobeto egokitzen baita egurrezko kaxaren goialdean. Askoz errazagoa bihurtzen da boluntario batzuekin zure inguruan, edo, besterik gabe, erabili marko tenkagailu bat guk egin genuen bezala. Zurezko itsasgarriarekin "KUBOAREN IZKINAK" egiten dituzten "ERTZAK" itsatsiko ditugu. Nahiko zaila da 45 gradu lortzea gelaxkak zedarritzen dituzten ertz-punten angeluan. Horrela, adi egon eta pieza bakoitza ondo diseinatu eta egin behar da.



Ertzak egiteko, piezak neurri egokiekin beharko ditugu. Gure kasuan, ez ditugu erreferentzia gisa erabili dugun proiektuko neurri berak erabili. Horretarako, fitxategi bat utziko dugu erantsita, laser ebakigailuarekin (XTOOL D1 PRO) ebakitzeko erabili ditugun piezekin. Piezen neurriak honako hauek dira
:![IMG20240206100735](https://github.com/Aratzd2003/LED-CUBE-KAI/assets/158164861/b32921a3-e380-4c07-98eb-e1f8b6972bab)


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



