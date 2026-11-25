#include "Reservation.h"

std::set<int> Reservation::usedIds;
int Reservation::nextAutoId = 1;

Reservation::Reservation(int id, Visitor* v, Attraction* a) {
    // garantim que l'ID sigui positiu i únic en tot el sistema
    if (id > 0 && usedIds.find(id) == usedIds.end()) {
        this->id = id;
    } 
    else {
        while (usedIds.find(nextAutoId) != usedIds.end()) {
            nextAutoId++;
        }
        this->id = nextAutoId++;
    }
    usedIds.insert(this->id);

    this->status = true; // comença activa per defecte
    this->visitor = v;
    this->attraction = a;
}

int Reservation::getId() const {
    return this->id;
}

bool Reservation::getStatus() const {
    return this->status;
}

void Reservation::cancel() {
    this->status = false; // una vegada cancel·lada, no es pot reactivar
}

bool Reservation::isActive() const {
    return this->status;
}

Visitor* Reservation::getVisitor() const {
    return this->visitor;
}

Attraction* Reservation::getAttraction() const {
    return this->attraction;
}