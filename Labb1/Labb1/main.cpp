//#include "Labb1U1.h"
#include <iostream>

using namespace std;

int main(){    //ctor
    //From instructions
    for(int a = 1; a <= 3; a++){
        for(int b = 1; b<= 3; b++){
            for(int c = 1; c<= 3; c++){
                int x = 0;
                int m = a;
                if(b>m)
                    m=b;
                if(c>m)
                    m=c;
                //The solution
                if(a>b && a>c)
                    x=a;
                else if(b>c)
                    x=b;
                else
                    x=c;

                cout << "a b c x = " << a << " " << b << " " << c << " " << x;
                if(x!=m){
                    cout << " Fel: max = " << m;
                }
                cout << endl;
            }
        }
    }
    return 0;
}
