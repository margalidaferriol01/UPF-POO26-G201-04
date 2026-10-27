#include "Area.h"

Area::Area(string name, string description) {
    this->name = name;
    this->description = description;
}

string Area::getName() const {
    return this->name;
}

string Area::getDescription() const {
    return this->description;
}

void Area::setDescription(string d) {
    this->description = d;
}

void Area::addAttraction(Attraction a) {
    // Comprovar si l'atracció ja existeix per evitar duplicats
    for (const auto& attr : this->attractions) {
        if (attr.getName() == a.getName()) {
            return; // Ja existeix, no la tornem a afegir
        }
    }
    this->attractions.push_back(a);
}

bool Area::removeAttraction(string name) {
    for (auto it = this->attractions.begin(); it != this->attractions.end(); ++it) {
        if (it->getName() == name) {
            this->attractions.erase(it);
            return true;
        }
    }
    return false; // Retorna false si l'atracció no hi era
}