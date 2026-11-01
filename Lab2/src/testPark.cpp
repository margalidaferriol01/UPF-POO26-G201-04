#include <string>
#include <iostream>

#include "Area.h"
#include "Park.h"
#include "Ticket.h"
#include "Visitor.h"

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

    //TEST ATTRACTION
    Attraction attraction1("Dragon Khan", -10, 0, -5.0); //capacitat, durada i preu invàlids
    Attraction attraction2("Shambhala", 30, 3, 10.0);
    std::cout << "[Attraction] Nom: " << attraction1.getName() << std::endl;
    std::cout << "[Attraction] Capacitat corregida: " << attraction1.getMaxCapacity() << std::endl; //esperat: 1
    std::cout << "[Attraction] Durada corregida: " << attraction1.getDuration() << std::endl; //esperat: 1
    std::cout << "[Attraction] Preu corregit: " << attraction1.getPrice() << std::endl; //esperat: 0.0
    std::cout << "[Attraction] Estat inicial engegada: " << attraction1.isRunning() << std::endl;

    attraction1.start();
    std::cout << "[Attraction] Estat després d'engegar: " << attraction1.isRunning() << std::endl;
    attraction1.stop();
    std::cout << "[Attraction] Estat després d'aturar: " << attraction1.isRunning() << std::endl;

    std::cout << std::endl;

    //TEST AREA
    Area area1("Mediterrania", "Zona d'entrada");
    area1.addAttraction(attraction1);
    area1.addAttraction(attraction2);
    area1.addAttraction(attraction1); //intent de duplicat

    std::cout << "[Area] Eliminar atraccio existent: " << area1.removeAttraction("Dragon Khan") << std::endl; //esperat: true
    std::cout << "[Area] Eliminar atraccio inexistent: " << area1.removeAttraction("Hurakan Condor") << std::endl; //esperat: false

    std::cout << std::endl;

    //TEST PARK
    Park park1("PortAventura");
    park1.addArea(area1);
    std::cout << "[Park] Eliminar area existent: " << park1.removeArea("Mediterrania") << std::endl; //esperat: true
    std::cout << "[Park] Eliminar area inexistent: " << park1.removeArea("Far West") << std::endl; //esperat: false

    park1.addVisitor(visitor1);
    std::cout << "[Park] Eliminar visitant existent: " << park1.removeVisitor(visitor1) << std::endl; //esperat: true
    std::cout << "[Park] Eliminar visitant inexistent: " << park1.removeVisitor(visitor2) << std::endl; //esperat: false

    return 0;
}