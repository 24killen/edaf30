#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

List::List()
{
    //ctor
}

List::~List()
{
    //dtor
}

void List::add(int value){

    Node *newNode = new Node(value);
    Node *temp = head;

    // Om det redan finns noder i listan, g� till sista elementet och l�nka next till det nya inlagda.
    if(temp != nullptr){
            while(temp->next() != nullptr){
                temp = temp->next();
            }
        temp->setNext(newNode);
    }else{
        // newNode �r f�rsta noden.
        head = newNode;
    }
}

int List::getHighestValue(){
    Node* temp = head;
    int high = 0;

    if(temp == nullptr){
        return -1;
    }else{
        if(temp->next() == nullptr){
            high = temp->data();
        }else{
            do{
                if(temp->data()>high){
                    high = temp->data();
                }
                temp = temp->next();
            }while(temp != nullptr);
        }
    }
    return high;
}

void List::print(){
    Node* temp = head;

    if(temp == nullptr){
        cout << "TOM LISTA" << endl;
    }else{
        if(temp->next() == nullptr){
            cout << temp->data() << "--> " << "NULL" << endl;
        }else{
            do{
                cout << temp->data() << "--> ";
                temp = temp->next();
            }while(temp != nullptr);
            cout << "NULL" << endl;
        }
    }
}

