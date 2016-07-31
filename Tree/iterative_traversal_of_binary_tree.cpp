//post order iterative traversal
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (!root) return ans;
	stack<TreeNode*> nodes;
	TreeNode* pre = nullptr;
	nodes.push(root);
	while (!nodes.empty()) {
		root = nodes.top();
		if ((root->left == nullptr) && (root->right == nullptr) ||
				(pre != nullptr && (root->left = pre || root->right == pre))) {
			ans.push_back(root->val);
			nodes.pop();
			pre = root;
		}
		else {
			if (root->right) nodes.push(root->right);
			if (root->left) nodes.push(root->left);
		}
	}
}


//in order iterative traversal
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ans;
	stack<TreeNode*> nodes;
	while (root || !nodes.empty()) {
		while (root) {
			nodes.push(root);
			root = root->left;
		}
		if (!nodes.empty()) {
			root = nodes.top();
			nodes.pop();
			ans.push_back(root->val);
			root = root->right;
		}
	}
}

//post order iterative traversal
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ans;
	if (!root) return ans;
	stack<TreeNode*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		root = nodes.top();
		nodes.pop();
		ans.push_back(root->val);
		if (root->right) nodes.push(root->right);
		if (root->left) nodes.push(root->left);
	}
	return ans;
}

