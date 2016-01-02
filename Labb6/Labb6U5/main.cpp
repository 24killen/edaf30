#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<string> s;
    s.enqueue("Apa");
    s.enqueue("Banana");
    s.enqueue("Minions");
    cout << "Added: Apa, Banana and Minions, to queue" << endl;

    cout << "Current size: " << s.getSize() << endl;

    s.dequeue();
    s.dequeue();
    s.dequeue();

    cout << "Adding: Apples" << endl;
    s.enqueue("Apples");
    cout << "Current size: " << s.getSize() << endl;

    cout << "Empty?: " << s.empty() << endl;

    cout << "Clears the queue." << endl;
    s.clear();

    cout << "Current size: " << s.getSize() << endl;
    cout << "Empty?: " << s.empty() << endl;
/*
    for(int i = 0; i<20; i++){
        cout << "Adding: " << i << " to the stack." << endl; s.push(i);
    }

    cout << "Is the stack empty? (1=true)" << s.empty() <<endl;
    cout << "Current size is now: " << s.getSize() << endl;
    cout << "Pop value: " << s.pop() << endl;

    cout << "Clears the stack, current size is now: "; s.clear(); cout << s.getSize() << endl;
    cout << "Adding: 10 to the stack." << endl; s.push(10);
    cout << "Adding: 15 to the stack." << endl; s.push(15);
    cout << "Adding: 20 to the stack." << endl; s.push(20);
    cout << "Poping values 4 times: " << endl;
    try{
        cout << "Value 1: " << s.pop() << endl;
        cout << "Value 2: " << s.pop() << endl;
        cout << "Value 3: " << s.pop() << endl;
        cout << "Value 4: " << s.pop() << endl;
    }catch(length_error){
        cout << "Length error exception was made. Current size is: " << s.getSize() <<endl;
    }*/
    return 0;
}

