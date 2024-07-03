#ifndef SNODE_H
#define SNODE_H
#include<iostream>
#include<cstdlib>
#include<string>

template<typename E>
class SNode{
    public:
        SNode():elem(), next(nullptr){};
        SNode(const E& elem): elem(elem), next(nullptr){};
        SNode(const SNode<E>& source): elem(source.elem), next(nullptr){};
        ~SNode(){};
    protected:
    private:
        E elem;
        SNode* next;
        template<typename T>friend class SLinkedList;
};

#endif