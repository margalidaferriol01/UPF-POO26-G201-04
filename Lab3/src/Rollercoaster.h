#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include <string>
#include "Attraction.h"

class Rollercoaster : public Attraction{
    private:
        double maxSpeed;
        int loops;
    public:
        Rollercoaster(std::string n, int cap, int dur, 
            double price, double speed, int loops);
        double getMaxSpeed();
        int getLoops();
        void setMaxSpeed(double speed);
        void setLoops(int loops);
        void checkSafetySystem();
        bool isExtremeCoaster();
};

#endif