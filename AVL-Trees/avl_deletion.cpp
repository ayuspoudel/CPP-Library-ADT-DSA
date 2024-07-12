#include<string>
#include<stack>
#include<queue>
#include<iostream>
#include<cstdlib>

struct Node{
    int data;
    Node* rchild;
    Node* lchild;
    Node(int n): data(n), rchild(nullptr), lchild(nullptr){};
    Node(): data(), rchild(nullptr), lchild(nullptr){};
};

int treeHeight(Node* tree){
    if(tree == nullptr){
        return 0;
    }
    int lheight = treeHeight(tree->lchild);
    int rheight = treeHeight(tree->rchild);
    return (lheight>rheight)?lheight+1:rheight+1;
}
int balanceFactor(Node* tree){
    if(tree == nullptr){
        return 0;
    }
    int lheight = treeHeight(tree->lchild)+1;
    int rheight = treeHeight(tree->rchild)+1;
    return (lheight - rheight);
}
Node* LLRotation(Node* root){
    Node* rl = root->lchild;
    Node* rlr = root->lchild->rchild;
    rl->rchild = root;
    root->lchild = rlr;
    return rl;
}
Node* LRRotation(Node* root){
    Node* rl = root->lchild;
    Node* rlr = rl->rchild;
    root->lchild = rlr;
    rl->rchild = rlr->lchild;
    rlr->lchild = rl;
    root = LLRotation(root);
    return root;
}
Node* RRRotation(Node* root) {
    Node* rr = root->rchild;
    Node* rrl = rr->lchild;
    rr->lchild = root;
    root->rchild = rrl;
    return rr;
}

Node* RLRotation(Node* root){
    Node* rr = root->rchild;
    Node* rlr = root->rchild->lchild;
    root->rchild = rlr;
    rr->lchild = rlr->lchild;
    rlr->rchild = rr;
    root = RRRotation(root);
    return root;
}
Node* checkImbalance(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    if (balanceFactor(root) == 2 && balanceFactor(root->lchild) >= 0) {
        root = LLRotation(root);
    }
    if (balanceFactor(root) == 2 && balanceFactor(root->lchild) < 0) {
        root = LRRotation(root);
    }
    if (balanceFactor(root) == -2 && balanceFactor(root->rchild) <= 0) {
        root = RRRotation(root);
    }
    if (balanceFactor(root) == -2 && balanceFactor(root->rchild) > 0) {
        root = RLRotation(root);
    }
    return root;
};
Node* insert(Node* root, int n){
    if(root == nullptr){
        Node* newNode = new Node(n);
        return newNode;
    }   
    else if(n<root->data){
        root->lchild = insert(root->lchild, n);
    }
    else if(n>root->data){
        root->rchild = insert(root->rchild, n);
    }
    else{
        std::cout<<"The key "<<n<< " is already present in the tree"<<std::endl;
        return root;
    }
    root = checkImbalance(root);
    return root;
}

Node* deleteNode(Node* tree, int key){
    if(tree == nullptr){
        return nullptr;
    }
    if(key<tree->data){
        tree->lchild = deleteNode(tree->lchild, key);
    }
    else if(key>tree->data){
        tree->rchild = deleteNode(tree->rchild, key);
    }
    else{
        //case 1, 2
        if(tree->lchild == nullptr){
            Node* pointer = tree->rchild;
            delete tree;
            return pointer;
        }
        else if(tree->rchild == nullptr){
            Node* pointer = tree->lchild;
            delete tree;
            return pointer;
        }
        //case 3
        else{
            Node* temp = tree->rchild;
            while(temp->lchild!=nullptr){
                temp = temp->lchild;
            }
            tree->data = temp->data;
            tree->rchild = deleteNode(tree->rchild, temp->data);
        }
    }
    tree = checkImbalance(tree);
    return tree;
}


void inorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    inorderTraversal(root->lchild);
    std::cout<<root->data<<" ";
    inorderTraversal(root->rchild);
}

void preorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }
    std::cout<<root->data<<" ";
    preorderTraversal(root->lchild);
    preorderTraversal(root->rchild);
}


int main(){
    Node* avltree = nullptr;
    avltree = insert(avltree, 10);
    avltree = insert(avltree, 20);
    avltree = insert(avltree, 30);
    avltree = insert(avltree, 40);
    avltree = insert(avltree, 50);
    avltree = insert(avltree, 60);
    avltree = insert(avltree, 70);
    avltree = insert(avltree, 80);
    avltree = insert(avltree, 90);
    avltree = insert(avltree, 100);
    avltree = deleteNode(avltree, 40);
    avltree = deleteNode(avltree, 20);
    avltree = deleteNode(avltree, 30);
    avltree = deleteNode(avltree, 10);
    avltree = insert(avltree, 15);
    avltree = insert(avltree, 25);
    avltree = insert(avltree, 35);
    avltree = insert(avltree, 45);
    avltree = insert(avltree, 95);
    avltree = insert(avltree, 85);
    avltree = insert(avltree, 75);
    avltree = insert(avltree, 55);
    avltree = insert(avltree, 65);
    std::cout<<"PreOrderTraversal: ";
    preorderTraversal(avltree);
    std::cout<<std::endl;
    std::cout<<"InOrderTraversal: ";
    inorderTraversal(avltree);
    std::cout<<std::endl;
    int h = treeHeight(avltree);
    int bf = balanceFactor(avltree);
    std::cout<<"The height of the tree is: "<<h<<std::endl;
    std::cout<<"The balance factor of the tree is: "<<bf<<std::endl;
    return EXIT_SUCCESS;
}