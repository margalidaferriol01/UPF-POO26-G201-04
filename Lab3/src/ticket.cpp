#include "Ticket.h"

Ticket::Ticket(int id, double price){
    this->id = id;
    
    if(price>=0) this->price = price;
    else this -> price = 0.0; // si el preu és negatiu, el posem a 0

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