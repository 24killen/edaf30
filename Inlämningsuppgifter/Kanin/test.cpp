#include "test.h"
#include <iostream>


using namespace std;

test::test(){
    for(int j=0;j<3;++j){   //The test-part.
    int nbrOfRabbits = 0;
    if(j==1)
        nbrOfRabbits = 999;
    else if(j==2)
        nbrOfRabbits ='A';

    bool goodEntry = false;
        //Here starts the original main-method.
        cout<<"How many rabbits shall compete? Enter a number between 1-999: ";
//        cin>>nbrOfRabbits;
        if(nbrOfRabbits>0&&nbrOfRabbits<1000)
            goodEntry=true;
        else{
            nbrOfRabbits = 1;
            cout<<endl<<"Incorrect input. Number changed to value: "<<nbrOfRabbits<<endl;
        }

    if(!goodEntry){

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
}
}
