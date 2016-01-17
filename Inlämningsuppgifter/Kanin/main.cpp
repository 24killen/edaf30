#include <iostream>
#include "RabbitRace.h"
using namespace std;

int main(){

    bool goodEntry = false;
    int nbrOfRabbits = 1;

    cout<<"How many rabbits shall compete? Enter a number between 1-999: ";
    cin>>nbrOfRabbits;
    if(!(nbrOfRabbits>0&&nbrOfRabbits<1000)){
        nbrOfRabbits = 1;
        cout<<endl<<"Incorrect input. Number changed to value: "<<nbrOfRabbits<<endl;
    }

    RabbitRace rr = RabbitRace(nbrOfRabbits);

    bool raceFinished = false;
    int counter = 0;
    for(int i=0;i<1000&&!raceFinished;++i){
        cout<<"==== Round "<<i<<" ===="<<endl;
        raceFinished = rr.advance(1);
        rr.printStandings();
        counter = i+1;
    }
    cout<<"Duration: "<<counter<<" seconds."<<endl;
    int result = rr.getWinnerNbr();
    if(result == -1)
        cout<<"The race was closed after "<<counter<<" seconds.";
    else
        cout<<"Rabbit "<<result<<" has won!";
    return 0;
}
