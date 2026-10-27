#include "Attraction.h"

Attraction::Attraction(string n, int cap, int dur, double price) {
    this->name = n;
    this->maxCapacity = cap;
    this->duration = dur;
    this->price = price;
    this->running = false; // Comença aturada per defecte
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