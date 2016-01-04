#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <iostream>
using namespace std;


template <class T>
void printArray(T a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

template <class T>
int medel(T a[], int start, int stop) {
    return start + (stop - start)/2;
}

template <class T>
int del(T a[], int start, int stop){
    int index = medel(a, start, stop);  // Hitta elementet i mitten.
    T value = a[index];
    swap(a[index], a[stop]);            // Byt plats på sista elementet och mittenelementet.
    int pos = start;
    for(int i = start; i < stop; i++) {
        if(a[i] < value) {              // Om värdet i element i är mindre än mittenelementets value, byt plats med element med index pos.
            swap(a[i], a[pos]);
            pos++;
        }
    }
    swap(a[pos], a[stop]);
    return pos;
}

template <class T>
void quicksort(T a[], int start, int stop){
    if(start < stop) {
        int pos = del(a, start, stop);
        quicksort(a, start, pos - 1);
        quicksort(a, pos + 1, stop);
    }
}




/*
template <class T>
void quicksort(T a[], int start, int stop){
    //printArray(a);
    if(stop-start<=1){
    }
    else{
        int k = a[start];
        int leftSide = start;
        for(int i=start;i<stop;++i){
            if(a[i]<=k){            //Om objektet är mindre än k,
                ++leftSide;         //Hitta det högre talet som är närmast k och
                T temp = a[i];      //Byt plats på det mindre talet och det det högre talet som är närmast k.
                a[i] = a[leftSide];
                a[leftSide] = temp;
            }
        }
        T temp = a[leftSide];      //Avsluta med att byta plats på k (som är sist) och det mindre talet längst till höger.
        a[leftSide] = k;
        a[start] = temp;
        quicksort(a, start, leftSide);  //Sortera vänstra sidan
        quicksort(a, leftSide+1, stop); //sortera högra sidan.
    }
}
*/

#endif // QUICKSORT_H
