#include"SLinkedList.h"

template<typename E>
class LinkedStack{
    public:
        LinkedStack(): stack(new SLinkedList<E>), size(0){};
        LinkedStack(const LinkedStack<E>& source):
            stack(new SLinkedList<E>(*source.stack)), size(source.size){};
        ~LinkedStack(){
            this->clearStack();
            delete this->stack;
        }
        void pop(){
            if(this->isEmpty()){
                throw std::runtime_error("Stack is empty");
            }
            this->stack->removeFront();
            this->size--;
        }
        void push(const E& elem){
            this->stack->addFront(elem);
            this->size++;
        }
        const E& peek(int pos) const{
            if(this->isEmpty()){
                throw std::runtime_error("Stack is empty");
            }
            return this->stack->view(pos);
        }
        const E& top() const{
            if(this->isEmpty()){
                throw std::runtime_error("Stack is empty");
            }
            return this->stack->Front();
        }
        void clearStack(){
            this->stack->clearList();
            this->size = 0;
            return;
        }
        bool isEmpty() const{
            return (size==0);
        }
        int getSize() const{
            return this->size;
        }
        void print(){
            if(this->isEmpty()){
                std::cout<<"The stack is empty."<<std::endl;
            }
            LinkedStack<E>* temp = new LinkedStack<E>;
            while(!this->isEmpty()){
                std::cout<<this->top()<<" ";
                temp->push(this->top());
                this->pop();
            }   
            std::cout<<std::endl;
            while(!temp->isEmpty()){
                this->push(temp->top());
                temp->pop();
            }
        }
        void swap(LinkedStack<E>& other);
    protected:
    private:
        SLinkedList<E>* stack;
        int size;
};
template<typename E>void LinkedStack<E>::swap(LinkedStack<E>& other){
    LinkedStack<E>* temp = new LinkedStack<E>(other);
        if(this->getSize() != other.getSize()){
            throw std::runtime_error("Two stacks of different sizes cannot be swapped.");
        }
        other.clearStack();
        other = new LinkedStack(*this);
        this->clearStack();
        this = new LinkedStack(*temp);
        return;

}