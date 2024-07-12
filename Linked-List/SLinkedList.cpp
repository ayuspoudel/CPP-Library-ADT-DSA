#include"SLinkedList.h"
template<typename E> SLinkedList<E>::SLinkedList():head(nullptr){};
template<typename E> bool SLinkedList<E>::empty() const{
    return (this->head == nullptr);
}
template<typename E> const E& SLinkedList<E>::front() const{
     return this->head->elem;
}
template<typename E> void SLinkedList<E>::addfront(const E& e){
    SNode<E>* newNode = new SNode<E>;
    newNode->elem = e;
    newNode->next = head;
    head = newNode;
    nElem++;
    return;
}
template<typename E> void SLinkedList<E>::removeFront(){
    SNode<E>* prev = head;
    head = head->next;
    delete prev;
    nElem--;
    return;
}
template<typename E>SLinkedList<E>::~SLinkedList(){
    SNode<E>* temp = head;
    while(temp!=nullptr){
        SNode<E>* pointer = temp;
        temp = temp->next;
        delete pointer;
        nElem--;
    }
    return;
    }
template<typename E> void SLinkedList<E>::print(){
    SNode<E>* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->elem<<"\t";
        temp = temp->next;
    }
    std::cout<<std::endl;
    return;
    }