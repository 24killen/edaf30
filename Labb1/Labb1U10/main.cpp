//  main.cpp
//  Programmeringskurs
//
//  Created by Simon Lerpard and Artur Hellberg on 2015-11-09.
//  Copyright © 2015 Simon Lerpard. All rights reserved.

#include <iostream>

using namespace std;

int main(){

    int currentValue = 0, lastValue = 0, sum = 0;
    string input;
    cin >> input;

    for(int i = 0; i < input.size(); i++){
        switch(input[i]){
            case 'M':
                currentValue = 1000;
                break;
            case 'D':
                currentValue = 500;
                break;
            case 'C':
                currentValue = 100;
                break;
            case 'L':
                currentValue = 50;
                break;
            case 'X':
                currentValue = 10;
                break;
            case 'V':
                currentValue = 5;
                break;
            case 'I':
                currentValue = 1;
                break;
            default:
                currentValue = 0;
                cout << "Syntax error, your input are not correct. [" << input[i] << "]" << endl;
        }

        if(currentValue>lastValue && lastValue != 0){
            sum -= (lastValue*2);
        }
        sum += currentValue;

        /* Debug info
        cout << "current: " << currentValue << endl;
        cout << "last: " << lastValue << endl;
        cout << "sum: " << sum << endl;
        cout << "--------------------" << endl;
        */

        lastValue = currentValue;
    }
    cout << endl;
    cout << "Roman number: " << input << endl;
    cout << "Arabic number: "<< sum << endl << endl;

}
