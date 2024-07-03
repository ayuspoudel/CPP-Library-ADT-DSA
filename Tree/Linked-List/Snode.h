#ifndef SNODE_H
#define SNODE_H

#include<iostream>
#include<string>

template<typename E>
class SNode{
    public:
        SNode(){};
    protected:
    private:
        E elem;
        SNode<E>* next;
        template<typename T>friend class SLinkedList;
};

#endif