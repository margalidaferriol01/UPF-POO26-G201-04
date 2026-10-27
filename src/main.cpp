#include <string>
#include <iostream>

#include "Area.h"
#include "Park.h"
#include "Ticket.h"
#include "Visitor.h"
#include "Attraction.h"


int main(){
    //TEST ATTRACTION/AREA/PARK:
    Attraction attraction1("Dragon Khan", -10, 0, -5.0); //capacitat, durada i preu invàlids
    cout << "Attraction name: " << attraction1.getName() << endl;
    cout << "Max Capacity: " << attraction1.getMaxCapacity() << endl; //comprovem que s'hagi posat a 1
    cout << "Duration: " << attraction1.getDuration() << endl; //comprovem que s'hagi posat a 1
    cout << "Price: " << attraction1.getPrice() << endl; //comprovem que s'hagi posat a 0.0
    cout << "Is running: " << attraction1.isRunning() << endl; //comprovem que estigui aturada

    attraction1.start();
    cout << "Is running after start: " << attraction1.isRunning() << endl; //comprovem que s'engegui

    Area area1("Mediterrània", "Zona d'entrada");
    area1.addAttraction(attraction1);
    area1.addAttraction(attraction1); //intentem afegir duplicat

    cout << "Remove attraction status: " << area1.removeAttraction("Dragon Khan") << endl; //esperem 1 (true)
    cout << "Remove attraction status (inexistent): " << area1.removeAttraction("Shambhala") << endl; //esperem 0 (false)

    Park park1("PortAventura");
    park1.addArea(area1);
    cout << "Remove area status: " << park1.removeArea("Mediterrània") << endl; //esperem 1 (true)
    cout << "Remove area status (inexistent): " << park1.removeArea("Polynesia") << endl; //esperem 0 (false)

    Visitor visitor3("Peppa", 86);
    Visitor visitor4("Peppo", -93);

    park1.addVisitor(visitor3);
    cout << "Remove visitor status: " << park1.removeVisitor(visitor3) << endl; //esperem 1 (true)
    cout << "Remove visitor status (inexistent): " << park1.removeVisitor(visitor4) << endl; //esperem 0 (false)
    return 0;


    //TEST TICKET/VISITOR:
    Ticket ticket1(125, 8); // ID=125
    std::cout << ticket1.isValid() << std::endl; //testegem que sigui vàlid
    ticket1.invalidate();
    std::cout << ticket1.isValid() << std::endl; //comprovem que s'hagi invalidat

    Ticket ticket2(150, -5); //ID:150, preu negatiu
    std::cout <<ticket2.getPrice() << std::endl; //comprovem que el preu s'hagi posat a 0.0

    Visitor visitor1("Peppa", 86);
    std::cout << "Visitor name: " << visitor1.getName() << "\nVisitor age: " << visitor1.getAge() << std::endl;

    Visitor visitor2("Peppo", -93); //visitor amb edat negativa
    std::cout << "Visitor name: " << visitor2.getName() << "\nVisitor age: " << visitor2.getAge() << std::endl;

}