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
    swap(a[index], a[stop]);            // Byt plats p� sista elementet och mittenelementet.
    int pos = start;
    for(int i = start; i < stop; i++) {
        if(a[i] < value) {              // Om v�rdet i element i �r mindre �n mittenelementets value, byt plats med element med index pos.
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
            if(a[i]<=k){            //Om objektet �r mindre �n k,
                ++leftSide;         //Hitta det h�gre talet som �r n�rmast k och
                T temp = a[i];      //Byt plats p� det mindre talet och det det h�gre talet som �r n�rmast k.
                a[i] = a[leftSide];
                a[leftSide] = temp;
            }
        }
        T temp = a[leftSide];      //Avsluta med att byta plats p� k (som �r sist) och det mindre talet l�ngst till h�ger.
        a[leftSide] = k;
        a[start] = temp;
        quicksort(a, start, leftSide);  //Sortera v�nstra sidan
        quicksort(a, leftSide+1, stop); //sortera h�gra sidan.
    }
}
*/

#endif // QUICKSORT_H
