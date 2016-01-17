#include "Track.h"
#include <iostream>



Track::Track(const Track& other){
    //copy ctor
}

Track& Track::operator=(const Track& rhs){
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int Track::getCurrentPosition(){
    return position;
}

bool Track::reachedGoal(){
    return (position>=lenght);
}

void Track::movement(int nbrOfSteps){
    position =  position + nbrOfSteps;
}
