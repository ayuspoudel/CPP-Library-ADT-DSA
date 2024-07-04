#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
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
        ~BTree(){};
        void create();
        void preordertraversal(BNode* root);
        void inordertraversal(BNode* root);
        void postordertraversal(BNode* root);
        BNode* getNode(){
            return this->root;
        }
    private:
        BNode* root;
};

void BTree::create(){
    std::cout<<"Enter the root of the tree: ";
    int x;
    std::cin>>x;
    this->root = new BNode(x);
    std::queue<BNode*> Q;
    Q.push(this->root);
    BNode* pointer;
    while(!Q.empty())
    {
        pointer = Q.front();
        Q.pop();
        std::cout<<"Enter the left child of"<<pointer->elem<< ": ";
        std::cin>>x;
        if(x!=-1)
        {
            BNode* childNode = new BNode(x);
            pointer->left = childNode;
            Q.push(childNode);
        }
        std::cout<<"Enter the right child of"<<pointer->elem<< ": ";
        std::cin>>x;
        if(x!=-1)
        {
            BNode* childNode = new BNode(x);
            pointer->right = childNode;
            Q.push(childNode);
        }
    }
    return;
}

void BTree::preordertraversal(BNode* root){
    if(root == nullptr){
        return;
    }
    //visit the node
    std::cout<<root->elem<<", ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void BTree::inordertraversal(BNode* root){
    if(root == nullptr){                   
        return;
    }
    inordertraversal(root->left);
    //visit the node
    std::cout<<root->elem<<", ";
    inordertraversal(root->right);
}
void BTree::postordertraversal(BNode* root){
    if(root == nullptr){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    //visit the node
    std::cout<<root->elem<<", ";
}

int main(){
    BTree* binaryTree = new BTree();
    binaryTree->create();
    BNode* root_node = binaryTree->getNode();
    binaryTree->inordertraversal(root_node);
    std::cout<<std::endl;
    binaryTree->preordertraversal(root_node);
    std::cout<<std::endl;
    binaryTree->postordertraversal(root_node);
    std::cout<<std::endl;
    return EXIT_SUCCESS;
}