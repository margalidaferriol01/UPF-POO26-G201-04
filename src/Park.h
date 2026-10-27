#ifndef PARK_H
#define PARK_H

#include <string>
#include <vector>
#include "Area.h"
#include "Visitor.h"

using namespace std;

class Park {
private:
    string name;
    vector<Area> areas;
    vector<Visitor> visitors;

public:
    Park(string name);
    ~Park();

    string getName() const;
    void setName(string name);

    void addArea(Area area);
    bool removeArea(string name);

    void addVisitor(Visitor visitor);
    bool removeVisitor(Visitor visitor);
};

#endif