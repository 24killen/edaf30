#include <iostream>
#include "quicksort.h"

using namespace std;

int main(){
    int nbrs[10] = {10,9,8,7,6,5,4,3,2,1};
    quicksort q = quicksort(nbrs, 0, 9);
    cout << "Hello world!" << endl;
    return 0;
}
