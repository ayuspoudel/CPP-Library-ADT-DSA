#include<string>
#include<stack>
#include<queue>
#include<iostream>
#include<cstdlib>

struct Node{
    int data;
    Node* left, * right;
    Node(): data(), left(nullptr), right(nullptr){};
    Node(int n): data(n), left(nullptr), right(nullptr){};
};
Node* minVal(Node* root){
    Node* temp = root;
    while(temp!= nullptr && temp->left!=nullptr){
        temp = temp->left;
    }
    return temp;
}
Node* deleteNode(Node* tree, int key){
    if(tree == nullptr){
        std::cout<<"The tree is empty.";
        return nullptr;
    }
    if(tree->data>key){
        tree->left = deleteNode(tree->left, key);
    }
    else if(tree->data<key){
        tree->right = deleteNode(tree->right, key);
    }
    else{
        //this is when the key matches
        //if it is a leaf node, or has only one child
        if(tree->left == nullptr){
            Node* temp = tree->right;
            free(temp);
            return temp;
        }
        else if(tree->left == nullptr){
            Node* temp = tree->left;
            free(temp);
            return temp;
        }
        //if it has two child
        else{
            Node* temp = minVal(tree->right);
            tree->data = temp->data;
            tree->right = deleteNode(tree->right, temp->data);
        }
    }
    return tree;

}   

void inorderTraversal(Node* tree){
    Node* pointer = tree;
    std::stack<Node*> pointerstack;
    while(pointer!=nullptr||!pointerstack.empty()){
        if(pointer!=nullptr){
            pointerstack.push(pointer);
            pointer = pointer->left;
        }
        else{
            pointer = pointerstack.top();
            pointerstack.pop();
            std::cout<<pointer->data<<" ";
            pointer = pointer->right;
        }
    } 
    std::cout<<std::endl;
    return;
}
Node* insert(Node* tree, int n){   
    Node* newNode = new Node(n);
    if(tree == nullptr){
        return newNode;
    }
    if(tree->data>n){
        tree->left = insert(tree->left, n);
    }
    else if(tree->data<n){
        tree->right = insert(tree->right, n);
    }
    else{
        std::cout<<"The Key already Exists in the tree."<<std::endl;
    }
    return tree;
}

int main(){
    Node* bst_tree = new Node(10);
    bst_tree = insert(bst_tree, 20);
    bst_tree = insert(bst_tree, 15);
    bst_tree = insert(bst_tree, 5);
    bst_tree = insert(bst_tree, 7);
    bst_tree = insert(bst_tree, 3);
    bst_tree = insert(bst_tree, 18);
    inorderTraversal(bst_tree);
    bst_tree = deleteNode(bst_tree, 7);
    inorderTraversal(bst_tree);
    return EXIT_SUCCESS;
}