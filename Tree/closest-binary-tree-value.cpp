/**
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
 
 **/

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        //just compare all the possible value along the path
        while (root) {
            if (abs(res - target) >= abs(root->val - target)) {
                res = root->val;
            }
            root = target < root->val ? root->left : root->right;
        }
        return res;
    }
};


class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        TreeNode *t = target < a ? root->left : root->right;
        if (!t) return a;
        int b = closestValue(t, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};

/**
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
**/

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res, v;
        inorder(root, v);
        int idx = 0;
        double diff = numeric_limits<double>::max();
        //find the nearest value to the target value
        for (int i = 0; i < v.size(); ++i) {
            if (diff >= abs(target - v[i])) {
                diff = abs(target - v[i]);
                idx = i;
            }
        }
        int left = idx - 1, right = idx + 1;
        for (int i = 0; i < k; ++i) {
            res.push_back(v[idx]);
            //from both side choose the smaller value 
            if (left >= 0 && right < v.size()) {
                if (abs(v[left] - target) > abs(v[right] - target)) {
                    idx = right;
                    ++right;
                } else {
                    idx = left;
                    --left;
                }
            } else if (left >= 0) {
                idx = left;
                --left;
            } else if (right < v.size()) {
                idx = right;
                ++right;
            }
        }
        return res;
    }
    void inorder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};


class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int>> q;
        inorder(root, target, k, q);
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &q) {
        if (!root) return;
        inorder(root->left, target, k, q);
        q.push({abs(root->val - target), root->val});
        if (q.size() > k) q.pop();
        inorder(root->right, target, k, q);
    }
};

/** the solution that implement 2 interfaces **/

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<TreeNode*> pre, suc;
        while (root) {
            if (root->val <= target) {
                pre.push(root);
                root = root->right;
            } else {
                suc.push(root);
                root = root->left;
            }
        }
        while (k-- > 0) {
            if (suc.empty() || !pre.empty() && target - pre.top()->val < suc.top()->val - target) {
                res.push_back(pre.top()->val);
                getPredecessor(pre);
            } else {
                res.push_back(suc.top()->val);
                getSuccessor(suc);
            }
        }
        return res;
    }
    void getPredecessor(stack<TreeNode*> &pre) {
        TreeNode *t = pre.top(); pre.pop();
        if (t->left) {
            pre.push(t->left);
            while (pre.top()->right) pre.push(pre.top()->right);
        }
    }
    void getSuccessor(stack<TreeNode*> &suc) {
        TreeNode *t = suc.top(); suc.pop();
        if (t->right) {
            suc.push(t->right);
            while (suc.top()->left) suc.push(suc.top()->left);
        }
    }
};