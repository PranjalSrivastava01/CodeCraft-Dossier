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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //using level order traversal
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>m;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto i=q.front();
            q.pop();
            TreeNode* x=i.first;//node
            int y=i.second.first;//vertical
            int z=i.second.second;//level
            m[y][z].insert(x->val);
            if(x->left)
            {
               q.push({x->left,{y-1,z+1}});
            }
            if(x->right)
            {
              q.push({x->right,{y+1,z+1}});
            }

        }
        vector<vector<int>>res;
        for(auto i:m)
        {
            vector<int>temp;
            for(auto j:i.second)
            {
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            }
            res.push_back(temp);
        }
        return res;
        
    }
};