#include <iostream>
#include <tgmath.h>

using namespace std;

int poly(int koeff [5]){
    int x;
    cout << "Mata in x: ";
    cin >> x;

    int result = koeff[0];
    for(int i=1;i<5;++i){
        int pow = 1;
        for(int j=1;j<=i;++j){
            pow =  pow*x;
        }
//        cout << koeff[i]*pow << endl;
//        result += (koeff[i]*pow(x,i));
      result += (koeff[i]*pow);
    }
    return result;
}



int main(){
    int polynom[5] = {0,0,0,0,0};
    for(int i=0;i<5;++i){
        cout << "Mata in a" << i << ": ";
        cin >> polynom[i];
    }
    int result = poly(polynom);
    cout << result << endl;
    return 0;
}
