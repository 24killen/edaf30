#include "Stack.h"

Stack::Stack(int max)
{
    maxSize = max;
    num = 0;
    data = new int [maxSize];
}

Stack::~Stack()
{
    delete[] data;
}

void Stack::clear(){
    delete[] data;
    data = new int[maxSize];
    num = 0;
}

bool Stack::empty() const{
    return num <= 0;
}

bool Stack::full() const {
    return num >= maxSize;
}

// Hämta+avlägsna element, throw (length_error)
int Stack::pop() throw (std::length_error){
    if(num <= 0) throw std::length_error("Stack::pop");
    return data[--num];
}

//throw (length_error)
void Stack::push(int value) throw (std::length_error){
    if(num>=maxSize) throw std::length_error("Stack::push");
    data[num++] = value;
}
int Stack::getSize(){
    return num;
}
