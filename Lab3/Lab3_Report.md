# **Lab 3 Report**

Margalida Ferriol Torres (u266481), Martí Carrasco Guitart (u266404) – P201 / G04

## **1. Introducció**

En aquest laboratori, l'objectiu és ampliar el sistema de gestió del parc d'atraccions desenvolupat al Lab 2 incorporant el concepte d'**herència** i especialitzant les atraccions segons el diagrama UML dissenyat al Seminari 2. A partir de la classe base `Attraction`, s'han implementat tres noves classes derivades (`RollerCoaster`, `WaterRide` i `Simulator`), així com noves funcionalitats a les classes existents `Visitor`, `Area` i `Park`. Finalment, s'han adaptat les proves al programa principal (`testPark.cpp`) per verificar tant les operacions heredades i específiques com el compliment de totes les regles de validació.

*(enganxar aquí la imatge del diagrama UML final del Seminari 2 / Lab 3)*

## **2. Implementació**

### 2.1. Jerarquia de l'herència:

* **Classe base `Attraction`:**
 La classe `Attraction` conté els atributs i mètodes comuns per totes les atraccions (`name`, `maxCapacity`, `duration`, `price`, `start()`, `stop()`...).
* **Classes derivades:**
  Totes tres subclasses fan servir llistes d'inicialització als seus constructors (`: Attraction(n, cap, dur, price)`) per la inicialització dels atributs heretats al constructor de la classe pare abans d'inicialitzar els seus atributs específics:
  * **`RollerCoaster`:** Introdueix els atributs privats `maxSpeed` (velocitat màxima, que ha de ser major que zero) i `loops` (nombre de girs, major o igual a 0), amb els seus respectius *getters* i *setters*. També té `checkSafetySystem()` per verificar arnesos i frens abans d'engegar l'atracció, i `isExtremeCoaster()`, que retorna `true` si la velocitat supera els 80 km/h o si té més de 2 loops.
  * **`WaterRide`:** Afegeix l'atribut `minHeight` (alçada mínima requerida per accedir-hi, sempre zero o positiva) amb el seu *getter* i *setter* corresponent. Té el mètode `prepareWaterPump()` per activar el sistema hidràulic abans de posar-la en marxa, i `isVisitorAllowed(visitorHeight: double)`, que retorna `true` si l'alçada del visitant és igual o supera el mínim.
  * **`Simulator`:** Conté els atributs `simulationType` (descripció del tipus de simulació) i `motionIntensity` (intensitat del moviment, amb un rang de [0, 10]). Proporciona `resetSimulation()` per reiniciar la plataforma i el programari entre sessions, i `isHighIntensity()`, que retorna `true` si la intensitat és superior o igual a 7.

### **2.2. Ampliacions a `Visitor`, `Area` i `Park

* **`Visitor`:**
  S'ha afegit l'atribut privat `currentArea` (de tipus `string`) per emmagatzemar el nom de l'àrea on es troba actualment el visitant, juntament amb els mètodes `moveToArea(areaName)` i `getCurrentArea()` per actualitzar-la i consultar-la. També s'han afegit `getTotalSpent()`, que suma el preu de tots els tiquets associats al visitant, i `getValidTicketsCount()`, que compta quants tiquets tenen l'estat `valid` a `true` d'un visitant. Els valors es calculen recorrent el vector `tickets`.

* **`Area`:**
  S'han afegit dues noves operacions de consulta sobre el vector d'atraccions de l'àrea: `getRunningAttractionsCount()`, que el recorre  retorna el nombre d'atraccions en funcionament, i `hasAttraction(name)`, que comprova si existeix alguna atracció dins el vector amb el nom especificat.

* **`Park`:**
  S'han implementat dos mètodes més per consultar informació global de tot el parc: `getTotalAttractions()`, que suma el nombre d'atraccions de totes les àrees registrades al parc, i `isVisitorRegistered(name)`, que verifica si un visitant amb el nom indicat forma part de la llista de visitants del parc.

## **3. Solucions alternatives i decisions de disseny**

* **`Visitor`:** Per tal que funcionin correctament els mètodes com `getTotalSpent()`, o `getValidTicketsCount()`, hem optat per modificar el tipus dels objectes de dins el vector `tickets`, per tal que siguin punters, i per tant, ara el vector és de tipus `Ticket*`. Amb això, ens assegurem que després que un tiquet s'associa a un visitant i llavors s'invalida, en el moment en que aquests mètodes recorrin el vector tickets per mirar l'atribut de validesa, el vegin com a `false`. Abans, es creava una còpia de l'objecte al vector `tickets`, i en invalidar-ne un, la còpia de dins el vector no ho feia, i els mètodes no funcionaven correctament.

    A part d'això, la variable iteradora dels bucles `for`, hem fet que sigui de tipus `size_t`, ja que si era `int`, el compilador del `Makefile`donava un error, i així `size_t`és un enter sense signe.

* **`Area` i `Park`:** Hem fet el mateix que amb el vector de tiquets a visitor: hem canviat el tipus del vector `areas`i `attractions`de `Park`i `Area`respectivament cap a punters, ja que així els mètodes que requerien la consulta d'atributs que es modificaven després de la assignació dels elements als vectors podien trobar-los actualitzats correctament.
 

falta explicar el makefile
## **4. Proves**

S'ha actualitzat el fitxer `testPark.cpp` per validar tant les noves classes com la integració amb la funcionalitat del Lab 2:


## **5. Conclusions**

