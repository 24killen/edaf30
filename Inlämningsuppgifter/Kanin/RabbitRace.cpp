#include "RabbitRace.h"

using namespace std;
RabbitRace::RabbitRace(int nbrOfRabbits){
    winnerNbr = -1;
    completed = false;
    for(int i=0;i<nbrOfRabbits;++i){
        Track t = Track(1000);                      //The track is 10m/1000cm long.
        Rabbit* r = new Rabbit(i+1,t);                     //Given a number and a track.
        rabbits.push_back(r);
    }
}

RabbitRace::~RabbitRace(){
    //rabbits.clear();
}

bool RabbitRace::advance(int nbrOfRounds){
    bool hasWon = false;
    for(int i=0;i<rabbits.size()&&!hasWon;++i){
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
    for(int i=0;i<rabbits.size();++i){
        Rabbit* r = rabbits.at(i);
        for(int j=i+1;j<rabbits.size();++j){
            Rabbit* temp = rabbits.at(j);
        }
        cout<<"Rabbit "<<(r->getRabbitNbr())<<" is currently at "<<r->getProgress()<<endl;
    }
}

int RabbitRace::getWinnerNbr(){
    return winnerNbr;
}
