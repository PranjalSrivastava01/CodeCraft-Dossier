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
bool myFun(TreeNode* left,TreeNode* right)
{
    if(left==nullptr || right==nullptr)
    return left==right;
    if(left->val!=right->val)
    {
        return false;
    }
    return myFun(left->left,right->right) && myFun(left->right,right->left);
}
    bool isSymmetric(TreeNode* root) {
        return root==nullptr || myFun(root->left,root->right);
    }
};
// class Solution {
// public:
//     bool myFun(TreeNode* left, TreeNode* right) {
//         if (left == nullptr || right == nullptr)
//             return left == right;

//         if (left->val != right->val) {
//             return false;
//         }

//         return myFun(left->left, right->right) && myFun(left->right, right->left);
//     }

//     bool isSymmetric(TreeNode* root) {
//         return root == nullptr || myFun(root->left, root->right);
//     }
// };
