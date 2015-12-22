#include <iostream>
#include <List.h>
#include <random>
#include <time.h>
using namespace std;

void addRandomValues(List &list, int nbrItems);

int main()
{
    srand(time(NULL));

    List list;
    addRandomValues(list, 20);

    list.print();
    cout << endl << endl<< "Highest value: "<< list.getHighestValue()<<endl;

    return 0;
}

void addRandomValues(List &list, int nbrItems){
    for(int i = 0; i<nbrItems; i++){
        list.add(rand()%(9999));
    }
}
