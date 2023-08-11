/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
bool isLeaf(TreeNode<int> *root)
{
    if(root->left==NULL)
    {
        if(root->right==NULL) return true;
    }
    return false;
}
void addLeftBoundary(TreeNode<int> *root,vector<int> &res)
{
TreeNode<int> *curr = root->left;
while (curr) {
        if (!isLeaf(curr))
          res.push_back(curr->data);
        if (curr->left)
          curr = curr->left;
        else
          curr = curr->right;
}
}
void addRightBoundary(TreeNode<int> *root,vector<int> &res)
{
stack<int>temp;
TreeNode<int> *curr = root->right;
while (curr) {
        if (!isLeaf(curr))
          temp.push(curr->data);
        if (curr->right)
          curr = curr->right;
        else
          curr = curr->left;
}
while(!temp.empty())
{
    res.push_back(temp.top());
    temp.pop();
}
}
void addLeaves(TreeNode<int> *root,vector<int> &res)
{
    if(root==NULL) return;
    if(isLeaf(root))
    {
        res.push_back(root->data);
    }
    addLeaves(root->left,res);
    addLeaves(root->right,res);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
vector<int>res;
if(!root) return res;
res.push_back(root->data);
addLeftBoundary(root,res);
addLeaves(root,res);
addRightBoundary(root,res);
return res;
}
