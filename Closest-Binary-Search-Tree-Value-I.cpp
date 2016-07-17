/**
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Note: Given target value is a floating point. You are guaranteed to have only one unique value in the BST that is closest to the target.
**/
/** my original solution **/
class Solution {
	int close_val = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) {
    	if (!root)  return INT_MAX;
    	if (abs(root->val - target) < abs(target - close_val)) {
    		close_val = root->val;
    	}
    	int diff_left = closestValue(root->left, target);
    	int diff_right = closestValue（root->right, target);
		if (abs(root->diff_left - target) < abs(target - close_val)) {
			close_val = root->val;
		}
		if (abs(root->diff_right - target) < abs(target - close_val)) {
			close_val = root->val;
		}
		return close_val;
    }
};


class Solution_iterative {
public:
    int closestValue(TreeNode* root, double target) {
    	int result = root->val;
    	while (root) {
    		if (abs(target - root->val) < abs(target, result)) {
    			result = root->val;
    		}
    		root = root->val > target ? root->left : root->right;
    	}
    	return result;
    }
};


class Solution_recursive {
public:
    int closestValue(TreeNode* root, double target) {
    	int a = root->val;
    	auto kid = target < a ? root->left : root->right ;
    	if (!kid) = return a;
    	int b = closestValue(kid, target);
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
        for (int i = 0; i < v.size(); ++i) {
            if (diff >= abs(target - v[i])) {
                diff = abs(target - v[i]);
                idx = i;
            }
        }
        int left = idx - 1, right = idx + 1;
        for (int i = 0; i < k; ++i) {
        	res.push_back(v[idx]);
        	if (left >= 0 && right < v.size()) {
        		if (abs(v[left]-target) > abs(v[right]-target)) {
        			idx = right;
        			right++;
        		}
        		else {
        			idx = left;
        			left--;
        		}
        	}
        	else if (left >= 0) {
        		idx = left;
        		--left;
        	}
        	else if (right < v.size()) {
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
        inorder(root, target, k, res);
        return res;
    }
    void inorder(TreeNode *root, double target, int k, vector<int> &res) {
    	if (!root) return;
    	inorder(root->left, target, k, res);
    	if (res.size() < k) res.push_back(root->val);
    	
    }
};

