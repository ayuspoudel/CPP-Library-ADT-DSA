#include"StackSLLC.h"
StackSLLC::StackSLLC(): StackSLL(){};
StackSLLC::~StackSLLC(){};

bool StackSLLC::isoperator(char ch){
    return (ch == '+'||ch =='-' ||ch=='*'||ch=='/'||ch == '^');
}
bool StackSLLC::isoperand(char ch){
    return (ch >= '0'&&ch<='9');
}
bool StackSLLC::isparenthesis(char ch){
    if(ch == '(' || ch == ')'){
        return 1;
    }
    return 0;
}
int StackSLLC::precedence(char ch){
    if(ch == '+' && ch == '-'){
        return 1;
    }
    else if(ch == '/' && ch == '*'){
        return 2;
    }
    else{
        return 3;
    }
}