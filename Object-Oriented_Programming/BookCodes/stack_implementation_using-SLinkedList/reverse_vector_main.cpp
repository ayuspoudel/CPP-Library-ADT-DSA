#include"Stack_SLL.cpp"

int main(){
    std::vector<int> vec_nums = {13,6,-1,17,9,0,25};
    for(auto i = vec_nums.begin(); i!=vec_nums.end(); i++){
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
    StackSLL<int>* nums= new StackSLL<int>;
    for(auto i = vec_nums.begin(); i!=vec_nums.end(); i++){
        nums->push(*i);
    }
    std::vector<int> rev_nums;
    while(!nums->empty()){
        rev_nums.push_back(nums->stackTop());
        nums->pop();
    }
    for(auto i = rev_nums.begin(); i!=rev_nums.end(); i++){
        std::cout<<*i<<" ";
    }
    
    
}