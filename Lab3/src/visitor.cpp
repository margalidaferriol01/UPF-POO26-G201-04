#include "Visitor.h"
#include "Ticket.h"
#include <string>
#include <vector>

Visitor::Visitor(std::string n, int a){
    this->name = n;

    if(a>=0) this->age = a; 
    else this->age = 0; // si l'edat és negativa, la posem a 0
}

std::string Visitor::getName()const{
    return this->name;
}

int Visitor::getAge()const{
    return this->age;
}

void Visitor::setName(std::string n){
    this->name = n;
}

void Visitor::setAge(int a){
    if (a>=0) this->age = a; // si l'edat a és negativa, age no es modifica
}

void Visitor::addTicket(Ticket t){
    tickets.push_back(t);
}

bool Visitor::removeTicket(Ticket t){
    // itera dins de <tickets> per trobar el que es vol esborrar
    for (size_t i = 0; i < tickets.size(); i++) {
        if(tickets.at(i).getId() == t.getId()) { // utilitzem l'id dels tickets per diferenciar-los
            tickets.erase(tickets.begin() + i); // tickets.begin apunta a la primera posició del vector
            return true;
        }
    }
    return false;
}

void Visitor::moveToArea(string areaName)
{
    currentArea = areaName;
}

string Visitor::getCurrentArea() const
{
    return currentArea;
}

double Visitor::getTotalSpent() const
{
    double total = 0.0;

    for (size_t i = 0; i < tickets.size(); i++) {
        total += tickets.at(i).getPrice();
    }

    return total;
}

int Visitor::getValidTicketsCount() const
{
    int count = 0;

    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets.at(i).isValid()) {
            count++;
        }
    }

    return count;
}