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

void Park::addArea(Area area) {
    this->areas.push_back(area);
}

bool Park::removeArea(string name) {
    for (auto it = this->areas.begin(); it != this->areas.end(); ++it) {
        if (it->getName() == name) {
            this->areas.erase(it);
            return true;
        }
    }
    return false; // Retorna false si l'àrea no existeix al parc
}

void Park::addVisitor(Visitor visitor) {
    this->visitors.push_back(visitor);
}

bool Park::removeVisitor(Visitor visitor) {
    for (auto it = this->visitors.begin(); it != this->visitors.end(); ++it) {
        if (it->getName() == visitor.getName() && it->getAge() == visitor.getAge()) {
            this->visitors.erase(it);
            return true;
        }
    }
    return false; // Retorna false si el visitant no està registrat
}