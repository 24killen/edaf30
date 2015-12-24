#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include <iostream>

class Queue {
    private:
        int maxSize; // köns maximala storlek
        int *data; // Data
        int head; // index till nästa att läsa från 
        int tail; // index till nästa att skriva till
        int nbr_elem;
    public:
        Queue(int max = 100);
        ~Queue();
        void clear();
        bool empty() const;
        bool full() const ;
        int dequeue()throw (std::length_error);; // Hämta+avlägsna element, throw (length_error)
        void enqueue(int value)throw (std::length_error); //throw (length_error)
        int length();
};
#endif // STACK_H
