#include<string>
#include<iostream>
#include<cstdlib>
#include<exception>

template<typename E> class SNode{
    public:
        SNode():next(nullptr), elem(){};
        SNode(const E& e, SNode* next = nullptr): elem(e), next(next){};
        SNode(const SNode& other){
            this->elem = other->elem;
            this->next = (other->next)? new SNode<E>(other->next):nullptr;
        }
        ~SNode(){};
    protected:
    private:
        E elem;
        SNode* next;
        template<typename T> friend class SLinkedList;
};