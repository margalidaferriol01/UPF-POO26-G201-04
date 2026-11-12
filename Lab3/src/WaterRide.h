#ifndef WATERRIDE_H
#define WATERRIDE_H

#include "Attraction.h"

class WaterRide : public Attraction {
private:
    double minHeight; // altura minima per pujar

public:
    WaterRide(string n, int cap, int dur, double price, double minHeight);

    bool prepareWaterPump(); // prepara la bomba
    double getMinHeight() const; // retornam altura minima
    void setMinHeight(double height); // canviam altura minima
    bool isVisitorAllowed(double visitorHeight) const; // comprovam si pot pujar

    void prepare() override; // preparam l'atracció
};

#endif