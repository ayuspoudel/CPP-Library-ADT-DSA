#ifndef STACK_SLL_H
#define STACK_SLL_H

#include"SLinkedList.cpp"
template<typename E>
class StackSLL{
    enum {DEF_CAP = 100};
    public:
        StackSLL();
        ~StackSLL();
        StackSLL(const StackSLL<E>& other);
        int getSize() const;
        void print();
        void push(const E& elem);
        void pop();
        const E& peek(const int& pos) const;
        const E& stackTop() const;
        bool empty() const;
        void convert();
    protected:
        bool isoperand(char ch);
        bool isoperator(char ch);
        bool isparenthesis(char ch);
        int precedence(char ch);
    private:
        SNode<E>* top;
        int size;
        SLinkedList<E> LinkedStack;
    
};

#endif