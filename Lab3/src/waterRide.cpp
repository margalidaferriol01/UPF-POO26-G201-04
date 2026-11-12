#include "WaterRide.h"

WaterRide::WaterRide(string n, int cap, int dur,
                     double price, double minHeight)
    : Attraction(n, cap, dur, price)
{
    if (minHeight >= 0.0) {
        this->minHeight = minHeight;
    }
    else {
        this->minHeight = 0.0; // si l'altura és negativa, la posam a 0
    }
}

bool WaterRide::prepareWaterPump()
{
    return true; // preparam la bomba
}

double WaterRide::getMinHeight() const
{
    return this->minHeight; // retornam altura minima
}

void WaterRide::setMinHeight(double height)
{
    if (height >= 0.0) {
        this->minHeight = height;
    }
}

bool WaterRide::isVisitorAllowed(double visitorHeight) const
{
    return visitorHeight >= this->minHeight; // comprovam si pot pujar
}

void WaterRide::prepare()
{
    if (prepareWaterPump()) {
        start(); // si la bomba funciona, engegam l'atracció
    }
}