#include <iostream>

#include "Area.h"
#include "Park.h"
#include "Ticket.h"
#include "Visitor.h"
#include "WaterRide.h"
#include "Simulator.h"
#include "RollerCoaster.h"

int main() {
    std::cout << std::boolalpha; // mostra els valors booleans com 'true' / 'false' en lloc de 1 / 0

    // TEST ROLLERCOASTER
    RollerCoaster coaster1("Furious Baco", 25, 2, 8.0, 70.0, 2);
    RollerCoaster coaster2("Shambala", -28, -4, -8.0, 0.0, -1);

    std::cout << "[Rollercoaster 1] Nom: "
              << coaster1.getName() << std::endl;
    std::cout << "[Rollercoaster 2] Nom: "
              << coaster2.getName() << std::endl;
    std::cout << "[Rollercoaster 2] Capacitat corregida: "
              << coaster2.getMaxCapacity() << std::endl;
    std::cout << "[Rollercoaster 2] Durada corregida: "
              << coaster2.getDuration() << std::endl;
    std::cout << "[Rollercoaster 2] Preu corregit: "
              << coaster2.getPrice() << std::endl;
    std::cout << "[Rollercoaster 2] Velocitat corregida: "
              << coaster2.getMaxSpeed() << std::endl;
    std::cout << "[Rollercoaster 2] Nombre de loops corregit: "
              << coaster2.getLoops() << std::endl;

    // Comprovem funcionalitat heretada
    std::cout << "[Rollercoaster 1] Estat inicial: "
              << coaster1.isRunning() << std::endl;
    coaster1.start();
    std::cout << "[Rollercoaster 1] Estat després de start(): "
              << coaster1.isRunning() << std::endl;
    coaster1.stop();
    std::cout << "[Rollercoaster 1] Estat després de stop(): "
              << coaster1.isRunning() << std::endl;

    // Modifiquem valors de coaster1 amb valors incorrectes:
    std::cout << "[Rollercoaster 1] MaxSpeed abans de canviar: "
              << coaster1.getMaxSpeed() << std::endl;
    coaster1.setMaxSpeed(-2.0);
    std::cout << "[Rollercoaster 1] MaxSpeed després d'intent fallit de canviar: "
              << coaster1.getMaxSpeed() << std::endl;

    std::cout << "[Rollercoaster 1] Loops abans de canviar: "
              << coaster1.getLoops() << std::endl;
    coaster1.setLoops(-2);
    std::cout << "[Rollercoaster 1] Loops després d'intent fallit de canviar: "
              << coaster1.getLoops() << std::endl;

    // Mirem extreme coaster
    std::cout << "[Rollercoaster 1] És extreme coaster (abans)?: "
              << coaster1.isExtremeCoaster() << std::endl;

    // Canviem velocitat a una major a 80:
    coaster1.setMaxSpeed(100.0);

    // Comparem
    std::cout << "[Rollercoaster 1] És extreme coaster (després)?: "
              << coaster1.isExtremeCoaster() << std::endl;

    // Comprovem també el cas de tenir més de 2 loops
    coaster1.setMaxSpeed(70.0);
    coaster1.setLoops(3);
    std::cout << "[Rollercoaster 1] És extreme coaster amb 3 loops?: "
              << coaster1.isExtremeCoaster() << std::endl;

    // Comprovem sistemes de seguretat abans d'operar
    coaster1.checkSafetySystem();

    std::cout << std::endl;

    // TEST WATER RIDE
    WaterRide attraction1("Troncs", -10, 0, -5.0, -120.0);
    WaterRide attraction2("Super Flume", 30, 3, 10.0, 130.0);

    std::cout << "[WaterRide] Nom: "
              << attraction1.getName() << std::endl;
    std::cout << "[WaterRide] Capacitat corregida: "
              << attraction1.getMaxCapacity() << std::endl;
    std::cout << "[WaterRide] Durada corregida: "
              << attraction1.getDuration() << std::endl;
    std::cout << "[WaterRide] Preu corregit: "
              << attraction1.getPrice() << std::endl;
    std::cout << "[WaterRide] Altura minima corregida: "
              << attraction1.getMinHeight() << std::endl;
    std::cout << "[WaterRide] Estat inicial engegada: "
              << attraction1.isRunning() << std::endl;

    // Preparem el sistema hidràulic abans d'engegar
    attraction1.prepareWaterPump();

    std::cout << "[WaterRide] Visitant de 130cm permès (minHeight 0): "
              << attraction1.isVisitorAllowed(130.0)
              << std::endl; // esperat: true

    // Intentem modificar minHeight amb valor negatiu
    attraction1.setMinHeight(-50.0);
    std::cout << "[WaterRide] Altura minima després d'intent negatiu: "
              << attraction1.getMinHeight()
              << std::endl; // esperat: 0

    attraction1.setMinHeight(150.0);
    std::cout << "[WaterRide] Altura minima modificada: "
              << attraction1.getMinHeight()
              << std::endl; // esperat: 150

    std::cout << "[WaterRide] Visitant de 150cm permès: "
              << attraction1.isVisitorAllowed(150.0)
              << std::endl; // esperat: true

    std::cout << "[WaterRide] Visitant de 140cm permès: "
              << attraction1.isVisitorAllowed(140.0)
              << std::endl; // esperat: false

    std::cout << std::endl;

    // TEST SIMULATOR
    Simulator simulator1("Vol espacial", 30, 5, 15.0, "Vol espacial", 8);

    std::cout << "[Simulator] Tipus: "
              << simulator1.getSimulationType() << std::endl;
    std::cout << "[Simulator] Intensitat: "
              << simulator1.getMotionIntensity() << std::endl;
    std::cout << "[Simulator] Intensitat alta: "
              << simulator1.isHighIntensity() << std::endl;

    // Comprovem funcionalitat heretada
    simulator1.start();
    std::cout << "[Simulator] Estat després de start(): "
              << simulator1.isRunning() << std::endl;

    // Reiniciem el simulador abans d'una nova sessió
    simulator1.resetSimulation();
    std::cout << "[Simulator] Estat després de resetSimulation(): "
              << simulator1.isRunning() << std::endl;

    // Test setSimulationType
    simulator1.setSimulationType("Terror");
    std::cout << "[Simulator] Tipus modificat: "
              << simulator1.getSimulationType() << std::endl;

    // Test setMotionIntensity amb valor vàlid
    simulator1.setMotionIntensity(6);
    std::cout << "[Simulator] Intensitat modificada: "
              << simulator1.getMotionIntensity() << std::endl; // esperat: 6

    std::cout << "[Simulator] Intensitat alta amb 6: "
              << simulator1.isHighIntensity() << std::endl; // esperat: false

    // Test setMotionIntensity amb valor massa alt
    simulator1.setMotionIntensity(15);
    std::cout << "[Simulator] Intensitat després de posar 15: "
              << simulator1.getMotionIntensity() << std::endl; // esperat: 6

    // Test setMotionIntensity amb valor negatiu
    simulator1.setMotionIntensity(-3);
    std::cout << "[Simulator] Intensitat després de posar -3: "
              << simulator1.getMotionIntensity() << std::endl; // esperat: 6

    std::cout << std::endl;

    // TEST VISITOR / TICKET / AREA / PARK
    // Creem parc:
    Park park1("PortAventura");

    // Creem àrees, les assignem al parc i hi posem atraccions:
    Area area1("Far West", "First area ever created.");
    Area area2("Mediterranea", "Entrance area, inspired in a small town.");
    Area area3("Mexico", "Inspired in the mexican culture.");

    park1.addArea(&area1);
    park1.addArea(&area2);
    park1.addArea(&area3);

    area1.addAttraction(&coaster1);
    area1.addAttraction(&coaster2);

    area2.addAttraction(&attraction2);
    area2.addAttraction(&simulator1);

    area3.addAttraction(&attraction1);

    // Comprovem el total d'atraccions del parc i la cerca per nom a l'àrea
    std::cout << "[Park] Total d'atraccions al parc: "
              << park1.getTotalAttractions() << std::endl; // esperat: 5

    std::cout << "[Area] Far West té 'Furious Baco'?: "
              << area1.hasAttraction("Furious Baco") << std::endl; // esperat: true

    std::cout << "[Area] Far West té 'Troncs'?: "
              << area1.hasAttraction("Troncs") << std::endl; // esperat: false

    // Creem tiquets:
    Ticket ticket1(1, 8);
    Ticket ticket2(2, 12);
    Ticket ticket3(3, 12);
    Ticket ticket4(4, 10);
    Ticket ticket5(5, -11);
    Ticket ticket6(6, 15);

    // Engeguem atraccions excepte attraction2:
    coaster1.start();
    coaster2.start();
    attraction1.start();
    simulator1.start();

    // A l'àrea Far West hi hauria d'haver 2 atraccions funcionant, i a Mediterranea, 1 atracció funcionant
    std::cout << "Hi ha " << area1.getRunningAttractionsCount() << " atraccions funcionant a la àrea "
              << area1.getName() << "." << std::endl;

    std::cout << "Hi ha " << area2.getRunningAttractionsCount() << " atraccions funcionant a la àrea "
              << area2.getName() << "." << std::endl;

    // Creem visitors i els associem a tiquets, àrees i parc:
    Visitor visitor1("Peppa", 86);
    visitor1.addTicket(&ticket1); // associem dos tiquets al visitant
    visitor1.addTicket(&ticket2);
    visitor1.moveToArea("Mediterranea");
    ticket1.invalidate(); // li invalidem un tiquet

    std::cout << visitor1.getName() << " està a la àrea " << visitor1.getCurrentArea()
              << ", s'ha gastat " << visitor1.getTotalSpent() << "€, i té " << visitor1.getValidTicketsCount()
              << " tiquet(s) vàlids." << std::endl;

    Visitor visitor2("Peppo", -93); // visitor amb edat negativa
    visitor2.addTicket(&ticket3);

    Visitor visitor3("Peppe", 68);
    visitor3.addTicket(&ticket4);

    Visitor visitor4("Pepppi", 2);
    visitor4.addTicket(&ticket5);
    visitor4.addTicket(&ticket6);

    // Registrem els visitants al parc i comprovem si hi són
    park1.addVisitor(visitor1);
    park1.addVisitor(visitor2);
    park1.addVisitor(visitor3);
    park1.addVisitor(visitor4);

    std::cout << "[Park] Està registrada 'Peppa'?: "
              << park1.isVisitorRegistered("Peppa") << std::endl; // esperat: true

    std::cout << "[Park] Està registrat 'Joan'?: "
              << park1.isVisitorRegistered("Joan") << std::endl; // esperat: false

    return 0;
}
