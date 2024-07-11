#include<cstdlib>
#include<string>
#include<iostream>
#include<stack>
struct Node{
    struct Node* lchild;
    int data;
    int height;
    struct Node* rchild;
}* root = nullptr;
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
    return -1;
}
void preOrderTraversal(struct Node* tree){
    if(tree == nullptr){
        return;
    }
    std::cout<<tree->data<<" ";
    preOrderTraversal(tree->lchild);
    preOrderTraversal(tree->rchild);
}
void InOrderTraversal(struct Node* tree){
    // if(tree == nullptr){
    //     return;
    // }
    struct Node* pointer = tree;
    std::stack<struct Node*> pointerstack;
    while(pointer!=nullptr||!pointerstack.empty()){
        if(pointer!=nullptr){
            pointerstack.push(pointer);
            pointer=pointer->lchild;
        }
        else{
            pointer = pointerstack.top();
            pointerstack.pop();
            std::cout<<pointer->data<<" ";
            pointer = pointer->rchild;
        }
    }
    std::cout<<std::endl;
}

int TreeHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    int left_height = TreeHeight(root->lchild);
    int right_height = TreeHeight(root->rchild);
    return max(left_height, right_height)+1;
}

int balanceFactor(Node* root){
    if(root == nullptr){
        return 0;
    }
    int lheight = TreeHeight(root->lchild);
    int rheight = TreeHeight(root->rchild);
    return (lheight - rheight);
}

Node* LLRotation(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* rl = root->lchild;
    Node* rlr = root->lchild->rchild;
    rl->rchild = root;
    root->lchild = rlr;
    return rl;
}
Node* RRRotation(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* rr = root->rchild;
    Node* rrl = rr->lchild;
    rr->lchild = root;
    root->rchild = rrl;
    return rr;
}
Node* LRRotation(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* rl = root->lchild;
    Node* rlr = root->lchild->rchild;
    root->lchild = rlr;
    rl->rchild = rlr->lchild;
    rlr->lchild = rl;
    root = LLRotation(root);
    return root;
}
Node* RLRotation(Node* root){
    if(root == nullptr){
        return nullptr;
    }
    Node* rr = root->rchild;
    Node* rrl = root->rchild->lchild;
    root->rchild = rrl;
    rr->lchild = rrl->rchild;
    rrl->rchild = rr;
    root = RRRotation(root);
    return root;
}
struct Node* RInsert(struct Node *tree, int n){
    if(tree == nullptr){
        struct Node* p = (struct Node* )malloc(sizeof(struct Node));
        p->data = n;
        p->height =1;
        p->lchild = nullptr;
        p->rchild = nullptr;
        return p;
    }
    if(n<tree->data)
    {
        tree->lchild = RInsert(tree->lchild, n);
    }
    else if(n>tree->data){
        tree->rchild = RInsert(tree->rchild, n);
    }
    else{
        std::cout<<"The key already exists in the tree."<<std::endl;
        return tree;
    }
    tree->height = TreeHeight(tree);
    if(balanceFactor(tree) == 2 && balanceFactor(tree->lchild) == 1){
        tree = LLRotation(tree);
    }
    if(balanceFactor(tree) == 2 && balanceFactor(tree->lchild) == -1){
        tree = LRRotation(tree);
    }
    if(balanceFactor(tree) == -2 && balanceFactor(tree->rchild) == -1){
        tree = RRRotation(tree);
    }
    if(balanceFactor(tree) == -2 && balanceFactor(tree->rchild)==1){
        tree = RLRotation(tree);
    }
    return tree;
}

int main(){
    struct Node* avlTreell = nullptr;
    avlTreell = RInsert(avlTreell, 40);
    avlTreell = RInsert(avlTreell, 20);
    avlTreell = RInsert(avlTreell, 10);
    int h = TreeHeight(avlTreell);
    int bf = balanceFactor(avlTreell);
    std::cout<<"The height of the current tree is: "<<h<<std::endl;
    std::cout<<"The balance factor of the current tree is: "<<bf;
    std::cout<<"\nThe preorder traversal is: ";
    preOrderTraversal(avlTreell);
    std::cout<<"\nThe inorder traversal is: ";
    InOrderTraversal(avlTreell);
    std::cout<<std::endl;
    struct Node* avltreerr = nullptr;
    avltreerr = RInsert(avltreerr, 10);
    avltreerr = RInsert(avltreerr, 20);
    avltreerr = RInsert(avltreerr, 30);
    int h2 = TreeHeight(avltreerr);
    int bf2 = balanceFactor(avltreerr);
    std::cout<<"The height of the current tree is: "<<h2<<std::endl;
    std::cout<<"The balance factor of the current tree is: "<<bf2;
    std::cout<<"\nThe preorder traversal is: ";
    preOrderTraversal(avltreerr);
    std::cout<<"\nThe inorder traversal is: ";
    InOrderTraversal(avltreerr);
    std::cout<<std::endl;
    struct Node* avltreelr = nullptr;
    avltreelr = RInsert(avltreelr, 20);
    avltreelr = RInsert(avltreelr, 10);
    avltreelr = RInsert(avltreelr, 15);
    int h3 = TreeHeight(avltreelr);
    int bf3 = balanceFactor(avltreelr);
    std::cout<<"The height of the current tree is: "<<h3<<std::endl;
    std::cout<<"The balance factor of the current tree is: "<<bf3;
    std::cout<<"\nThe preorder traversal is: ";
    preOrderTraversal(avltreelr);
    std::cout<<"\nThe inorder traversal is: ";
    InOrderTraversal(avltreelr);
    std::cout<<std::endl;
    struct Node* avltreerl = nullptr;
    avltreerl = RInsert(avltreerl, 20);
    avltreerl = RInsert(avltreerl, 30);
    avltreerl = RInsert(avltreerl, 25);
    int h4 = TreeHeight(avltreerl);
    int bf4 = balanceFactor(avltreerl);
    std::cout<<"The height of the current tree is: "<<h4<<std::endl;
    std::cout<<"The balance factor of the current tree is: "<<bf4;
    std::cout<<"\nThe preorder traversal is: ";
    preOrderTraversal(avltreerl);
    std::cout<<"\nThe inorder traversal is: ";
    InOrderTraversal(avltreerl);
    return EXIT_SUCCESS;
}