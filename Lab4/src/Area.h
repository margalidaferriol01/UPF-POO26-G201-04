#ifndef AREA_H
#define AREA_H

#include <string>
#include <vector>
#include "Attraction.h"
using namespace std;

class Visitor; // afegim la classe Visitor per així no haver d'incloure el .h corresponent
class Area {
private:
    string name;
    string description;
    vector<Attraction*> attractions;
    vector<Visitor*> visitors;

public:
    Area(string name, string description);

    //getters i setters
    string getName() const;
    string getDescription() const;
    void setDescription(string d);

    //mètodes de gestió d'atraccions
    void addAttraction(Attraction* a);
    bool removeAttraction(string name);

    //mètodes de gestió de visitants
    void addVisitor(Visitor* visitor);
    bool removeVisitor(Visitor* visitor);
    const vector<Visitor*>& getVisitors() const;
    int getVisitorsCount() const;
    bool hasVisitor(string visitorName) const;

    //extensió 6.2 lab 3
    int getRunningAttractionsCount();
    bool hasAttraction(string name);
    int getTotalAreaAttractionsCount();
};

#endif