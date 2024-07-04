#include<cstdlib>
#include<iostream>
#include<string>
#include<queue>
class BNode{      
    public:
        BNode():elem(-1), left(nullptr), right(nullptr){};
        BNode(int n): elem(n), left(nullptr), right(nullptr){};
        ~BNode(){};
    protected:
    private:
        int elem;
        BNode* left;
        BNode* right;
        friend class BTree;
};

class BTree{
    private:
        BNode* root;
    public:
        BTree():root(nullptr){};
        BTree(int n):root(new BNode(n)){};
        ~BTree(){};
        void create();
        void display();
    protected:
        void inordertraversal(BNode* root);
};
void BTree::create(){
    std::queue<BNode*> Q;
    std::cout<<"Enter the root of the tree: ";
    int x;
    std::cin>>x;
    root = new BNode(x);
    Q.push(root);
    while(!Q.empty()){
        BNode* p;
        p = Q.front();
        Q.pop();
        std::cout<<"Enter the left child of the "<< p->elem<<": ";
        std::cin>>x;
        if(x!=-1){
            BNode* newChild = new BNode(x);
            p->left = newChild; 
            Q.push(newChild);
        }
        std::cout<<"Enter the right child of "<< p->elem<<": ";
        std::cin>>x;
        if(x!=-1){
            BNode* newChild = new BNode(x);
            p->right = newChild; 
            Q.push(newChild);
        }
    }
    return;
}
void BTree::inordertraversal(BNode* root){
    if(root == nullptr){
        return;
    }
    inordertraversal(root->left);
    std::cout<<root->elem<<", ";
    inordertraversal(root->right);
}

void BTree::display(){
   inordertraversal(root);
    return;
}


int main(){
    BTree* binaryTree = new BTree();
    binaryTree->create();
    std::cout<<"Done";
    binaryTree->display();
    return EXIT_SUCCESS;
}