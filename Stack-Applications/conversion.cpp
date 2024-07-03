#include"Stack-Library/Stack.h"
#include<iostream>
#include<cstdlib>
#include<string.h>
bool isoperand(char ch){
    return (ch>='0' && ch<='9');
}
bool isoperator(char ch){
    return (ch == '+'||ch == '-'||ch == '*'||ch == '/');
}
int precedence(char ch){
    if(ch=='+'||ch=='-'){
        return 1;
    }
    if(ch == '*'|| ch=='/'){
        return 2;
    }
    return 0;
}
char* convert(char* pointer){
    LinkedStack<char>* operators = new LinkedStack<char>;
    char* postfix = new char[strlen(pointer)+1];
    char* p1 = pointer;
    char* p2 = postfix;
    while(p1!='\0'){
        if(isoperand(*p1)){
            *p2 = *p1;
            p2++;
            p1++;
        } else if(isoperator(*p1)){
            if(operators->isEmpty() || precedence(*p1)>precedence(operators->top())){
                operators->push(*p1);
                p1++;
                continue;
            }
            else{
                *p2 = operators->top();
                operators->pop();
                p2++;
                p1++;
            }
        }
    }
    while(!operators->isEmpty()){
        *p2 = operators->top();
        operators->pop();
        p2++;
    }
    *p2 = '\0';
    delete operators;
    return p2;
}
enum {CAP =100};
int main(){
    char expression[100] = "1+2+3";
    printf("%s\n", expression);
    char* postfix = convert(expression);
    printf("%s\n", postfix);
    return 0;
}