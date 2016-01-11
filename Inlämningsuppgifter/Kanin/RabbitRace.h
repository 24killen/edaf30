#ifndef RABBITRACE_H
#define RABBITRACE_H
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Rabbit.h"
#include "Track.h"


class RabbitRace{

    public:
        RabbitRace(int nbrOfRabbits);
        virtual ~RabbitRace();
        bool advance(int nbrOfRounds);  //Moves all the rabbits nbrOfRounds times, returns false if noone has won.
        void printStandings();          //Skriver ut nuvarande ställning bland de tävlande.
        int getWinnerNbr();
    private:
        int winnerNbr;
        bool completed;
        std::vector<Rabbit*> rabbits;
};

#endif // RABBITRACE_H
