#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    try{
    Queue q(10);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.enqueue(6);
        q.enqueue(7);
        q.enqueue(8);
        q.enqueue(9);
        q.enqueue(10);
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
        q.dequeue();
    }
    catch(std::length_error e){
        cout << "ERROR (length_error): " <<  e.what() << endl;
    }

    return 0;
}
