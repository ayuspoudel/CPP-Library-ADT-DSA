#include"Stack_SLL.cpp"

int main(){

    StackSLL<char>* preFix_exp = new StackSLL<char>;
    StackSLL<char> postFix_exp;
    char ch;
    std::cout<<"Enter the PreFix Expression: ";
while(std::cin.get(ch) && ch!='\n'){
    preFix_exp->push(ch);
}
std::cout<<"Your Prefix Expression is: ";
preFix_exp->print();
preFix_exp->convert();
std::cout<<"Your PostFix Expression is: ";
preFix_exp->print();

    return 0;
}