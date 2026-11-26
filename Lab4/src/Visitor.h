#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <vector>
#include <memory> // afegim per poder fer servir unique_ptr

#include "Ticket.h" 

using namespace std;

// afegim les classes per així no haver d'incloure els .h corresponents
class Area;
class Reservation;
class Attraction;

class Visitor {
    private:
        string name;
        int age;
        vector<Ticket*> tickets;
        Area* currentArea = nullptr; // això significa que inicialment el visitant no està dins cap àrea
        vector<unique_ptr<Reservation>> reservations; // afegim les reserves com a vector de punters únics a Reservation

    public:
        Visitor(string n, int a);
        ~Visitor(); // destructor del visitor

        string getName() const;
        int getAge() const;

        void setName(string n);
        void setAge(int a);

        void addTicket(Ticket* t);
        bool removeTicket(Ticket t);

        void moveToArea(Area* area);
        Area* getCurrentArea() const;

        double getTotalSpent() const;
        int getValidTicketsCount() const;

        void addReservation(unique_ptr<Reservation> reservation);
        const vector<unique_ptr<Reservation>>& getReservations() const;
        int getActiveReservationsCount() const;
        bool hasActiveReservation(Attraction* attraction) const;
};

#endif
