#ifndef CNODE_H
#define CNODE_H
#include<string>
#include<cstdlib>
#include<iostream>
template<typename E>
class CNode{
    public:
        CNode():elem(), next(this){};
        CNode(E elem): elem(elem), next(this){};
        CNode(const CNode& source): elem(source.elem), next(source.next){};
        ~CNode(){};
    protected:
    private:
        E elem;
        CNode* next;
        template<typename T>friend class CLinkedList;
};

#endif



