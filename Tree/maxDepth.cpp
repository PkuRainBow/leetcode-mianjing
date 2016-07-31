int maxDepthIterative(TreeNode* root) {
	if (!root) return 0;
	stack<TreeNode*> s;
	s.push(root);
	int result = 0;
	TreeNode* prev = nullptr;
	while (!s.empty()) {
		TreeNode* cur = s.top();
		if (!prev || prev->left == cur || prev->right == cur) {
			if (cur->left) {
				s.push(cur->left);
			}
			if (cur->right) {
				s.push(cur->right);
			}
		}
		else if (cur->left == prev) {
			if (cur->right) 
				s.push(cur->right);
		} else {
			s.pop();
		}
		prev = cur;
		if (s.size() > result) {
			result = s.size();
		}
	}
	return result;
}