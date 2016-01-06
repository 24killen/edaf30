#include "Rabbit.h"

Rabbit::Rabbit(){       //Default
    rabbitNbr = 0;
    track =Track(1000);
    jumpForwardProbability = 40;
    stayProbability = 40;
    mini = 20;
    maxi = 40;
}

Rabbit::Rabbit(int nbr, Track course){
    rabbitNbr = nbr;
    track = course;
    jumpForwardProbability = 40;
    stayProbability = 40;
    mini = 20;
    maxi = 40;
}

Rabbit::~Rabbit(){

    //dtor
}

Rabbit::Rabbit(const Rabbit& other){
    //copy ctor
}

Rabbit& Rabbit::operator=(const Rabbit& rhs){
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Rabbit::setProbabilities(int stay, int jumpForward){
    stayProbability = stay;
    jumpForwardProbability = jumpForward;
}

void Rabbit::setMoveDistances(int minimum, int maximum){
    mini = minimum;
    maxi = maximum;
}

int Rabbit::getInterval(){
    srand((unsigned)time(0));
    return mini+rand()%(maxi-mini+1);        //Intervall 20-40 (default)
}

int Rabbit::movement(){
    int movement = 0;
    int choice = rand()%101;    //Intervall 0-100
    if(choice<=stayProbability){             //Stå still
        movement = 0;
    }else if(choice<=(stayProbability+jumpForwardProbability)){       //Hoppa frammåt
        movement = getInterval();
    }else{                      //Hoppa bakåt
        movement = getInterval();
        movement *=-1;
    }
    track.movement(movement);   //Flytta positionen
    return movement;
}

int Rabbit::getProgress(){
    return track.getCurrentPosition();
}

int Rabbit::getRabbitNbr(){
    return rabbitNbr;
}

bool Rabbit::hasWon(){
    return track.reachedGoal();
}
