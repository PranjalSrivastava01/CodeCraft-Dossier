/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       int p1=p->val;
       int q1=q->val;
        while(root)
        {
            int r=root->val;
            if(r>p1 && r>q1) root=root->left;
            else if(r<p1 && r<q1) root=root->right;
            else return root;
        }
        return root;
    }
};