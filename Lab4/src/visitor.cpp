#include "Visitor.h"
#include "Ticket.h"
#include "Area.h"
#include "Reservation.h"
#include "Attraction.h"
#include <string>
#include <vector>

// crea un visitant amb nom i edat
Visitor::Visitor(std::string n, int a){
    this->name = n;

    if(a >= 0) {
        this->age = a;
    }
    else {
        this->age = 0; // si l'edat és negativa, la posem a 0
    }
}

// destructor del visitant
Visitor::~Visitor()
{
    if (currentArea != nullptr) {
        currentArea->removeVisitor(this);
    }

    // eliminam el visitant de les atraccions de les seves reserves
    for (const auto& reservation : reservations) {
        if (reservation != nullptr &&
            reservation->getAttraction() != nullptr) {

            reservation->getAttraction()->removeVisitor(this);
        }
    }
}

// retorna el nom del visitant
std::string Visitor::getName() const{
    return this->name;
}

// retorna l'edat del visitant
int Visitor::getAge() const{
    return this->age;
}

// modifica el nom del visitant
void Visitor::setName(std::string n){
    this->name = n;
}

// modifica l'edat si és vàlida
void Visitor::setAge(int a){
    if (a >= 0) this->age = a; // si l'edat és negativa, age no es modifica
}

// afegeix un ticket si el punter és vàlid
void Visitor::addTicket(Ticket* t){
    if (t != nullptr) { // comprovem que el punter apunti a alguna cosa
        tickets.push_back(t);
    }
}

// elimina un ticket segons el seu id
bool Visitor::removeTicket(Ticket t){
    // itera dins de tickets per trobar el que es vol esborrar
    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets.at(i) != nullptr &&
            tickets.at(i)->getId() == t.getId()) {

            tickets.erase(tickets.begin() + i);
            return true;
        }
    }

    return false;
}

// mou el visitant a una nova àrea
void Visitor::moveToArea(Area* area)
{
    // si ja estava dins una àrea, l'eliminam d'aquesta
    if (currentArea != nullptr) {
        currentArea->removeVisitor(this);
    }

    // actualitzam l'àrea actual
    currentArea = area;

    // si la nova àrea existeix, afegim el visitant
    if (currentArea != nullptr) {
        currentArea->addVisitor(this);
    }
}

// retorna l'àrea actual del visitant
Area* Visitor::getCurrentArea() const
{
    return currentArea;
}

// retorna el total gastat en tickets
double Visitor::getTotalSpent() const
{
    double total = 0.0;

    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets.at(i) != nullptr) {
            total += tickets.at(i)->getPrice();
        }
    }

    return total;
}

// retorna el nombre de tickets vàlids
int Visitor::getValidTicketsCount() const
{
    int count = 0;

    for (size_t i = 0; i < tickets.size(); i++) {
        if (tickets.at(i) != nullptr && tickets.at(i)->isValid()) {
            count++;
        }
    }

    return count;
}

// afegeix una reserva al visitant
void Visitor::addReservation(unique_ptr<Reservation> reservation)
{
    if (reservation != nullptr) {
        reservations.push_back(std::move(reservation));
    }
}

// retorna totes les reserves del visitant
const vector<unique_ptr<Reservation>>& Visitor::getReservations() const
{
    return reservations;
}

// retorna el nombre de reserves actives
int Visitor::getActiveReservationsCount() const
{
    int count = 0;

    for (const auto& reservation : reservations) {
        if (reservation != nullptr && reservation->isActive()) {
            count++;
        }
    }

    return count;
}

// comprova si el visitant té una reserva activa per una atracció
bool Visitor::hasActiveReservation(Attraction* attraction) const
{
    for (const auto& reservation : reservations) {
        if (reservation != nullptr &&
            reservation->isActive() &&
            reservation->getAttraction() == attraction) {
            return true;
        }
    }

    return false;
}