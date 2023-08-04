/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int myFun(TreeNode* root)
{    if(root == nullptr) return 0;
    int lh=myFun(root->left);
    int lr=myFun(root->right);
    if(lh==-1 || lr==-1) return -1;
    if(abs(lh-lr)>1) return -1;
    return max(lh,lr)+1;}
public:
    bool isBalanced(TreeNode* root) {
        int k=myFun(root);
        if(k==-1) return false;
        return true;
    }
};