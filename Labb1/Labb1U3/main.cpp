#include <iostream>
#include <limits.h>
using namespace std;

int main()
{

    int input = 0;
    int maxInput = 0, minInput = INT_MAX, mid = 0, sum = 0, counter = 0;
    cout << "Mata in poäng: ";
    cin >> input;
    cout << endl;
    while(input >= 0){


        if(minInput > input){
            minInput = input;
        }
        if(maxInput < input) {
           maxInput = input;
        }
        counter++;
        sum = sum + input;

        cout << "Mata in poäng: ";
        cin >> input;
        cout << endl;
    }

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
