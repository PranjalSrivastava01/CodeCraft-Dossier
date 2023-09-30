class BSTIterator {
public:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (!reverse) {
            if (temp->right) pushAll(temp->right);
        } else {
            if (temp->left) pushAll(temp->left);
        }
        return temp->val;
    }

    stack<TreeNode*> st;
    bool reverse;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;
    }
};
