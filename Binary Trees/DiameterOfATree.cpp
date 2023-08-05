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

public:
int myFun(TreeNode* root,int &maxi)
{
if(root==nullptr) return 0;
        int lh= myFun(root->left,maxi);
        int lr=myFun(root->right,maxi);
        maxi=max(maxi,lh+lr);
        cout<<maxi;
        return 1+max(lh,lr);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=-1;
        if(root->left==nullptr && root->right==nullptr) return 0;
        int k=myFun(root,maxi);
        return maxi;
        
    }
};