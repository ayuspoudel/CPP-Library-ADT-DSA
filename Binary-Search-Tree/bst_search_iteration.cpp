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
		void inorderTraversal();

	private:
		BNode* root;
		BNode* insert(BNode* node, int n);
		void preorderTraversal(BNode* root);
		void inorderTraversal(BNode* root);
};

BNode* BSTree::search(int n){
	BNode* pointer;
	pointer = this->root;
	while(pointer!=nullptr){
		if(pointer->elem == n){
			return pointer;
		}
		else if(pointer->elem > n){
			pointer = pointer->left;
		}
		else{
			pointer = pointer->right;
		}
	}
	return nullptr;
}

BNode* BSTree::insert(BNode* node, int n) {
	BNode* newNode = new BNode(n);
	if(node ==nullptr){
		return newNode;
	}
	BNode* slow = nullptr;
	BNode* fast = node;
	while(fast!=nullptr){
		slow = fast;
		if(fast->elem<n){
			fast = fast->right;
		}
		else if(fast->elem>n){
			fast = fast->left;
		}
		else{
			std::cout<<"The value is already in the tree"<<std::endl;
			return node;
		}
	}
	if(n<slow->elem){
		slow->left = newNode;
	}
	else{
		slow->right = newNode;
	}
	return node;
}

// BNode* BSTree::insert(BNode* node, int n){
// 	BNode* newNode = new BNode(n);
// 	if(node == nullptr){
// 		return newNode;
// 	}
// 	else if(node->elem >n){
// 		node->left = insert(node->left,n);
// 	}
// 	else if(node->elem<n){
// 		node->right = insert(node->right, n);
// 	}
// 	return node;
// }
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
	std::cout<<std::endl;
}

void BSTree::inorderTraversal(BNode* root){
	if(root == nullptr){return;}
	std::stack<BNode*> pointerstack;
	BNode* pointer;
	pointer = root;
	while(pointer!=nullptr||!pointerstack.empty()){
		if(pointer!=nullptr){
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
void BSTree::inorderTraversal() {
    inorderTraversal(root);
}

void BSTree::preorderTraversal() {
    preorderTraversal(root);
}

int main() {
    BSTree* newSearchTree = new BSTree();
    newSearchTree->insert(9);
    newSearchTree->insert(15);
    newSearchTree->insert(5);
    newSearchTree->insert(20);
    newSearchTree->insert(16);
    newSearchTree->insert(8);
    newSearchTree->insert(12);
    newSearchTree->insert(3);
    newSearchTree->insert(6);
    newSearchTree->preorderTraversal();
	newSearchTree->inorderTraversal();
	if(newSearchTree->search(50)){
		std::cout<<"Found 40";
	} else{
		std::cout<<"40 not found";
	}
	std::cout<<std::endl;
    return EXIT_SUCCESS;
}
