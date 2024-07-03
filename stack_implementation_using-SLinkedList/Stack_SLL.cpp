#include"Stack_SLL.h"
template<typename E>StackSLL<E>::StackSLL():
    size(0), top(nullptr), LinkedStack(){};
template<typename E>StackSLL<E>::~StackSLL(){
}
template<typename E>
StackSLL<E>::StackSLL(const StackSLL<E>& other) : size(0), top(nullptr), LinkedStack() {
    SNode<E>* current = other.top;
    SNode<E>* prev = nullptr;
    while (current != nullptr) {
        SNode<E>* newNode = new SNode<E>(current->data);
        if (top == nullptr) {
            top = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
        current = current->next;
    }
    size = other.size;
}

template<typename E>int StackSLL<E>::getSize() const{
    return this->size;
}
template<typename E>void StackSLL<E>::print(){
    this->LinkedStack.print();
}
template<typename E>void StackSLL<E>::push(const E& elem){
    this->LinkedStack.addFront(elem);
    this->size++;
}
template<typename E>void StackSLL<E>::pop(){
    this->LinkedStack.removeFront();
    this->size--;
}
template<typename E>const E& StackSLL<E>::peek(const int& pos) const{
    return this->LinkedStack.find(pos);
}
template<typename E>const E& StackSLL<E>::stackTop() const{
    return this->LinkedStack.front();
}
template<typename E>bool StackSLL<E>::empty() const{
    return this->LinkedStack.isEmpty();
}
template<typename E>void StackSLL<E>::convert(){
            StackSLL<char>* screen = new StackSLL<char>;
            StackSLL<char>* operators = new StackSLL<char>;
            while(!this->empty()){
                if(this->isoperand(this->stackTop())){
                    screen->push(this->stackTop());
                    this->pop();
                } else if(this->isparenthesis(this->stackTop())){
                    if(this->stackTop() == '('){
                        operators->push(this->stackTop());
                        this->pop();
                    } else {
                        char curr = operators->stackTop();
                        while(curr !='('){
                            screen->push(operators->stackTop());
                            operators->pop();
                            curr = operators->stackTop();
                        }
                        operators->pop();
                        this->pop();
                    }
                } else if(this->isoperator(this->stackTop())){
                    //if precedence of existing operators in stack are greater 
                    //then pop out alll those operators
                    //then push the curr operator into stack
                    char newOp = this->stackTop();
                    while(!operators->empty() && precedence(newOp)<=precedence(operators->stackTop())){
                        screen->push(operators->stackTop());
                        operators->pop();
                    };
                    operators->push(newOp);
                    this->pop();
                }
            }
            while (!operators->empty()) {
                 screen->push(operators->stackTop());
                operators->pop();
             }

    // Replace the current stack's contents with the screen stack
            *this = *screen;
            delete screen;
            delete operators;
            return;
}

template<typename E>bool StackSLL<E>::isoperator(char ch){
    return (ch == '+'||ch =='-' ||ch=='*'||ch=='/'||ch == '^');
}
template<typename E>bool StackSLL<E>::isoperand(char ch){
    return (ch >= '0'&&ch<='9');
}
template<typename E>bool StackSLL<E>::isparenthesis(char ch){
    if(ch == '(' || ch == ')'){
        return 1;
    }
    return 0;
}
template<typename E>int StackSLL<E>::precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else{
        return 3;
    }
}

