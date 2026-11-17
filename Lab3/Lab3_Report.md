# **Lab 3 Report**

Margalida Ferriol Torres (u266481), Martí Carrasco Guitart (u266404) – P201 / G04

## **1. Introducció**

En aquest laboratori, l'objectiu és ampliar el sistema de gestió del parc d'atraccions desenvolupat al Lab 2 incorporant el concepte d'**herència** i especialitzant les atraccions segons el diagrama UML dissenyat al Seminari 2. A partir de la classe base `Attraction`, s'han implementat tres noves classes derivades (`RollerCoaster`, `WaterRide` i `Simulator`), així com noves funcionalitats a les classes existents `Visitor`, `Area` i `Park`. Finalment, s'han adaptat les proves al programa principal (`testPark.cpp`) per verificar tant les operacions heredades i específiques com el compliment de totes les regles de validació.

<img width="687" height="510" alt="Captura de pantalla 2026-11-18 a les 0 39 07" src="https://github.com/user-attachments/assets/c0b39dae-7762-478e-9d4f-1dcfb68715ea" />


## **2. Implementació**

### 2.1. Jerarquia de l'herència:

* **Classe base `Attraction`:**
 La classe `Attraction` conté els atributs i mètodes comuns per totes les atraccions (`name`, `maxCapacity`, `duration`, `price`, `start()`, `stop()`...).
* **Classes derivades:**
  Totes tres subclasses fan servir llistes d'inicialització als seus constructors (`: Attraction(n, cap, dur, price)`) per la inicialització dels atributs heretats al constructor de la classe pare abans d'inicialitzar els seus atributs específics:
  * **`RollerCoaster`:** Introdueix els atributs privats `maxSpeed` (velocitat màxima, que ha de ser major que zero) i `loops` (nombre de girs, major o igual a 0), amb els seus respectius *getters* i *setters*. També té `checkSafetySystem()` per verificar arnesos i frens abans d'engegar l'atracció, i `isExtremeCoaster()`, que retorna `true` si la velocitat supera els 80 km/h o si té més de 2 loops.
  * **`WaterRide`:** Afegeix l'atribut privat `minHeight` (alçada mínima requerida per accedir-hi, sempre zero o positiva) amb el seu *getter* i *setter* corresponent. Té el mètode `prepareWaterPump()` per preparar el sistema d'aigua abans de posar-la en marxa, i `isVisitorAllowed(visitorHeight: double)`, que retorna `true` si l'alçada del visitant és igual o supera el mínim.
  * **`Simulator`:** Conté els atributs `simulationType` (descripció del tipus de simulació) i `motionIntensity` (intensitat del moviment, amb un rang de [0, 10]). Proporciona `resetSimulation()` per reiniciar la plataforma i el programari entre sessions, i `isHighIntensity()`, que retorna `true` si la intensitat és superior o igual a 7.

### **2.2. Ampliacions a `Visitor`, `Area` i `Park **

* **`Visitor`:**
  S'ha afegit l'atribut privat `currentArea` (de tipus `string`) per emmagatzemar el nom de l'àrea on es troba actualment el visitant, juntament amb els mètodes `moveToArea(areaName)` i `getCurrentArea()` per actualitzar-la i consultar-la. També s'han afegit `getTotalSpent()`, que suma el preu de tots els tiquets associats al visitant, i `getValidTicketsCount()`, que compta quants tiquets tenen l'estat `valid` a `true` d'un visitant. Els valors es calculen recorrent el vector `tickets`.

* **`Area`:**
  S'han afegit dues noves operacions de consulta sobre el vector d'atraccions de l'àrea: `getRunningAttractionsCount()`, que recorre el vector i retorna el nombre d'atraccions en funcionament, i `hasAttraction(name)`, que comprova si existeix alguna atracció dins el vector amb el nom especificat.

* **`Park`:**
  S'han implementat dos mètodes més per consultar informació global de tot el parc: `getTotalAttractions()`, que suma el nombre d'atraccions de totes les àrees registrades al parc, i `isVisitorRegistered(name)`, que verifica si un visitant amb el nom indicat forma part de la llista de visitants del parc.

## **3. Solucions alternatives i decisions de disseny**

* **`Visitor`:** Per tal que funcionin correctament els mètodes com `getTotalSpent()`, o `getValidTicketsCount()`, hem optat per modificar el tipus dels objectes de dins el vector `tickets`, per tal que siguin punters, i per tant, ara el vector és de tipus `Ticket*`. Amb això, ens assegurem que després que un tiquet s'associa a un visitant i llavors s'invalida, en el moment en que aquests mètodes recorrin el vector tickets per mirar l'atribut de validesa, el vegin com a `false`. Abans, es creava una còpia de l'objecte al vector `tickets`, i en invalidar-ne un, la còpia de dins el vector no ho feia, i els mètodes no funcionaven correctament.

    A part d'això, la variable iteradora dels bucles `for`, hem fet que sigui de tipus `size_t`, ja que si era `int`, el compilador del `Makefile` donava un error, i així `size_t` és un enter sense signe.

* **`Area` i `Park`:** Hem fet el mateix que amb el vector de tiquets a visitor: hem canviat el tipus del vector `areas` i `attractions` de `Park`i `Area`respectivament cap a punters, ja que així els mètodes que requerien la consulta d'atributs que es modificaven després de la assignació dels elements als vectors podien trobar-los actualitzats correctament.
 
* **`WaterRide`:** Per a `minHeight`, hem mantingut la validació perquè el valor no pugui ser negatiu. D'aquesta manera, si s'intenta assignar una alçada mínima inferior a zero, es conserva el valor anterior. També hem implementat `isVisitorAllowed()` comparant l'alçada del visitant amb `minHeight`, de manera que només es permet l'accés quan el visitant compleix l'alçada mínima requerida.

* **`Simulator`:** Per a `motionIntensity`, hem aplicat una validació perquè el valor es mantingui dins del rang establert de 0 a 10. Si s'introdueix un valor fora d'aquest rang, es conserva el valor anterior. Per al mètode `resetSimulation()`, hem utilitzat `stop()` per deixar el simulador aturat abans d'una nova sessió, ja que és l'estat que podem controlar directament amb la funcionalitat disponible de la classe.

### **Makefile**
Per facilitar la compilació del projecte, al seminari ens van comentar com fer-ho, i hem utilitzat un `Makefile` que automatitza el procés de compilació.

El `Makefile` cerca automàticament tots els fitxers `.cpp` de la carpeta i els converteix en fitxers objecte `.o`. Posteriorment, enllaça tots aquests fitxers per generar l'executable `testPark`.

D'aquesta manera, per compilar el projecte només cal executar `make`, mentre que amb `./testPark` podem executar el programa. També s'ha afegit `make clean`, que elimina els fitxers `.o` i l'executable generat per poder tornar a compilar el projecte des de zero.

## **4. Proves**

S'ha actualitzat el fitxer `testPark.cpp` per validar tant les noves classes com la integració amb la funcionalitat del Lab 2.

En primer lloc, s'han provat les classes derivades de `Attraction` amb diferents valors vàlids i invàlids. En el cas de `RollerCoaster`, s'han comprovat les validacions de `maxSpeed` i `loops`, així com les operacions `isExtremeCoaster()`, `start()`, `stop()` i `checkSafetySystem()`. També s'ha comprovat que els valors invàlids no modifiquen els atributs.

Per a `WaterRide`, s'ha comprovat la validació de `minHeight`, incloent-hi un valor negatiu, i el funcionament de `isVisitorAllowed()` amb visitants que compleixen i que no compleixen l'alçada mínima. També s'ha provat `prepareWaterPump()` i la funcionalitat heretada de `Attraction`.

En el cas de `Simulator`, s'han provat `setSimulationType()`, `setMotionIntensity()`, `isHighIntensity()` i `resetSimulation()`. S'han utilitzat tant valors vàlids com valors fora del rang permès per comprovar que la validació funciona correctament.

Finalment, s'ha creat un parc amb diverses àrees i diferents tipus d'atraccions per comprovar el funcionament conjunt del sistema. També s'han creat visitants i tiquets i s'han comprovat les funcionalitats de `Visitor`, `Area` i `Park`, com el recompte d'atraccions, la cerca d'atraccions, el recompte d'atraccions en funcionament, els tiquets vàlids i el registre de visitants.

Les proves han donat els resultats esperats, tant en els casos vàlids com en els casos invàlids, i han permès comprovar que la funcionalitat heretada d'Attraction continua funcionant correctament en les classes derivades.


## **5. Conclusions**

Amb aquest laboratori hem pogut ampliar el sistema del parc d'atraccions del Lab 2 aplicant el concepte d'herència. Hem creat les classes `RollerCoaster`, `WaterRide` i `Simulator` a partir de la classe base `Attraction`, mantenint la funcionalitat comuna i afegint les operacions específiques de cada tipus d'atracció.

Durant la implementació també hem hagut de modificar algunes parts de les classes `Visitor`, `Area` i `Park` perquè treballessin correctament amb els objectes originals. En particular, l'ús de punters als vectors ha estat important per evitar treballar amb còpies dels objectes i poder consultar els seus valors actualitzats.

Les proves realitzades han permès comprovar que les validacions funcionen correctament, tant amb valors vàlids com amb valors invàlids, i que les funcionalitats heretades d'`Attraction` continuen funcionant en les classes derivades.

Finalment, la utilització del `Makefile` ha facilitat la compilació i l'execució del projecte, ja que permet automatitzar la compilació dels diferents fitxers `.cpp` i la generació de l'executable.

En general, aquest laboratori ens ha ajudat a entendre millor com funciona l’herència i com podem utilitzar els punters en C++. 