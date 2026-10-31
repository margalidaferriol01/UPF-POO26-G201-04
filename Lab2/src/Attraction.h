#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>
using namespace std;

class Attraction {
private:
    string name;
    int maxCapacity;
    int duration;
    double price;
    bool running;

public:

    Attraction(string n, int cap, int dur, double price);

    //getters
    string getName() const;
    int getMaxCapacity() const;
    int getDuration() const;
    double getPrice() const;

    //setters
    void setMaxCapacity(int cap);
    void setDuration(int dur);
    void setPrice(double price);

    void start();
    void stop();
    bool isRunning() const;
};

#endif