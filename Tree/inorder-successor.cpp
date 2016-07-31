//DFS solution 
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p) return NULL;
        inorder(root, p);
        return suc;
    }
    void inorder(TreeNode *root, TreeNode *p) {
        if (!root) return;
        inorder(root->left, p);
        //if the previous node is p, then the current node is the next node we want
        if (pre == p) suc = root;
        //update pre to the current node 
        pre = root;
        inorder(root->right, p);
    }
private:
    //user the pre and suc pointer to record the father node and child node 
    TreeNode *pre = NULL, *suc = NULL;
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *res = NULL;
        while (root) {
            if (root->val > p->val) {
                //record the smallest parent value along the path to the p node 
                res = root;
                root = root->left;
            } else root = root->right;
        }
        return res;
    }
};