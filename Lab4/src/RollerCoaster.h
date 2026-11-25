#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include "Attraction.h"

class RollerCoaster : public Attraction{
    private:
        double maxSpeed;
        int loops;
    public:
        RollerCoaster(std::string n, int cap, int dur, 
            double price, double speed, int loops);
        double getMaxSpeed();
        int getLoops();
        void setMaxSpeed(double speed);
        void setLoops(int loops);
        void checkSafetySystem();
        bool isExtremeCoaster();

        void prepare() override;
};

#endif