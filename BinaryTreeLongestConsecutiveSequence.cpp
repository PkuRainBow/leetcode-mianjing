public class Solution {
    public int longestConsecutive(TreeNode root) {
        return (root==null)?0:Math.max(dfs(root.left, 1, root.val), dfs(root.right, 1, root.val));
    }
    
    public int dfs(TreeNode root, int count, int val){
        if(root==null) return count;
        count = (root.val - val == 1)?count+1:1;
        int left = dfs(root.left, count, root.val);
        int right = dfs(root.right, count, root.val);
        return Math.max(Math.max(left, right), count);
    }
};

/** implementation  method 1 **/
int max = 0;
void helper(TreeNode* root, int target, int count) {
    if (root == nullptr) return;
    if (root->val == target) {
        count++;
    }
    else {
        count = 1;
    }
    max = max(max, count);
    helper(root->left, root->val + 1, count);
    helper(root->right, root->val + 1, count);
}

int longestConsecutive(TreeNode* root) {
    if (root == nullptr) return 0;
    helper(root, root->val + 1, 1);
    return max;
}

/** implementation method 2 **/
int helper(TreeNode* root, int target, int count) {
    if (root == nullptr) return 1;
    count = root->val == target ? count + 1 : 1;
    int left = help(root->left, root->val + 1, count);
    int right = help(root->right, root->val + 1, count);
    return max(max(left, right), count);
}

int longestConsecutive(TreeNode* root) {
    if (root == nullptr)  return 0;
    return max(helper(root->left, root->val + 1, 1), helper(root->right, root->val + 1, 1));
}


/*** the path could include the path from root to leaf also could be leaf to root **/
/**
longest consective increasing sequence in binary tree.(start point happen anywhere in the node, not necessary start from root)

1. 从左子树到当前节点到右子树的连续递增序列，
2. 或者左子树到根到右子树的连续递减序列。
所以要知道4个值 ： 
    1. 一个是左子树连续递增的序列的count，
    2. 一个是左子树连续递减的序列的count，
    3. 右子树连续递增序列的count
    4. 和右子树连续递减的count。

左子树连续递增count ＋ 当前节点＋ 右子树连续递减count ＝左子树到根到右子树的连续递减序列
左子树连续递减count ＋ 当前节点 ＋ 右子树连续递增count ＝ 左子树到根到右子树的连续递增序列

left_big : the increasing sequence starting from the root node in the left sub tree
left_small :　the decreasing sequence starting from the root node in the right sub tree

**/

int longestConsecutive2(TreeNode* root) {
    if (root == nullptr) return 0;
    int left = 0, left_big = 0,  left_small = 0;
    int right = 0, right_bit = 0, right_small = 0;
    dfs(root->left, root->val, left, left_big, left_small, root->val);
    dfs(root->right, root->val, right, right_big, right_small, root->val);
    int result = max(left, right, left_big + 1 + right_small, right_big + 1 + left_small);
    return result;
}

void dfs(TreeNode* root, int val, int& cnt, int& cnt_big, int& cnt_small, int prev_val) {
    if (root == nullptr) {
        cnt = 0;
        cnt_big = 0;
        cnt_small = 0;
        return;
    }

    int cnt_left, cnt_right, cnt_left_big, cnt_left_small, cnt_right_big, cnt_right_small;
    dfs(root->left, root->val, cnt_left, cnt_left_big, cnt_left_small, root->val);
    dfs(root->right, root->val, cnt_right, cnt_right_big, cnt_right_small, root->val);

    int result = max(cnt_left, cnt_right, cnt_left_big + 1 + cnt_right_small, cnt_right_big + 1 + cnt_left_small);

    if(root->val == prev_val + 1) {
        cnt = result;
        cnt_big = max(cnt_left_big, cnt_right_big) + 1;
        cnt_small = 0;
        return;
    }
    else if (root->val == prev_val - 1) {
        cnt = result;
        cnt_big = 0;
        cnt_small = max(cnt_left_small, cnt_right_small) + 1;
        return;
    }
    else {
        cnt = result;
        cnt_big = 0;
        cnt_small = 0;
        return;
    }
}