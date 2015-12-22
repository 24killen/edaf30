#ifndef NODE_H
#define NODE_H
#include <iostream>


class Node
{
    public:
        Node(int input = NULL);
        virtual ~Node();
        void setData(int data);
        void setNext(Node* nextNode);
        int data();
        Node* next();
    protected:
    private:
        int dataValue;
        Node* nextNode;
};

#endif // NODE_H
