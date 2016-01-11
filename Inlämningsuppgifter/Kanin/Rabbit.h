#ifndef RABBIT_H
#define RABBIT_H
#include "Track.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

class Rabbit{
    public:
        Rabbit ();
        Rabbit(int nbr, Track track);
        virtual ~Rabbit();
        Rabbit(const Rabbit& other);
        Rabbit& operator=(const Rabbit& other);
        bool operator<(Rabbit& other);
        bool operator==(Rabbit& other);
        void setProbabilities(int stay, int jumpForward);
        void setMoveDistances(int minimum, int maximum);
        int getInterval();      //Returns the lenght that the rabbit made.
        int movement();         //Returns the progress the rabbit made.
        int getProgress();      //Returns how much the rabbithas advanced in total.
        int getRabbitNbr();  //Returns the name of the rabbit.
        bool hasWon();
    protected:
    private:
        Track track;
        int rabbitNbr, stayProbability, jumpForwardProbability, mini, maxi;
};

#endif // RABBIT_H
