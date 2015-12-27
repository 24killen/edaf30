#include <iostream>
#include <vector>

using namespace std;


template<class T>
const void skrivUtFalt(const T& a, size_t n){

    for(int i = 0; i<n;++i){
        cout<<a[i]<<endl;
    }
}

int main(){

    int nbrs[4] = {10,20,30,40};
    string texts[4] = {"Kalle", "Eva", "Nisse", "Oskar"};
    skrivUtFalt(nbrs, 4);
    skrivUtFalt(texts, 4);
    return 0;
}
