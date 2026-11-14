#include "Simulator.h"

Simulator::Simulator(string n, int cap, int dur, double price,
                     string type, int intensity)
    : Attraction(n, cap, dur, price)
{
    simulationType = type;

    if (intensity >= 0 && intensity <= 10)
        motionIntensity = intensity;
    else
        motionIntensity = 0; // si la intensitat és invàlida, la posam a 0
}

string Simulator::getSimulationType() const
{
    return simulationType; // retornam el tipus de simulació
}

int Simulator::getMotionIntensity() const
{
    return motionIntensity; // retornam la intensitat
}

void Simulator::setSimulationType(string type)
{
    simulationType = type; // actualitzam el tipus
}

void Simulator::setMotionIntensity(int intensity)
{
    if (intensity >= 0 && intensity <= 10)
        motionIntensity = intensity;
}

void Simulator::resetSimulation()
{
    stop(); // reiniciam el simulador aturant-lo
}

bool Simulator::isHighIntensity() const
{
    return motionIntensity >= 7; // és intens si és 7 o més
}

void Simulator::prepare()
{
    resetSimulation(); // preparam el simulador abans d'una nova sessió
}