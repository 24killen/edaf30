#include <iostream>
#include "quicksort.h"

using namespace std;

int main(){
    // Test 1:
    cout << "Test 1: " << endl;
    int nbrs[10] = {9,10,8,2,6,5,4,3,7,1};
    cout << "Osorterad: ";
    printArray(nbrs,10);

    quicksort(nbrs, 0, 9);

    cout << "Sorterad: ";
    printArray(nbrs,10);

    cout << "---------------------" << endl;

    // Test 2
    cout << "Test 2: " << endl;
    char str[] = {"This is a cool test"};
    cout << "Osorterad: " << str << endl;
    quicksort(str, 0, 18);
    cout << "Sorterad: " << str << endl;


    return 0;
}
