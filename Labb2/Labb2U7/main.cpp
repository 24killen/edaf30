#include <iostream>

using namespace std;

int recursive(int n){
    if(n==1)
        return 1;
    return n*n+recursive(n-1);
}

int iterative(int n){
    int result = 0;
    for(int i=1;i<=n;++i){
        result +=i*i;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    cout << recursive(n) << endl;
    cout << iterative(n) << endl;

    return 0;
}
