#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include"SNode.h"
#include<exception>
template<typename E>
class SLinkedList{
    public:
        SLinkedList();
        SLinkedList(const SNode<E>& node);
        SLinkedList(const SLinkedList<E>& source);
        ~SLinkedList();
        void addFront(const E& elem);
        const E& Front() const;
        void removeFront();
        const E& view(int pos) const;
        void clearList();
        void print() const;
        int getSize() const{
            return(this->nElem);
        }
    protected:
    private:
        int nElem;
        SNode<E>* head;
        bool empty() const{
            return (nElem==0);
        }
        // int getSize() const{
        //     return(this->nElem);
        // }
};
template<typename E>SLinkedList<E>::SLinkedList():head(nullptr), nElem(0){};
template<typename E>SLinkedList<E>::SLinkedList(const SNode<E>& node):head(node), nElem(1){};
template<typename E>SLinkedList<E>::~SLinkedList(){
    this->clearList();
}
template<typename E>SLinkedList<E>::SLinkedList(const SLinkedList<E>& source){
    if(source.empty()){
        this->head = nullptr;
        this->nElem = 0;
        return;
        }
    this->head = new SNode<E>(*source.head);
    SNode<E>* pointer_source = source.head->next;
    SNode<E>* pointer_this = this->head;
    while(pointer_source!=nullptr){
        SNode<E>* newNode = new SNode<E>(*pointer_source);
        pointer_this->next = newNode;
        pointer_this = pointer_this->next;
        pointer_source = pointer_source->next;
    }
    this->nElem = source.nElem;
};
template<typename E>void SLinkedList<E>::addFront(const E& elem){
    SNode<E>* newNode = new SNode<E>(elem);
    if(this->empty()){
        this->head = newNode;
        nElem++;
        return;
    }
    SNode<E>* pointer = this->head;
    newNode->next = pointer;
    this->head = newNode;
    nElem++;
    return;
}
template<typename E>const E& SLinkedList<E>::Front() const{
    if(head == nullptr){
        throw std::runtime_error("The list is empty.");
    }
    return (this->head->elem);
}
template<typename E>void SLinkedList<E>::removeFront(){
    if(this->empty()){
        throw std::runtime_error("The list is empty.");
    }
    SNode<E>* pointer = this->head;
    this->head = pointer->next;
    nElem--;
    delete pointer;
}
template<typename E>const E& SLinkedList<E>::view(int pos)const{
    if(pos>this->getSize()){
        throw std::runtime_error("Index Out of Bounds Error");
    }
    if(pos<1){
        throw std::runtime_error("Invalid Position.");
    }
    int k = 1;
    SNode<E>* pointer = this->head;
    while(k<pos){
        pointer = pointer->next;
        k++;
    }
    return pointer->elem;
}
template<typename E>void SLinkedList<E>::clearList(){
    if(this->empty()){
        return;
    }
    SNode<E>* pointer = this->head;
    while(pointer!=nullptr){
        SNode<E>* temp = pointer;
        pointer = pointer->next;
        delete temp;
        nElem--;
    }
    this->head = nullptr;
    return;
}
template<typename E> void SLinkedList<E>::print() const{
    if(this->empty()){
        std::cout<<"The list is Empty."<<std::endl;
        return;
    }
    SNode<E>* pointer = this->head;
    while(pointer!=nullptr){
        std::cout<<pointer->elem<<" ";
        pointer =pointer->next;
    }
    std::cout<<std::endl;
    return;
}


#endif