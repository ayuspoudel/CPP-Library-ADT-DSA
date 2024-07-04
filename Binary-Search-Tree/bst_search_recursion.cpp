#include<iostream>
#include<string>
#include<cstdlib>

class BST{
    private:
        int elem;
        BST* right;
        BST* left;
    public:
        BST(int elem):elem(elem), left(nullptr), right(nullptr){};
        ~BST(){};
        void preordertraversal(BST* root);
        BST* insert(BST* root, int val);
        BST* search(BST* root, int val);

};
BST* BST::search(BST* root, int val){
    if(root == nullptr){
        return nullptr;
    }
    if(root->elem == val){
        return root;
    }
    if(root->elem > val){
        search(root->left, val);
    }
    if(root->elem<val){
        search(root->right, val);
    }
    return root;
}
BST* BST::insert( BST* root, int val){
    if(root == nullptr){
        return new BST(val);
    }
    if(root->elem < val){
        root->right = insert(root->right,  val);
    }
    if(root->elem>val){
        root->left = insert(root->left,  val);
    }
    return root;
}
void BST::preordertraversal(BST* root){
    if(root == nullptr){
        return;
    }
    std::cout<<root->elem<<std::endl;
    preordertraversal(root->left);
    
    preordertraversal(root->right);
}


int main(){
    BST* root;
    BST* newTree = new BST(10);
    root = newTree;
    newTree->insert(root, 20);
    newTree->insert(root, 30);
    newTree->insert(root, 40);
    newTree->insert(root, 50);
    newTree->insert(root, 60);
    newTree->insert(root, 70);
    newTree->preordertraversal(root);
    BST* ele = newTree->search(root, 70);
    return 0;
}