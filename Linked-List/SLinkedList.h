#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include<iostream>
#include<string>
#include"Snode.h"

template<typename E>
class SLinkedList{
    public:
        SLinkedList();
        ~SLinkedList();
        bool empty() const;
        const E& front() const;
        void addfront(const E& e);
        void removeFront();
        void print();
        int getsize() {return nElem;};
    protected:
    private:
        int nElem;
        SNode<E>* head;
};
#endif