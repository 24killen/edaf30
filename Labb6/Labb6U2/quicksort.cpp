#include "quicksort.h"

template<class T>
quicksort<T>::quicksort(const T a, int start, int stop){
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
