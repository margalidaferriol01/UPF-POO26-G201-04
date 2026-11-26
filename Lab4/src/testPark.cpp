#include <iostream>
#include <string>
#include <memory>

#include "Area.h"
#include "Park.h"
#include "Ticket.h"
#include "Visitor.h"
#include "WaterRide.h"
#include "Simulator.h"
#include "RollerCoaster.h"
#include "Reservation.h"

using namespace std;

int main() {
    cout << boolalpha; // mostra els valors booleans com 'true' / 'false' en lloc de 1 / 0

    // TEST ROLLERCOASTER
    RollerCoaster coaster1("Furious Baco", 25, 2, 8.0, 70.0, 2);
    RollerCoaster coaster2("Shambala", -28, -4, -8.0, 0.0, -1);

    cout << "[Rollercoaster 1] Nom: "
         << coaster1.getName() << endl;
    cout << "[Rollercoaster 2] Nom: "
         << coaster2.getName() << endl;
    cout << "[Rollercoaster 2] Capacitat corregida: "
         << coaster2.getMaxCapacity() << endl;
    cout << "[Rollercoaster 2] Durada corregida: "
         << coaster2.getDuration() << endl;
    cout << "[Rollercoaster 2] Preu corregit: "
         << coaster2.getPrice() << endl;
    cout << "[Rollercoaster 2] Velocitat corregida: "
         << coaster2.getMaxSpeed() << endl;
    cout << "[Rollercoaster 2] Nombre de loops corregit: "
         << coaster2.getLoops() << endl;

    // Comprovem funcionalitat heretada
    cout << "[Rollercoaster 1] Estat inicial: "
         << coaster1.isRunning() << endl;
    coaster1.start();
    cout << "[Rollercoaster 1] Estat després de start(): "
         << coaster1.isRunning() << endl;
    coaster1.stop();
    cout << "[Rollercoaster 1] Estat després de stop(): "
         << coaster1.isRunning() << endl;

    // Modifiquem valors de coaster1 amb valors incorrectes:
    cout << "[Rollercoaster 1] MaxSpeed abans de canviar: "
         << coaster1.getMaxSpeed() << endl;
    coaster1.setMaxSpeed(-2.0);
    cout << "[Rollercoaster 1] MaxSpeed després d'intentar canviar-lo: "
         << coaster1.getMaxSpeed() << endl;

    cout << "[Rollercoaster 1] Loops abans de canviar: "
         << coaster1.getLoops() << endl;
    coaster1.setLoops(-2);
    cout << "[Rollercoaster 1] Loops després d'intentar canviar-lo: "
         << coaster1.getLoops() << endl;

    // Mirem extreme coaster
    cout << "[Rollercoaster 1] És extreme coaster (abans)?: "
         << coaster1.isExtremeCoaster() << endl;

    // Canviem velocitat a una major a 80:
    coaster1.setMaxSpeed(100.0);

    // Comparem
    cout << "[Rollercoaster 1] És extreme coaster (després)?: "
         << coaster1.isExtremeCoaster() << endl;

    // Comprovem també el cas de tenir més de 2 loops
    coaster1.setMaxSpeed(70.0);
    coaster1.setLoops(3);
    cout << "[Rollercoaster 1] És extreme coaster amb 3 loops?: "
         << coaster1.isExtremeCoaster() << endl;

    // Comprovem sistemes de seguretat abans d'operar
    coaster1.checkSafetySystem();

    cout << endl;

    // TEST WATER RIDE
    WaterRide attraction1("Troncs", -10, 0, -5.0, -120.0);
    WaterRide attraction2("Super Flume", 30, 3, 10.0, 130.0);

    cout << "[WaterRide] Nom: "
         << attraction1.getName() << endl;
    cout << "[WaterRide] Capacitat corregida: "
         << attraction1.getMaxCapacity() << endl;
    cout << "[WaterRide] Durada corregida: "
         << attraction1.getDuration() << endl;
    cout << "[WaterRide] Preu corregit: "
         << attraction1.getPrice() << endl;
    cout << "[WaterRide] Altura minima corregida: "
         << attraction1.getMinHeight() << endl;
    cout << "[WaterRide] Estat inicial engegada: "
         << attraction1.isRunning() << endl;

    // Preparem el sistema hidràulic abans d'engegar
    attraction1.prepareWaterPump();

    cout << "[WaterRide] Visitant de 130cm permès (minHeight 0): "
         << attraction1.isVisitorAllowed(130.0)
         << endl; // esperat: true

    // Intentem modificar minHeight amb valor negatiu
    attraction1.setMinHeight(-50.0);
    cout << "[WaterRide] Altura minima després d'intent negatiu: "
         << attraction1.getMinHeight()
         << endl; // esperat: 0

    attraction1.setMinHeight(150.0);
    cout << "[WaterRide] Altura minima modificada: "
         << attraction1.getMinHeight()
         << endl; // esperat: 150

    cout << "[WaterRide] Visitant de 150cm permès: "
         << attraction1.isVisitorAllowed(150.0)
         << endl; // esperat: true

    cout << "[WaterRide] Visitant de 140cm permès: "
         << attraction1.isVisitorAllowed(140.0)
         << endl; // esperat: false

    cout << endl;

    // TEST SIMULATOR
    Simulator simulator1("Vol espacial", 30, 5, 15.0, "Vol espacial", 8);

    cout << "[Simulator] Tipus: "
         << simulator1.getSimulationType() << endl;
    cout << "[Simulator] Intensitat: "
         << simulator1.getMotionIntensity() << endl;
    cout << "[Simulator] Intensitat alta: "
         << simulator1.isHighIntensity() << endl;

    // Comprovem funcionalitat heretada
    simulator1.start();
    cout << "[Simulator] Estat després de start(): "
         << simulator1.isRunning() << endl;

    // Reiniciem el simulador abans d'una nova sessió
    simulator1.resetSimulation();
    cout << "[Simulator] Estat després de resetSimulation(): "
         << simulator1.isRunning() << endl;

    // Test setSimulationType
    simulator1.setSimulationType("Terror");
    cout << "[Simulator] Tipus modificat: "
         << simulator1.getSimulationType() << endl;

    // Test setMotionIntensity amb valor vàlid
    simulator1.setMotionIntensity(6);
    cout << "[Simulator] Intensitat modificada: "
         << simulator1.getMotionIntensity() << endl; // esperat: 6

    cout << "[Simulator] Intensitat alta amb 6: "
         << simulator1.isHighIntensity() << endl; // esperat: false

    // Test setMotionIntensity amb valor massa alt
    simulator1.setMotionIntensity(15);
    cout << "[Simulator] Intensitat després de posar 15: "
         << simulator1.getMotionIntensity() << endl; // esperat: 6

    // Test setMotionIntensity amb valor negatiu
    simulator1.setMotionIntensity(-3);
    cout << "[Simulator] Intensitat després de posar -3: "
         << simulator1.getMotionIntensity() << endl; // esperat: 6

    cout << endl;

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
    cout << "[Park] Total d'atraccions al parc: "
         << park1.getTotalAttractions() << endl; // esperat: 5

    cout << "[Area] Far West té 'Furious Baco'?: "
         << area1.hasAttraction("Furious Baco") << endl; // esperat: true

    cout << "[Area] Far West té 'Troncs'?: "
         << area1.hasAttraction("Troncs") << endl; // esperat: false

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
    cout << "Hi ha " << area1.getRunningAttractionsCount() << " atraccions funcionant a l'àrea "
         << area1.getName() << "." << endl;

    cout << "Hi ha " << area2.getRunningAttractionsCount() << " atraccions funcionant a l'àrea "
         << area2.getName() << "." << endl;

    // Creem visitors i els associem a tiquets, àrees i parc:
    Visitor visitor1("Peppa", 86);
    visitor1.addTicket(&ticket1); // associem dos tiquets al visitant
    visitor1.addTicket(&ticket2);
    // visitor1.moveToArea("Mediterranea");
    visitor1.moveToArea(&area2);
    ticket1.invalidate(); // li invalidem un tiquet

    cout << visitor1.getName() << " està a l'àrea " << visitor1.getCurrentArea()->getName()
         << ", s'ha gastat " << visitor1.getTotalSpent() << "€, i té " << visitor1.getValidTicketsCount()
         << " tiquet(s) vàlids." << endl;

    Visitor visitor2("Peppo", -93); // visitor amb edat negativa
    visitor2.addTicket(&ticket3);

    Visitor visitor3("Peppe", 68);
    visitor3.addTicket(&ticket4);

    Visitor visitor4("Pepppi", 2);
    visitor4.addTicket(&ticket5);
    visitor4.addTicket(&ticket6);

    // Registrem els visitants al parc i comprovem si hi són
    park1.addVisitor(&visitor1);
    park1.addVisitor(&visitor2);
    park1.addVisitor(&visitor3);
    park1.addVisitor(&visitor4);

    cout << "[Park] Està registrada 'Peppa'?: "
         << park1.isVisitorRegistered("Peppa") << endl; // esperat: true

    cout << "[Park] Està registrat 'Joan'?: "
         << park1.isVisitorRegistered("Joan") << endl; // esperat: false

    // TEST VISITOR / AREA

    cout << endl;
    cout << "===== TEST VISITOR I AREA =====" << endl;

    // comprovam que inicialment no està dins cap àrea
    Visitor visitorTest("TestVisitor", 20);

    cout << "[Visitor] Àrea inicial: "
         << (visitorTest.getCurrentArea() == nullptr ? "nullptr" : "error")
         << endl;

    // movem el visitor a Mediterranea
    visitorTest.moveToArea(&area2);

    cout << "[Visitor] Àrea després de moure's: "
         << visitorTest.getCurrentArea()->getName()
         << endl;

    cout << "[Area] Mediterranea conté el visitor?: "
         << area2.hasVisitor("TestVisitor")
         << endl;

    // movem el visitor a Far West
    visitorTest.moveToArea(&area1);

    cout << "[Visitor] Àrea després del segon moviment: "
         << visitorTest.getCurrentArea()->getName()
         << endl;

    cout << "[Area] Far West conté el visitor?: "
         << area1.hasVisitor("TestVisitor")
         << endl;

    cout << "[Area] Mediterranea conté el visitor després de moure'l?: "
         << area2.hasVisitor("TestVisitor")
         << endl;


    // TEST RESERVATION

    cout << endl;
    cout << "===== TEST RESERVATION =====" << endl;

    Visitor visitorReservation("ReservationVisitor", 25);

    // creem una reserva per Furious Baco
    unique_ptr<Reservation> reservation1 =
        make_unique<Reservation>(1, &visitorReservation, &coaster1);

    visitorReservation.addReservation(std::move(reservation1));

    cout << "[Reservation] Nombre de reserves: "
        << visitorReservation.getReservations().size()
        << endl;

    cout << "[Reservation] Reserves actives: "
        << visitorReservation.getActiveReservationsCount()
        << endl;

    cout << "[Reservation] Té reserva activa per Furious Baco?: "
        << visitorReservation.hasActiveReservation(&coaster1)
        << endl;

    // cancel·lam la reserva
    visitorReservation.getReservations().at(0)->cancel();

    cout << "[Reservation] Reserves actives després de cancel·lar: "
        << visitorReservation.getActiveReservationsCount()
        << endl;

    cout << "[Reservation] Té reserva activa per Furious Baco després de cancel·lar?: "
        << visitorReservation.hasActiveReservation(&coaster1)
        << endl;
        
    return 0;
    
}