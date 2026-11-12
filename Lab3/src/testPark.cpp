#include <string>
#include <iostream>

#include "Area.h"
#include "Park.h"
#include "Ticket.h"
#include "Visitor.h"
#include "WaterRide.h"

int main() {
    //mostra els valors booleans com 'true' / 'false' en lloc de 1 / 0
    std::cout << std::boolalpha;

    //TEST TICKET
    Ticket ticket1(125, 8); //ID=125
    std::cout << "[Ticket] Ticket 1 price: " << ticket1.getPrice() << std::endl;
    std::cout << "[Ticket] Ticket validation: " << ticket1.isValid() << std::endl;
    ticket1.invalidate();
    std::cout << "[Ticket] Ticket invalidation: " << ticket1.isValid() << std::endl;

    Ticket ticket2(150, -5); //ID:150, preu negatiu
    std::cout << "[Ticket] Ticket 2 price: " << ticket2.getPrice() << std::endl; //esperat: 0.0

    std::cout << std::endl;

    //TEST VISITOR
    Visitor visitor1("Peppa", 86);
    visitor1.addTicket(ticket2); //associem un tiquet al visitant
    std::cout << "[Visitor] Visitor name: " << visitor1.getName() << "\n[Visitor] Visitor age: " << visitor1.getAge() << std::endl;
    std::cout << "[Visitor] Eliminar tiquet inexistent: " << visitor1.removeTicket(ticket1) << std::endl; //esperat: false
    std::cout << "[Visitor] Eliminar tiquet existent: " << visitor1.removeTicket(ticket2) << std::endl; //esperat: true

    Visitor visitor2("Peppo", -93); //visitor amb edat negativa
    std::cout << "[Visitor] Visitor name: " << visitor2.getName() << "\n[Visitor] Visitor age: " << visitor2.getAge() << std::endl; //esperat: 0

    std::cout << std::endl;

    // TEST WATER RIDE
    WaterRide attraction1("Dragon Khan", -10, 0, -5.0, 120.0);
    WaterRide attraction2("Shambhala", 30, 3, 10.0, 130.0);

    std::cout << "[WaterRide] Nom: "
            << attraction1.getName() << std::endl;

    std::cout << "[WaterRide] Capacitat corregida: "
            << attraction1.getMaxCapacity() << std::endl;

    std::cout << "[WaterRide] Durada corregida: "
            << attraction1.getDuration() << std::endl;

    std::cout << "[WaterRide] Preu corregit: "
            << attraction1.getPrice() << std::endl;

    std::cout << "[WaterRide] Altura minima: "
            << attraction1.getMinHeight() << std::endl;

    std::cout << "[WaterRide] Estat inicial engegada: "
            << attraction1.isRunning() << std::endl;

    attraction1.prepare();

    std::cout << "[WaterRide] Estat despres de prepare(): "
            << attraction1.isRunning() << std::endl;

    std::cout << "[WaterRide] Visitant de 130cm permès: "
          << attraction1.isVisitorAllowed(130.0) << std::endl; // esperat: true

    std::cout << "[WaterRide] Visitant de 100cm permès: "
            << attraction1.isVisitorAllowed(100.0) << std::endl; // esperat: false

    attraction1.setMinHeight(150.0);

    std::cout << "[WaterRide] Altura minima modificada: "
            << attraction1.getMinHeight() << std::endl; // esperat: 150

    std::cout << "[WaterRide] Visitant de 150cm permès: "
            << attraction1.isVisitorAllowed(150.0) << std::endl; // esperat: true

    std::cout << "[WaterRide] Visitant de 140cm permès: "
            << attraction1.isVisitorAllowed(140.0) << std::endl; // esperat: false
}