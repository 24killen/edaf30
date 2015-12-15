#include <iostream>

using namespace std;

void kvadratkubtabell(int n){
    for(int i=1; i<=n; ++i){
        cout << i << " , " << (i*i) << " , " << (i*i*i) << endl;
    }
}

int main(){
    int a;
    cin >> a;
    kvadratkubtabell(a);
    return 0;
}
