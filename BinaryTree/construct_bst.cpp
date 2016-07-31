class Solution {
public:
	TreeNode* constructBSTfromPreorder(vector<int> preorder) {
		int min_val = INT_MIN, max_val = INT_MAX;
		int pos = 0;
		return dfs(pos, min_val, max_val, preorder);
	}

	TreeNode* dfs(int& pos, int min_val, int max_val, const vector<int>& preorder) {
		if (pos >= preorder.size())
			return nullptr;
		TreeNode* root = nullptr;
		if (preorder[pos] > min_val && preorder[pos] < max_val) {
			root = new TreeNode(preorder[pos]);
			pos++;
			root->left = dfs(pos, min_val, root->val, preorder);
			root->right = dfs(pos, root->val, max_val, preorder);
		}
		return root;
	}
};

class Solution {
public:
	TreeNode* constructBSTfromPreorder(vector<int> preorder) {
		int pos = 0;
		int size = (int)preorder.size();
		stack<TreeNode*> st;
		TreeNode* root = new TreeNode(preorder[0]);
		st.push(root);
		int i;
		TreeNode* temp;
		for (int i = 1; i < size; i++) {
			if (!st.empty() && preorder[i] < st.top()->val) {
				TreeNode* cur = new TreeNode(preorder[i]);
				st.top()->left = cur;
				st.push(cur);
			}
			else {
				temp = nullptr;
				while (!st.empty() && preorder[i] > st.top()->val) {
					temp = st.top();
					st.pop();
				}
				if (temp != nullptr) {
					temp->right = new TreeNode(preorder[i]);
				}
			}
		}
		return root;
	}
};

