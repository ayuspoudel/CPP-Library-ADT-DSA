#ifndef SNODE_H
#define SNODE_H
#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
template<typename E>
class SNode{
    private:
        E elem;
        SNode<E>* next;
        template <typename T>friend class SLinkedList;
    protected:
    public:
        SNode():next(nullptr){};
};
#endif