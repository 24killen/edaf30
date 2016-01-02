#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <class T>
class Queue{
    private:
        int maxSize; // Stackens maximala storlek
        int num; // Antalet ele
        T *data; // Data
        int head; // index till nästa pos att läsa från
        int tail; // index till nästa pos att skriva till
    public:
        Queue(int max=100){
            maxSize = max;
            head = -1;
            tail = -1;
            num = 0;
            data = new T [maxSize];
        }

        ~Queue(){
            delete[] data;
        }

        void clear(){
            delete[] data;
            data = new T[maxSize];
            head = 0;
            tail = 0;
            num = 0;
        }

        bool empty() const{
            return num <= 0;
        }

        bool full() const {
            return num >= maxSize;
        }

        T dequeue()throw (std::length_error){
            int ret = head;
            if (head == -1) {
                throw std::length_error("Queue::pop");
            }
            if (head == tail) {
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
            --num;

            return data[ret];
        } // Hämta+avlägsna element, throw (length_error)

        void enqueue(T value)throw (std::length_error){
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
                ++num;
        } //throw (length_error)

        int getSize(){
            return num;
        }
};

#endif // QUEUE_H
