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

void Area::addAttraction(Attraction* a) {

    // comprovar si l'atracció ja existeix per evitar duplicats
    for (const auto& attr : this->attractions) {
        if (attr->getName() == a->getName()) {
            return;
        }
    }

    this->attractions.push_back(a);
}

bool Area::removeAttraction(string name) {

    for (auto it = this->attractions.begin();
         it != this->attractions.end();
         ++it) {

        if ((*it)->getName() == name) {
            this->attractions.erase(it);
            return true;
        }
    }

    return false;
}

int Area::getRunningAttractionsCount(){
    int count = 0;
    // size_t és un enter sense signe
    for(size_t i = 0; i<attractions.size(); i++){ // iterem tots els elements del vector
        // si la atracció està corrent, sumem 1 al contador
        if(attractions.at(i)->isRunning() == true) count++;
    }
    return count;
}

bool Area::hasAttraction(string name){
    for(size_t i = 0; i<attractions.size(); i++){ // iterem tots els elements del vector
        // si un coincideix, retornem true
        if(attractions.at(i)->getName() == name) return true; 
    }
    return false; // si no se-n'ha trobat cap que coincideixi
}

int Area::getTotalAreaAttractionsCount(){
    return attractions.size();
}