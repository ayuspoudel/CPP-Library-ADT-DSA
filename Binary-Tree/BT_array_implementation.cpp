#include<iostream>
#include<string>
#include<cstdlib>
enum {N=100};
class BinaryTree{
    public:
        BinaryTree(): arr(){}; 
        int set_root(char ch){
            if(arr[0] == '\0'){
                arr[0] = ch;
                return 0;
            }
            std::cout<<"The root already has element "<<arr[0]<<std::endl;
            return 1;
        }
        int setleft(char ch, int parent){
            if(arr[parent]=='\0'){
                std::cout << "\nCan't set child at "<< (parent * 2) + 1<< " , no parent found";
                return 1;
            }
            arr[2*parent +1] = ch;
            return 0;
        }
        int setright(char ch, int parent){
            if(arr[parent]=='\0'){
                std::cout << "\nCan't set child at "<< (parent * 2) + 2<< " , no parent found";
                return 1;
            }
            arr[2*parent +2] = ch;
            return 0;
        }
        void display(){
            if(this->arr[0] == '\0'){
                std::cout<<"The Binary Tree is Empty"<<std::endl;
                return;
            }
            int i = 0;

            while(arr[i]!='\0'){
                std::cout<<arr[i]<<", ";
                i++;
            }
        }
    private:
        char arr[N];
    protected:
};

int main(){
    BinaryTree* newBT = new BinaryTree();
    
    newBT->set_root('1');
    newBT->setleft('2', 0);
    newBT->setright('3', 0);
    newBT->display();
    return 0;
}