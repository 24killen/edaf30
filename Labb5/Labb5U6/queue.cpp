#include "queue.h"

Queue::Queue(int mSize)
{
    maxSize = mSize;
    tail = -1;
    head = -1;
    data = new int[maxSize];
    nbr_elem = 0;
}

Queue::~Queue()
{
    delete[] data;
}

void Queue::clear(){
    tail = 0;
    head = 0;
    nbr_elem = 0;
    delete[] data;
    data = new int[maxSize];
}
bool Queue::empty() const{
    return nbr_elem == 0;
}
bool Queue::full() const {
    return nbr_elem == maxSize;
}

// Hämta+avlägsna element, throw (length_error)
int Queue::dequeue() throw (std::length_error) {

    int ret = head;
    if (head == -1) {
        throw std::length_error("Queue::pop");
    }
    if (head == tail&&nbr_elem == 1) {
        head = -1;
        tail = -1;
    } else {
        if (head == maxSize - 1) {
            head = 0;
        } else {
            head = head + 1;
        }
    }
    std::cout << "Element deleted from queue is: " << data[ret] << std::endl;
    nbr_elem = nbr_elem - 1;

    return data[ret];
}

//throw (length_error)
void Queue::enqueue(int value) throw (std::length_error) {
    if ((head == 0 && tail == maxSize -1) || (head == tail + 1)) {
        throw std::length_error("Queue::push");
    }
    if (head == -1) {
        head = 0;
        tail = 0;
    } else {
        if (tail == maxSize - 1) {
            tail = 0;
        } else {
            tail = tail + 1;
        }
    }
        data[tail] = value;
        nbr_elem = nbr_elem + 1;
}

int Queue::length(){
    return nbr_elem;
}
