#include "RollerCoaster.h"

RollerCoaster::RollerCoaster(std::string n, int cap, int dur, 
                            double price, double speed, int loops): 
                            Attraction(n, cap, dur, price)
{
    if(loops>=0) this->loops = loops;
        else this->loops = 0; // si el valor no es pot acceptar, loops = 0
    if(speed>0) this-> maxSpeed = speed;   
        else this->maxSpeed = 1.0; // si la velocitat no té sentit, la posem a 1
}

double RollerCoaster::getMaxSpeed(){
    return this->maxSpeed; 
}

int RollerCoaster::getLoops(){
    return this->loops;
}

void RollerCoaster::setMaxSpeed(double speed){
    if(speed>0.0) this->maxSpeed = speed; // comprovem que speed sigui major que zero
}

void RollerCoaster::setLoops(int loops){
    if(loops>=0) this->loops = loops; // comprovem que loops sigui major o igual a 0
}

void RollerCoaster::checkSafetySystem(){
    
}

bool RollerCoaster::isExtremeCoaster(){
    if(maxSpeed > 80.0 || loops > 2) return true; // comprovem maxspeed major que 80 i loops majors que 2 amb un OR
    else return false;
}