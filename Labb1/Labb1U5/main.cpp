#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    unsigned long seed = time(0)*time(0);
    srand(seed);

   // rand 1, 2 eller 3
   int randNbr = rand() % 3+1;
   string valtext;

   switch(randNbr){
case 1: valtext = "STEN";
    break;
case 2: valtext = "SAX";
    break;
case 3: valtext = "P�SE";
    break;
   }

    int anvVal;
    string anvText;
    cout << "Sten, sax eller p�se? Svara med 1, 2 eller 3.";
    cin >> anvVal;

    switch(anvVal){
case 1: anvText = "STEN";
    break;
case 2: anvText = "SAX";
    break;
case 3: anvText = "P�SE";
    break;
    }
    string vinnare = "Datorn (" + valtext + ")";

   if((anvVal == 1 && randNbr != 3) ||
      (anvVal == 2 && randNbr != 1) ||
      (anvVal == 3 && randNbr != 2))
        vinnare = "Anv�ndaren (" + anvText +")";
    else if(anvVal == randNbr)
        vinnare = "Lika";

cout << vinnare << endl;
}
