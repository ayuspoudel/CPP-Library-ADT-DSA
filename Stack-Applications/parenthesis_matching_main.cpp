#include"Stack-Library/Stack.h"

bool check_balance(char* ch){
    LinkedStack<char>* paren = new LinkedStack<char>;
    char* i = ch;
    while(*i!='\0'){
        if(*i == '('){
            paren->push(*i);
            i++;
            continue;
        }else if(*i == ')'){
            if(paren->isEmpty()){
                return false;
            }else if(paren->top() == '('){
                paren->pop();
                i++;
            }
        }
        else{
            i++;
        }
    }
    if(!paren->isEmpty()){
        return false;
    }
    return true;
}   

int main(){
    char name[100];
    char ch = getchar();
    int i = 0;
    while(ch!='\n'){
        name[i]= ch;
        ch = getchar();
        i++;
    }
    name[i] = '\0';
    if(check_balance(name)){
        std::cout<<"Balanced"<<std::endl;
        return EXIT_SUCCESS;
    }
    std::cout<<"Not Balanced"<<std::endl;
    return 0;
}