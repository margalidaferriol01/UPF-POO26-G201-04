#ifndef TICKET_H
#define TICKET_H

class Ticket {
    private:
        int id;
        double price;
        bool valid;
    public:
        Ticket(int id, double price);
        int getId();
        double getPrice();
        void invalidate();
        bool isValid();
};

#endif