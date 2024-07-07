#include<cstdlib>
#include<string>
#include<stack>
#include<queue>
#include<iostream>
class BNode{
	public:
		BNode():elem(-1), left(nullptr), right(nullptr){};
		BNode(int n): elem(n), left(nullptr), right(nullptr){};
		~BNode(){};
		void print(){std::cout<<this->elem<<std::endl;};
	private:
		int elem;
		BNode* left;
		BNode* right;
		friend class BSTree;
};
class BSTree{
	public:
		BSTree():root(nullptr){};
		BSTree(int n): root(new BNode(n)){};
		~BSTree(){};
		void insert(BNode*, int n);
		BNode* search(int n);
	private:
		BNode* root;
};
void BSTree::insert(BNode* node, int n){
	BNode* newNode = new BNode(n);
	if(node == nullptr){
		node = newNode;
		return;
	}
	BNode* pointer = node;
	if(n>pointer->elem){
		insert(pointer->right, n);
	}
	if(n<pointer->elem){
		insert(pointer->left, n);
	}
	return;
	}
int main(){
	
	return EXIT_SUCCESS;
}
