#include "RabbitRace.h"
#include <algorithm>
#include <climits>

using namespace std;
RabbitRace::RabbitRace(int nbrOfRabbits){
    winnerNbr = -1;
    completed = false;
    for(int i=0;i<nbrOfRabbits;++i){
        Track t = Track(1000);                      //The track is 10m/1000cm long.
        Rabbit* r = new Rabbit(i+1,t);              //Given a number and a track.
        rabbits.push_back(r);
    }
}

RabbitRace::~RabbitRace(){
    for(unsigned int i=0;i<rabbits.size();++i)
        delete rabbits.at(i);
    delete &winnerNbr;
    delete &completed;
}

bool RabbitRace::advance(int nbrOfRounds){
    bool hasWon = false;
    for(unsigned int i=0;i<rabbits.size()&&!hasWon;++i){
        Rabbit* r = rabbits.at(i);
        r->movement();
        if((r->hasWon())){
            winnerNbr = r->getRabbitNbr();
            hasWon = true;
        }
    }
    return hasWon;
}
void RabbitRace::printStandings(){
    vector<int> shown;

    for(unsigned int i=0;i<rabbits.size();++i){
        pair<int, int> highest_nbr;
        highest_nbr.first = -1;
        highest_nbr.second = INT_MIN;

        for(unsigned int j=0;j<rabbits.size();++j){
            Rabbit* temp = rabbits.at(j);
            if(highest_nbr.second<(temp->getProgress())){
                bool beenshown = false;
                for(unsigned int k=0;k<shown.size();++k){
                    if(shown.at(k) == temp->getRabbitNbr())
                        beenshown = true;
                }
                if(!beenshown){
                    highest_nbr.first = temp->getRabbitNbr();
                    highest_nbr.second = temp->getProgress();
                }
            }
        }
        shown.push_back(highest_nbr.first);
        cout<<"Rabbit "<<highest_nbr.first<<" is at "<<highest_nbr.second<<endl;
    }
}

int RabbitRace::getWinnerNbr(){
    return winnerNbr;
}
