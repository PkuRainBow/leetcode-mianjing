class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    int helper(TreeNode *root, vector<vector<int>> &res) {
        if (!root) return 0;
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));
        if (depth >= res.size()) res.push_back(vector<int>());
        res[depth - 1].push_back(root->val);
        return depth;
    }
};

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    int helper(TreeNode *root, vector<vector<int>> &res) {
        if (!root) return 0;
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));
        if (depth >= res.size()) res.push_back(vector<int>());
        res[depth - 1].push_back(root->val);
        return depth;
    }
};