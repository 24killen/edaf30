#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int inputSize = 81;
    char input[inputSize];
    char newInput[inputSize];
    cin.getline(input,81);

    inputSize = strlen(input);

    cout << sizeof(input) << endl;
    cout << input[1]+13 << endl;

    for(int i = 0; i < strlen(input); i++){
        input[i] = toupper(input[i]);
        if(input[i] == ' '){
            newInput[i] = input[i];
        }else{
            newInput[i] = input[i]+13;
        }

        if(newInput[i] > 'Z'){
            newInput[i] -= 26;
        }
    }

    for(int i = 0; i< inputSize; i++){
        cout << newInput[i];
    }

    return 0;
}
