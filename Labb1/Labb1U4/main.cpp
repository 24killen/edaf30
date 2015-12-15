#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;

int main()
{

    ifstream f1("infilU4.txt");

    int input = 0;
    int maxInput = 0, minInput = INT_MAX, mid = 0, sum = 0, counter = 0;


    f1 >> input;
    while(input >= 0){


        if(minInput > input){
            minInput = input;
        }
        if(maxInput < input) {
           maxInput = input;
        }
        counter++;
        sum = sum + input;

        f1 >> input;
    }
    f1.close();
    sum = sum - (maxInput+minInput);
    counter -= 2;

    mid = sum/counter;

    cout << "Medel: " << mid << endl;
    cout << "Min: " << minInput << endl;
    cout << "Max: " << maxInput << endl;
    cout << "Sum: " << sum << endl;
    cout << "Counter: " << counter << endl;


    return 0;
}
