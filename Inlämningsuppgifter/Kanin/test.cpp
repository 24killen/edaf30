#include "test.h"
#include <iostream>


using namespace std;

test::test(){
    for(int j=0;j<3;++j){

    int nbrOfRabbits = 1;
    if(j==1)
        nbrOfRabbits =999;
    else if(j==2)
        nbrOfRabbits ='A';

    bool goodEntry = false;

    while(!goodEntry){
        cout<<"How many rabbits shall compete?";
//        cin>>nbrOfRabbits;
        if(nbrOfRabbits>0&&nbrOfRabbits<1000)
            goodEntry=true;
        else
            nbrOfRabbits = 0;
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
    cout<<nbrOfRabbits;
}
}
