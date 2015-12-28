#include <iostream>
#include "quicksort.h"

using namespace std;

int main(){
    int nbrs[10] = {10,9,8,7,6,5,4,3,2,1};
    quicksort<int> q = quicksort<int>(nbrs&, 0, 9);
    for(int i=0;i<10;++i){
        cout<<nbrs[i];
    }

    return 0;
}
