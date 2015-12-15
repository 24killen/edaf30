#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    string valid = "inkorrekt";

    if(input[0]>='A' && input[1]>='A' && input[2]>='A'
       && input[0]<='Z' && input[1]<='Z' && input[2]<='Z'
       && input[3]>='0' && input[4]>='0' && input[5]>='0'
       && input[3]<='9' && input[4]<='9' && input[5]<='9'
       && input.size() == 6){
            valid = "korrekt";
    }

    cout << "Registreringsnumret är " << valid << endl;

    return 0;
}
