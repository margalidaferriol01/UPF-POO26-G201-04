#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector>
#include "Attraction.h"
using namespace std;

class Area {
private:
    string name;
    string description;
    vector<Attraction> attractions;

public:
    Area(string name, string description);

    // Getters i Setters
    string getName() const;
    string getDescription() const;
    void setDescription(string d);

    // Mètodes de gestió d'atraccions
    void addAttraction(Attraction a);
    bool removeAttraction(string name);
};

#endif