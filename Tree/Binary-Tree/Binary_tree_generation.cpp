#include<queue>
#include<iostream>
#include<cstdlib>
#include<exception>
struct TNode{
    int elem;
    TNode* rchild;
    TNode* lchild;
};

struct TNode* generate_binary_tree(){
    std::queue<TNode*> address_q;
    struct TNode* p;
    
    struct TNode* root = (TNode*)malloc(sizeof(struct TNode));
        if(root == nullptr){
            std::cout<<"Memory allocation failed.\n";
            throw std::runtime_error("Memory Allocation failed");
        }
    std::cout<<"Enter the root value: ";
    int x;
    std::cin>>x;
    root->elem = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    address_q.push(root);
    while(!address_q.empty()){
        p = address_q.front();
        address_q.pop();
        std::cout<<"Enter the Left value of "<<p->elem<<": ";
        std::cin>>x;
        if(x !=-1){
            struct TNode* child = new TNode;
            child->elem = x;
            child->lchild = nullptr;
            child->rchild = nullptr;
            p->lchild = child;
            address_q.push(child);
        }
        std::cout<<"Enter the Right value: "<<p->elem<<": ";
        std::cin>>x;
        if(x !=-1){
            struct TNode* child = new TNode;
            child->elem = x;
            child->lchild = nullptr;
            child->rchild = nullptr;
            p->rchild = child;
            address_q.push(child);
        }
    }
    return root;
}

void preorder(const TNode* s){
    if(s == nullptr){
        return;
    }
    std::cout<<s->elem<<" ";
    preorder(s->lchild);
    preorder(s->rchild);
}
void postorder(const TNode* s){
    if(s == nullptr){
        return;
    }
    postorder(s->lchild);
    postorder(s->rchild);
    std::cout<<s->elem<<" ";
}
void inorder(const TNode* s){
    if(s == nullptr){
        return;
    }
    inorder(s->lchild);
    std::cout<<s->elem<<" ";
    inorder(s->rchild);
}


int main(){
    struct TNode* binary_tree = generate_binary_tree();
    std::cout<<"Pre-order Traversal: ";
    preorder(binary_tree);
    std::cout<<"Post-order Traversal: ";
    postorder(binary_tree);
    std::cout<<"In-order Traversal: ";
    inorder(binary_tree);
    return 0;
}