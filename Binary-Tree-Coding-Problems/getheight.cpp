#include<iostream>
#include<cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int getHeight(TreeNode* root){
    if(root == nullptr){
        return -1;
    }
    int lheight = getHeight(root->left)+1;
    int rheight = getHeight(root->right)+1;
    return lheight>rheight?lheight:rheight;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    int height = getHeight(root); //returns 3
    std::cout<<height<<std::endl;
}
