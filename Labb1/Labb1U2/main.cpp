#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

unsigned long seed = time(0)*time(0);
srand(seed);

int randNbrs[6], lottNbr[6];
int vinst = 0;
char test[6];

cout << "Vinstnummer: ";

for(int i=0;i<=5;i++){
    randNbrs[i] = rand()%10;
    cout << randNbrs[i];
}
cout << endl;

cin.getline(test,6);

// Converts char to int
for(int i = 0; i<6; i++){
    lottNbr[i] = test[i] - '0';
}

//cout << lottNbr[3]<<endl;

for(int i = 0; i<6; i++){
    if(lottNbr[i] == randNbrs[i]){
        if(vinst == 0)
            vinst = 1;
        vinst*=10;
    }
    else
        break;
}


int threeNbrs = lottNbr[0]*100 + lottNbr[1]*10 + lottNbr[2];
for(int i=1;i<=3;i++){
    int temp = randNbrs[i]*100 + randNbrs[i+1]*10 + randNbrs[i+2];
    if(threeNbrs == temp){
        vinst+=250;
        break;
    }
}





cout << "Vinst: " << vinst << "kr" ;


return 0;
}
