#include <iostream>

using namespace std;

//Funktionerna som main() anv�nder m�ste l�sas in f�rst, annars
//f�rst�r inte main() vad som menas med t.ex. delbar(int, int);
bool delbar(int a, int b){
        if(a%b == 0)
            return true;
        else
            return false;
}

int main(){
    int t,y;

    cin >> t;
    cin >> y;
    cout << delbar(t,y);



    return 0;
}

