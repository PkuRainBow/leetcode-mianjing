/**

完全二叉树 parent是孩子中的最小值，请找出整棵树第二小的值 example: * 2 * / \ * 2 3 * / \ | \ * 4 2 5 3 * In this given tree the answer is 3.

链接: https://instant.1point3acres.com/thread/180631
来源: 一亩三分地

**/

class Solution {
	int findSecond(TreeNode* root) {
		if (root->child.size() == 0)  return INT_MAX;
		int cur_second = 0;
		TreeNode* minNode = nullptr;
		TreeNode* secNode = nullptr;
		for (int i = 0; i < root->child.size(); i++) {
			if (root->child[i].val == root->val) {
				minNode = root->child[i];
			}
			else {
				if (secNode == nullptr) {
					secNode = root->children[i];
				}
				else {
					secNode = secNode->val < root->children[i]->val ? secNode : root->children[i];
				}
			}
		}
		return min(findSecond(minNode), secNode->val);
	}
}