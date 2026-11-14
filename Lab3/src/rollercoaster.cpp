#include "Rollercoaster.h"

Rollercoaster::Rollercoaster(std::string n, int cap, int dur, 
                            double price, double speed, int loops): 
                            Attraction(n, cap, dur, price)
{
    if(loops>=0) this->loops = loops;
        else this->loops = 0; // si el valor no es pot acceptar, loops = 0
    if(speed>0) this-> maxSpeed = speed;   
        else this->maxSpeed = 0.0; // si la velocitat no té sentit, la posem a zero
}

double Rollercoaster::getMaxSpeed(){
    return this->maxSpeed;
}

int Rollercoaster::getLoops(){
    return this->loops;
}

void Rollercoaster::setMaxSpeed(double speed){
    if(speed>0.0) this->maxSpeed = speed;
}

void Rollercoaster::setLoops(int loops){
    if(loops>=0) this->loops = loops;
}

void Rollercoaster::checkSafetySystem(){
    
}

bool Rollercoaster::isExtremeCoaster(){
    if(maxSpeed > 80.0 | loops > 2) return true;
    else return false;
}