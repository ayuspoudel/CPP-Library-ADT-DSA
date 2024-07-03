#ifndef DNODE_H
#define DNODE_H
#include<iostream>
#include<cstdlib>
#include<string>
#include<exception>
template<typename E>
class DNode{
    public: 
        DNode(): prev(nullptr), elem(), next(nullptr){};
        DNode(const E& elem):prev(nullptr), elem(elem), next(nullptr){};
        DNode(const DNode<E>& source){
            this->prev = source.prev;
            this->elem = source.elem;
            next->elem = source.next;
        }
        ~DNode(){};
    protected:
    private:
        DNode* prev;
        E elem;
        DNode* next;
        template <typename T>friend class DLinkedList;
};

#endif