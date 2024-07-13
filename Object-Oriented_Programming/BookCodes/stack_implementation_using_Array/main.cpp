#include"stack_oop.cpp"

int main(){
    std::vector<int> vec_nums = {13,6,-1,17,9,0,25};
    StackArray<int>* nums= new StackArray<int>;
    for(auto i = vec_nums.begin(); i!=vec_nums.end(); i++){
        nums->push(*i);
    }
    int n = nums->getSize();
    int i = 0;
    while(i<n){
        vec_nums[i] = nums->stackTop();
        nums->pop();
        i++;
    }
    for(auto i = vec_nums.begin(); i!=vec_nums.end(); i++){
        std::cout<<*i<<" "<<std::endl;
    }
}