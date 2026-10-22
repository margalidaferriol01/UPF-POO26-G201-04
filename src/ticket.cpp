#include "Ticket.h"

Ticket::Ticket(int id, double price){
    this->id = id;
    this->price = price;
    valid = true;
}

int Ticket::getId(){
    return this->id; // retornem id
}

double Ticket::getPrice(){
    return this->price; // retornem preu
}

void Ticket::invalidate(){
    this->valid = false; // forçem que s'invalidi
}

bool Ticket::isValid(){
    return this->valid;
}