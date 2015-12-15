#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

 int randInt(int mini, int maxi){
     if(mini<maxi){
        srand(time(NULL)*time(NULL));
        return rand() % (maxi - mini+1) + mini;
     }
     else if( mini == maxi)
        return mini;
     else
        cout << "Feeeeeel" << endl;
     return 0;
 }

int main(){

    int minimum, maximum;
    cin >> minimum;
    cin >> maximum;
    cout << randInt(minimum, maximum);
    return 0;
}
