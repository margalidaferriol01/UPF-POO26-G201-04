#ifndef RESERVATION_H
#define RESERVATION_H

#include <set>

class Visitor;
class Attraction;

class Reservation {
private:
    int id;
    bool status; // true = actiu, false = cancel·lat
    Visitor* visitor;
    Attraction* attraction;

    static std::set<int> usedIds;
    static int nextAutoId;

public:
    Reservation(int id, Visitor* v, Attraction* a);

    int getId() const;
    bool getStatus() const;
    void cancel();
    bool isActive() const;
    Visitor* getVisitor() const;
    Attraction* getAttraction() const;
};

#endif