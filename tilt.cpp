#include<iostream>
#include<cstdlib>
#include<cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int tilt(TreeNode* root, int* totaltilt){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return root->val;
    }
    int ltilt = tilt(root->left, totaltilt);
    int rtilt = tilt(root->right, totaltilt);
    int nodetilt = std::abs(ltilt - rtilt);
    (*totaltilt) += nodetilt;
    return root->val + ltilt + rtilt;
}
int calculatetilt(TreeNode* root){
    int totaltilt = 0;
    tilt(root, &totaltilt);
    return totaltilt;
}
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    int tilt = calculatetilt(root); 
    std::cout << "Total Tilt: " << tilt << std::endl; // Output should be 15
}
