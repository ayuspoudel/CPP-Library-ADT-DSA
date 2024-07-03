#include"Stack-Library/Stack.h"
#include<stdio.h>
bool check_parenthesis(char* pointer){
    LinkedStack<char>* stack = new LinkedStack<char>;
    char* temp = pointer;
    while(*temp!='\0'){
        if((*temp) == '('||(*temp) == '{'||(*temp) == '['){
            stack->push(*temp);
            temp++;
        }else if((*temp) == ')'){
            if(stack->isEmpty() || stack->top()!='('){
                return false;
            }
            stack->pop();
            temp++;
        }else if((*temp) == '}'){
            if(stack->isEmpty() || stack->top()!='{'){
                return false;
            }
            stack->pop();
            temp++;
        }else if((*temp) == ']'){
            if(stack->isEmpty() || stack->top()!='['){
                return false;
            }
            stack->pop();
            temp++;
        }else{
            temp++;
        }
    }
    if(stack->isEmpty()){
        return true;
    }
    return false;
}
int main(){
    char arr[100];
    std::cout<<"Enter the expression to check parenthesis: ";
    char ch = getchar();
    int i = 0;
    while(ch!='\n'){
        arr[i] = ch;
        ch = getchar();
        i++;
    }
    if(check_parenthesis(arr)){
        std::cout<<"Balanced"<<std::endl;   
        return 0;
    }
    std::cout<<"Unbalanced";
    return 0;
}