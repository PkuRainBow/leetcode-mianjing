class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dict;
        return help(root, dict);
    }
    
    int help(TreeNode* root, unordered_map<TreeNode*, int>& dict) {
        if(root == NULL)  return 0;
        if(dict.find(root)!=dict.end())  return dict[root];
        int val = 0;
        if(root->left != NULL) {
            val += help(root->left->left, dict) + help(root->left->right, dict);
        }
        if(root->right != NULL) {
            val += help(root->right->left, dict) + help(root->right->right, dict);
        }
        val = max(val + root->val, help(root->left, dict) + help(root->right, dict));
        dict[root] = val;
        return val;
    }
};


class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = help(root);
        return max(result[0], result[1]);
    }
    /**
     * result[0] : record the max sum exclude the root value
     * result[1] : record the max sum include the root value
     **/
    vector<int> help(TreeNode* root) {
        vector<int> result(2, 0);
        if (!root) {
            return result;
        }
        vector<int> left = help(root->left);
        vector<int> right = help(root->right);
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        result[1] = root->val + left[0] + right[0];
        return result;
    }
};