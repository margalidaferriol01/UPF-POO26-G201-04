#include "Attraction.h"

Attraction::Attraction(string n, int cap, int dur, double price) {
    this->name = n;
    this->maxCapacity = (cap > 0) ? cap : 1;
    this->duration = (dur > 0) ? dur : 1;
    this->price = (price >= 0.0) ? price : 0.0;
    this->running = false; //comença aturada per defecte
}

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

void Attraction::setMaxCapacity(int cap) {
    this->maxCapacity = cap;
}

void Attraction::setDuration(int dur) {
    this->duration = dur;
}

void Attraction::setPrice(double price) {
    this->price = price;
}

void Attraction::start() {
    this->running = true;
}

void Attraction::stop() {
    this->running = false;
}

bool Attraction::isRunning() const {
    return this->running;
}