#include "Stack.h"

Stack::Stack(int mSize)
{
    maxSize = 25;
    num = 0;
    int val[maxSize];
    for(int i = 0; i < maxSize; i++){
        val[i] = 5;
    }
    data = val;
    data[0] = 2;
    data[1] = 2;
    data[2] = 2;
}

Stack::~Stack()
{
    //dtor
}

void Stack::clear(){
    num = 0;
}
bool Stack::empty() const{
    return num<=0;
}
bool Stack::full() const {

}
// Hämta+avlägsna element, throw (length_error)
int Stack::pop() throw (std::length_error){
    if((num)<1){
        throw std::length_error("Stack::pop");
    }else{
     //   std::cout << "BANANA:" << data[num] << std::endl;
        num--;
        std::cout << "Pop: " <<  num << std::endl;
        return data[num];
    }
}
//throw (length_error)
void Stack::push(int value) throw (std::length_error){
     if((num)>(maxSize)){
        throw std::length_error("Stack::push");
    }else{
        std::cout << "Push: " << num << std::endl;
        data[num]=value;
        num++;
    }
}
int Stack::getSize(){
    return num;
}
