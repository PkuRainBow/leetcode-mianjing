

/** 
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

left -> right -> root : post order traversal of the tree  (bottom to up)**/

/** have one more child parameters to add the child node the tree **/

int findLargestBSTSubtree(BinaryTree *p, int &min, int &max, 
                   int &maxNodes, BinaryTree *& largestBST) {
  if (!p) return 0;
  bool isBST = true;
  /** left sub tree **/
  int leftNodes = findLargestBSTSubtree(p->left, min, max, maxNodes, largestBST);
  int currMin = (leftNodes == 0) ? p->data : min;
  if (leftNodes == -1 || 
     (leftNodes != 0 && p->data <= max))
    isBST = false;

  /** right sub tree **/
  int rightNodes = findLargestBSTSubtree(p->right, min, max, maxNodes, largestBST);
  int currMax = (rightNodes == 0) ? p->data : max;
  if (rightNodes == -1 || 
     (rightNodes != 0 && p->data >= min))
    isBST = false;

  /** root tree **/
  if (isBST) {
    min = currMin;
    max = currMax;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = p;
    }
    return totalNodes;
  } 
  else {
    return -1;   // This subtree is not a BST
  }
}

BinaryTree* findLargestBSTSubtree(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  int min = 0, max = 0;
  int maxNodes = INT_MIN;
  findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
  return largestBST;
}


/** 
Given a binary tree, find the largest Binary Search Tree (BST), 
where largest means BST with largest number of nodes in it. 
The largest BST may or may not include all of its descendants.

root -> left -> right (top to down method)

**/

int findLargestBST(BinaryTree *p, int min, int max, int &maxNodes, 
                   BinaryTree *& largestBST, BinaryTree *& child) {
  if (!p) return 0;
  if (min < p->data && p->data < max) {
    int leftNodes = findLargestBST(p->left, min, p->data, maxNodes, largestBST, child);
    BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;
    int rightNodes = findLargestBST(p->right, p->data, max, maxNodes, largestBST, child);
    BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;

    /** create the root node **/
    // create a copy of the current node and 
    // assign its left and right child.
    BinaryTree *parent = new BinaryTree(p->data);
    parent->left = leftChild;
    parent->right = rightChild;
    // pass the parent as the child to the above tree.
    child = parent;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = parent;
    }
    return totalNodes;
  } else {
    // include this node breaks the BST constraint,
    // so treat this node as an entirely new tree and 
    // check if a larger BST exist in this tree
    findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
    // must return 0 to exclude this node
    return 0;
  }
}

BinaryTree* findLargestBST(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  BinaryTree *child;
  int maxNodes = INT_MIN;
  findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
  return largestBST;
}