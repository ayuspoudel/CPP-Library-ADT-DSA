#include<cstdlib>
#include<iostream>
#include<string>

class BST{
    private:
        int elem;
        BST *left, *right;

    public:
        BST(int val): elem(val), left(nullptr), right(nullptr){};
        BST(): elem(), left(nullptr), right(nullptr){};
        BST* insert(BST*, int val);
        void preordertraversal(BST* root);
        void display(BST* root);
        void inorder(BST*);
};

BST* BST::insert(BST* root, int val){
    if(root == nullptr){
        return new BST(val);
    }
    if(root->elem>val){
        root->left = insert(root->left, val);
    }
    if(root->elem<val){
        root->right = insert(root->right, val);
    }
    return root;
}
void BST::preordertraversal(BST* root){
    if(root != nullptr){
        std::cout<<root->elem<<",";
    preordertraversal(root->left);
    preordertraversal(root->right);
    }
}
void BST::display(BST* root){
    preordertraversal(root);
}

int main(){
    BST* new_bst = new BST();
    new_bst->insert(new_bst, 30);
    new_bst->insert(new_bst, 40);
    new_bst->insert(new_bst, 10);
    new_bst->insert(new_bst, 20);
    new_bst->insert(new_bst, 90);
    new_bst->insert(new_bst, 60);
    new_bst->display(new_bst);
    return 0;
}