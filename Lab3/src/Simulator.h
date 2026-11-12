#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Attraction.h"
#include <string>   

using namespace std;

class Simulator : public Attraction {
private:
    string simulationType;
    int motionIntensity;

public:
    Simulator(string n, int cap, int dur, double price,
              string type, int intensity);

    string getSimulationType() const;
    int getMotionIntensity() const;

    void setSimulationType(string type);
    void setMotionIntensity(int intensity);

    void resetSimulation();
    bool isHighIntensity() const;

    void prepare() override;
};

#endif