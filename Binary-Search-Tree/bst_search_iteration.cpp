#include <cstdlib>
#include <iostream>
#include <stack>

class BNode {
public:
    BNode() : elem(-1), left(nullptr), right(nullptr) {}
    BNode(int n) : elem(n), left(nullptr), right(nullptr) {}
    ~BNode() {}
    void print() { std::cout << this->elem << std::endl; }

private:
    int elem;
    BNode* left;
    BNode* right;
    friend class BSTree;
};

class BSTree {
public:
    BSTree() : root(nullptr) {}
    BSTree(int n) : root(new BNode(n)) {}
    ~BSTree() {}
    void insert(int n);
    BNode* search(int n);
    void preorderTraversal();
    BNode* getRoot() { return this->root; }

private:
    BNode* root;
    BNode* insert(BNode* node, int n);
    void preorderTraversal(BNode* root);
};

BNode* BSTree::insert(BNode* node, int n) {
    if (node == nullptr) {
        return new BNode(n);
    }
    if (n > node->elem) {
        node->right = insert(node->right, n);
    } else if (n < node->elem) {
        node->left = insert(node->left, n);
    }
    return node;
}

void BSTree::insert(int n) {
    root = insert(root, n);
}

void BSTree::preorderTraversal(BNode* root) {
    if (root == nullptr) return;
    std::stack<BNode*> pointerStack;
    BNode* pointer = root;
    while (pointer != nullptr || !pointerStack.empty()) {
        while (pointer != nullptr) {
            std::cout << pointer->elem << " ";
            pointerStack.push(pointer);
            pointer = pointer->left;
        }
        pointer = pointerStack.top();
        pointerStack.pop();
        pointer = pointer->right;
    }
}

void BSTree::inorderTraversal(BNode* root){
	
}

void BSTree::preorderTraversal() {
    preorderTraversal(root);
}

int main() {
    BSTree* newSearchTree = new BSTree();
    newSearchTree->insert(10);
    newSearchTree->insert(20);
    newSearchTree->insert(5);
    newSearchTree->insert(30);
    newSearchTree->insert(0);
    newSearchTree->insert(50);
    newSearchTree->preorderTraversal();
    return EXIT_SUCCESS;
}
