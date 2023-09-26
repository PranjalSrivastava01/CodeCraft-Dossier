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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        if(!root) return 0;
        q.push({root,0});
        
        long long int ans=0;
        while(!q.empty())
        {
            long long int leftmost=0,rightmost=0;
            long long int size=q.size();
            long long int curr_min=q.front().second;
            for(int i=0;i<size;i++)
            {
            TreeNode* temp=q.front().first;
            long long int curr_id=q.front().second-curr_min;
            q.pop();
            if(i==0) leftmost=curr_id;
            if(i==size-1) rightmost=curr_id;
            if(temp->left)
            {
                q.push({temp->left,curr_id*2+1});
            }
            if(temp->right)
            {
                q.push({temp->right,curr_id*2+2});
            }
            }
            ans=max(ans,rightmost-leftmost+1);
        }
        return ans;
    }
};