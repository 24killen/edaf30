#include <iostream>
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include <vector>

using namespace std;

int main(){

    Pet* pointer;
    Bird b = Bird("Ho Ho");
    Cat c = Cat("Mjau");
    Dog d = Dog("Woof");
    std::vector<Pet*> v;

    v.push_back(&b);
    v.push_back(&c);
    v.push_back(&d);

    for(int i = 0; i<v.size();++i){
        pointer = v.at(i);
        cout << (pointer->speak()) << endl;
   }
    return 0;
}
