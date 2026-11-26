#include "Park.h"

Park::Park(string name) {
    this->name = name;
}

Park::~Park() = default;

string Park::getName() const {
    return this->name;
}

void Park::setName(string name) {
    this->name = name;
}

void Park::addArea(Area *area) {
    this->areas.push_back(area);
}

bool Park::removeArea(string name) {
    // auto decideix sol el tipus de la variable
    for (auto i = areas.begin(); i != areas.end(); ++i) {
        if (*i != nullptr && (*i)->getName() == name) {
            areas.erase(i);  // eliminem la àrea
            return true;
        }
    }

    return false; // si l'àrea no existeix al parc
}

void Park::addVisitor(Visitor* visitor)
{
    if (visitor != nullptr) {
        this->visitors.push_back(visitor);
    }
}

bool Park::removeVisitor(Visitor* visitor)
{
    for (auto it = visitors.begin(); it != visitors.end(); ++it) {
        if (*it == visitor) {
            visitors.erase(it);
            return true;
        }
    }

    return false; // si el visitant no està registrat
}

int Park::getTotalAttractions(){
    int count = 0;
    // anem sumant el nombre d'atraccions que té cada àrea
    for(size_t i=0; i<areas.size(); i++){
        count+=areas.at(i)->getTotalAreaAttractionsCount();
    }
    return count;
}

bool Park::isVisitorRegistered(string name)
{
    for (size_t i = 0; i < visitors.size(); i++) {
        if (visitors.at(i) != nullptr &&
            visitors.at(i)->getName() == name) {
            return true;
        }
    }

    return false;
}