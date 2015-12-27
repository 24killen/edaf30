#include "quicksort.h"

template<class T>
quicksort<T>::quicksort(const T a, int start, int stop){
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
