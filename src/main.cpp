#include <string>
#include <iostream>

#include "Area.h"
#include "Park.h"
#include "Ticket.h"
#include "Visitor.h"


int main(){
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