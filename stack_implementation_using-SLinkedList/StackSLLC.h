#include"Stack_SLL.h"

class StackSLLC:public StackSLL<char>{
    public:
        StackSLLC();
        ~StackSLLC();
        StackSLL<char>& convert(){
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
                            screen->push(operators->stackTop();
                            operators->pop();
                            curr = operators->stackTop();
                        }
                        operators->pop();
                        this->pop();
                    }
                } else if(this->isoperand(this->stackTop())){
                    //if precedence of existing operators in stack are greater 
                    //then pop out alll those operators
                    //then push the curr operator into stack
                    char newOp = this->stackTop();
                    if(operators->empty()){operators->push(newOp);};
                    char currOp = operators->stackTop();
                    if(precedence(newOp)> precedence(currOp)){
                        operators->push(newOp);
                    }
                    while(!operators->empty() && precedence(newOp)<=precedence(currOp)){
                        screen->push(currOp);
                        operators->pop();
                        currOp = operators->stackTop();
                    };
                    this->pop();
                }
            }
            return *screen;
        };

    private:
    protected:
        bool isoperand(char ch);
        bool isoperator(char ch);
        bool isparenthesis(char ch);
        int precedence(char ch);
};