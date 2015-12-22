#ifndef LIST_H
#define LIST_H
#include "Node.h"

class List
{
    public:
        List();
        virtual ~List();
        void add(int value);
        int getHighestValue();
        void print();
    protected:
    private:
        Node* head = nullptr;
};

#endif // LIST_H
