#include "Node.h"

Node::Node(int input)
{
    setData(input);
    setNext(nullptr);
}

Node::~Node()
{
    //dtor
}

void Node::setData(int input){
    dataValue = input;
}

void Node::setNext(Node* node){
    nextNode = node;
}

int Node::data(){
    return dataValue;
}

Node* Node::next(){
    return nextNode;
}
