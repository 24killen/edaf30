#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include <iostream>

class Stack {
    private:
        int maxSize; // Stackens maximala storlek
        int *data; // Data
        int num; // Antalet element i stacken
    public:
        Stack(int mSize=100);
        ~Stack();
        void clear();
        bool empty() const;
        bool full() const ;
        int pop()throw (std::length_error); // Hämta+avlägsna element, throw (length_error)
        void push(int value)throw (std::length_error); //throw (length_error)
        int getSize();
};
#endif // STACK_H
