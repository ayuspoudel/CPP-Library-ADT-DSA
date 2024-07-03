#include"SNode.h"
template<typename E>
class SLinkedList{
    public:
        SLinkedList();
        ~SLinkedList();
        void addFront(const E& elem);
        void print();
        void removeFront();
        const E& find(const int& pos) const;
        const E& front() const;
        bool isEmpty() const;
        int getSize()const ;
         void pushback(const E& elem);
    protected:
    private:
        SNode<E>* head;
        int size;
        template<typename T>friend class StackSLL; 
};