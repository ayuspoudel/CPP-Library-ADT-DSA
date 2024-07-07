#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
class BNode{
    public:
        BNode():elem(-1), left(nullptr), right(nullptr){};
        BNode(int n):elem(n), left(nullptr), right(nullptr){};
        ~BNode(){};
    private:
        int elem;
        BNode* left;
        BNode* right;
        friend class BTree;
};
class BTree{
    public:
        BTree():root(nullptr){};
        BTree(int n):root(new BNode(n)){};
        ~BTree(){};
        void create();
        void preordertraversal();
        void inordertraversal();
    private:
    protected:
        BNode* root;
};
void BTree::create(){
    std::cout<<"Enter the root of the tree: ";
    int x;
    std::cin>>x;
    BNode* pointer;
    root = new BNode(x);
    std::queue<BNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        pointer = Q.front();
        Q.pop();
        std::cout<<"Enter the left child of"<<pointer->elem<<": ";
        std::cin>>x;
        if(x!=-1){
            pointer->left = new BNode(x);
            Q.push(pointer->left);
        }
        std::cout<<"Enter the right child of"<<pointer->elem<<": ";
        std::cin>>x;
        if(x!=-1){
            pointer->right = new BNode(x);
            Q.push(pointer->right);
         }
     } 
        return;
    }
void BTree::preordertraversal(){
    std::stack<BNode*> pointerstack;
    BNode* temp = this->root;
    while(temp!=nullptr || !pointerstack.empty()){
        if(temp != nullptr){
            std::cout<<temp->elem<<" ";
            pointerstack.push(temp);
            temp = temp->left;
        }
        else{
            temp = pointerstack.top();
            pointerstack.pop();
            temp = temp->right;
        }
    }
    std::cout<<std::endl;
    return;
    }


    /*1. INorder we followed THese steps :
            a. Print
            b. Go to left 
            c Go to right
    2. In InOrder we shall follow:
            a. Go to left
            b. print
            c. Go to right
    */
void BTree::inordertraversal(){
    std::stack<BNode*> pointerstack;
    BNode* pointer = this->root;
    while(pointer!=nullptr || !pointerstack.empty()){
        if(pointer !=nullptr){
            pointerstack.push(pointer);
            pointer = pointer->left;
        }
        else{
            pointer = pointerstack.top();
            pointerstack.pop();
            std::cout<<pointer->elem<<" ";
            pointer = pointer->right;
        }
    }
    std::cout<<std::endl;
}
int main(){
    BTree* binaryTree = new BTree();
    binaryTree->create();
    binaryTree->preordertraversal();
    binaryTree->inordertraversal();
    return EXIT_SUCCESS;
}