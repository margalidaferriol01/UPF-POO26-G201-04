#ifndef VISITOR_H
#define VISITOR_H


class Visitor {
    private:
        std::string name;
        int age;
        std::vector <Ticket> tickets;
    public:
        Visitor(std::string name, int age);
        std::string getName();
        int getAge();
        void setName(std::string n);
        void setAge(int a);
        void addTicket(Ticket t);
        bool removeTicket(Ticket t);
};

#endif