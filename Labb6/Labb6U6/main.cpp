#include <iostream>
#include "queue.h"

using namespace std;

struct Kund {
    char namn[35];
    double belopp;
};

int main()
{
    Queue<Kund> q;
    Kund k;

    int sum = 0;

    int menyVal = -1;

    while(menyVal != 0){
        cout << "----MENU----" << endl;
        cout << "1. New customer" << endl;
        cout << "2. Serve customer" << endl;
        cout << "0. Exit" << endl;
        cin >> menyVal;

        try{
            switch(menyVal){
            case 1:
                cout << "Name: ";
                cin >> k.namn;
                cout << "Amount: ";
                cin >> k.belopp;
                q.enqueue(k);
                cout << "Customer added.";
                break;
            case 2:
                k = q.dequeue();
                cout << "Customer " << k.namn << " paied " << k.belopp << endl;
                sum += k.belopp;

                break;
            case 0:
                cout << "Got a total amount of: " << sum << endl;
                break;
            default:
                cout << "Wrong input, try again." << endl;
                break;
            }
        }catch(length_error e){
            cout << "There are no customers in the queue." << endl;
        }
    }
    return 0;
}
