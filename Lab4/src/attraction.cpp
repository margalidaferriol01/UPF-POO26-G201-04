#include "Attraction.h"

Attraction::Attraction(string n, int cap, int dur, double price) {
    this->name = n;
    this->maxCapacity = (cap > 0) ? cap : 1;
    this->duration = (dur > 0) ? dur : 1;
    this->price = (price >= 0.0) ? price : 0.0;
    this->running = false; //comença aturada per defecte
}


//GETERS
string Attraction::getName() const {
    return this->name;
}

int Attraction::getMaxCapacity() const {
    return this->maxCapacity;
}

int Attraction::getDuration() const {
    return this->duration;
}

double Attraction::getPrice() const {
    return this->price;
}

bool Attraction::isPrepared() const {
    if(this->prepared == true) return true;
    else return false;
}


//SETTERS
void Attraction::setMaxCapacity(int cap) {
    if (cap > 0) {
        this->maxCapacity = cap;
    }
}

void Attraction::setDuration(int dur) {
    if (dur > 0) {
        this->duration = dur;
    }
}

void Attraction::setPrice(double price) {
    if (price >= 0.0) {
        this->price = price;
    }
}

void Attraction::start() {
    // verifiquem que estigui preparada abans d'iniciar-la
    if(this->prepared == true){
        this->running = true;
    }
}

void Attraction::stop() {
    // posem valors running i prepared a fals
    this->running = false;
    this->prepared = false;
}

bool Attraction::isRunning() const {
    return this->running;
}

void Attraction::setPrepare(bool b){
    this->prepared = b;
}