#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ifstream f1("test1.txt");
    double zero, control, space, normal, other, twoFiveFive, counter;
    zero = control = space = normal = other = twoFiveFive = counter = 0;
    char currentChar;
    while(f1.get(currentChar)){
        int nbr = (int)currentChar;
        if(nbr==0)
            ++zero;
        else if(nbr==255)
            ++twoFiveFive;
        else if(nbr==32)
            ++space;
        else if(nbr<128 && nbr>32)
            ++normal;
        else if(nbr>127 && nbr<255)
            ++other;
        else
            ++control;
        ++counter;
    }
    cout<<"Kod\t%"<<endl;
    double result = zero/counter;
    cout<<"0:\t"<<result<<endl;
    result = control/counter*100;
    cout<<"1-31:\t"<<result<<endl;
    result = space/counter*100;
    cout<<"32:\t"<<result<<endl;
    result = normal/counter*100;
    cout<<"33-127:\t"<<result<<endl;
    result = other/counter*100;
    cout<<"128-254:"<<result<<endl;
    result = twoFiveFive/counter*100;
    cout<<"255:\t"<<result<<endl;
    f1.close();

    return 0;
}
