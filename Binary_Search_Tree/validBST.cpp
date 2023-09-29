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
    bool isValidBST2(TreeNode* root, long long maxValue, long long minValue) {
        if (root == NULL) return true;
        if (root->val <= minValue || root->val >= maxValue) return false;
        return isValidBST2(root->left, root->val, minValue) && isValidBST2(root->right, maxValue, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST2(root, LLONG_MAX, LLONG_MIN);
    }
};
