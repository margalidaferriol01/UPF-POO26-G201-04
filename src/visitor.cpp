#include "Visitor.h"
#include "Ticket.h"
#include <string>
#include <vector>

Visitor::Visitor(std::string n, int a){
    this->name = n;
    this->age = a;
}

std::string Visitor::getName(){
    return this->name;
}

int Visitor::getAge(){
    return this->age;
}

void Visitor::setName(std::string n){
    this->name = n;
}

void Visitor::setAge(int a){
    this->age = a;
}

void Visitor::addTicket(Ticket t){
    tickets.push_back(t);
}

bool Visitor::removeTicket(Ticket t){
    // itera dins de <tickets> per trobar el que es vol esborrar
    for(int i = 0; i<tickets.size(); i++){
        if(tickets.at(i).getId() == t.getId()) { // utilitzem l'id dels tickets per diferenciar-los
            tickets.erase(tickets.begin() + i); // tickets.begin apunta a la primera posició del vector
            return true;
        }
    }
    return false;
}