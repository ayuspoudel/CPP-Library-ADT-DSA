#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool evaluateExpression(TreeNode* root) {
    if(root == nullptr){
        return false;
    }
    if(root->left == nullptr && root->right == nullptr){
        return root->val == 1;
    }
    bool lvalue = evaluateExpression(root->left);
    bool rvalue = evaluateExpression(root->right);
    if(root->val == 2){
        return lvalue|| rvalue;
    }
    if(root->val == 3){
        return lvalue && rvalue;
   }
   return false;
}
    
int main() {
    TreeNode* root = new TreeNode(2); // OR
    root->left = new TreeNode(1); // True
    root->right = new TreeNode(3); // AND
    root->right->left = new TreeNode(0); // False
    root->right->right = new TreeNode(1);

    bool result = evaluateExpression(root);

    cout << "Result: " << result << endl;
    return 0;
}