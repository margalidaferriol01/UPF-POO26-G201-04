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
    bool prepared;

public:

    Attraction(string n, int cap, int dur, double price);

    //getters
    string getName() const;
    int getMaxCapacity() const;
    int getDuration() const;
    double getPrice() const;
    bool isPrepared() const;

    //setters
    void setMaxCapacity(int cap);
    void setDuration(int dur);
    void setPrice(double price);

    void start();
    void stop();
    bool isRunning() const;

    void setPrepare(bool b);

    // mètode abstracte (prepare)
    virtual void prepare() = 0;
    virtual ~Attraction() = default; // destructor

};

#endif