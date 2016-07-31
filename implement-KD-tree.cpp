//http://www.geeksforgeeks.org/k-dimensional-tree/
//implement kd-treeconst int k = 2;
//Delete cost is expensive 
 
class KD_tree {
	//basic node implementation 
	struct Node
	{
	    int point[k]; // To store k dimensional point
	    Node *left, *right;
	};
	struct Node* newNode(int arr[])
	{
	    struct Node* temp = new Node;
	 
	    for (int i=0; i<k; i++)
	       temp->point[i] = arr[i];
	 
	    temp->left = temp->right = NULL;
	    return temp;
	}
	 
	// Inserts a new node and returns root of modified tree
	// The parameter depth is used to decide axis of comparison
	Node *insertRec(Node *root, int point[], unsigned depth)
	{
	    // Tree is empty?
	    if (root == NULL)
	       return newNode(point);
	 
	    // Calculate current dimension (cd) of comparison
	    unsigned cd = depth % k;
	 
	    // Compare the new point with root on current dimension 'cd'
	    // and decide the left or right subtree
	    if (point[cd] < (root->point[cd]))
	        root->left  = insertRec(root->left, point, depth + 1);
	    else
	        root->right = insertRec(root->right, point, depth + 1);
	    return root;
	}
	Node* insert(Node *root, int point[])
	{
	    return insertRec(root, point, 0);
	}
	
	// Searches a Point represented by "point[]" in the K D tree.
	// The parameter depth is used to determine current axis.
	bool searchRec(Node* root, int point[], unsigned depth)
	{
	    // Base cases
	    if (root == NULL)
	        return false;
	    if (arePointsSame(root->point, point))
	        return true;
	 
	    // Current dimension is computed using current depth and total
	    // dimensions (k)
	    unsigned cd = depth % k;
	 
	    // Compare point with root with respect to cd (Current dimension)
	    if (point[cd] < root->point[cd])
	        return searchRec(root->left, point, depth + 1);
	 
	    return searchRec(root->right, point, depth + 1);
	}
	 
	bool search(Node* root, int point[])
	{
	    // Pass current depth as 0
	    return searchRec(root, point, 0);
	} 

	// A utility method to determine if two Points are same
	// in K Dimensional space
	bool arePointsSame(int point1[], int point2[])
	{
	    // Compare individual pointinate values
	    for (int i = 0; i < k; ++i)
	        if (point1[i] != point2[i])
	            return false;
	 
	    return true;
	}

	// Recursively finds minimum of d'th dimension in KD tree
	// The parameter depth is used to determine current axis.
	int findMinRec(Node* root, int d, unsigned depth)
	{
	    // Base cases
	    if (root == NULL)
	        return INT_MAX;
	 
	    // Current dimension is computed using current depth and total
	    // dimensions (k)
	    unsigned cd = depth % k;
	 
	    // Compare point with root with respect to cd (Current dimension)
	    if (cd == d)
	    {
	        if (root->left == NULL)
	            return root->point[d];
	        return findMinRec(root->left, d, depth+1);
	    }
	 
	    // If current dimension is different then minimum can be anywhere
	    // in this subtree
	    return min(root->point[d],
	               findMinRec(root->left, d, depth+1),
	               findMinRec(root->right, d, depth+1));
	}
	 
	// A wrapper over findMinRec(). Returns minimum of d'th dimension
	int findMin(Node* root, int d)
	{
	    // Pass current level or depth as 0
	    return findMinRec(root, d, 0);
	}

	// Function to delete a given point 'point[]' from tree with root
	// as 'root'.  depth is current depth and passed as 0 initially.
	// Returns root of the modified tree.
	Node *deleteNodeRec(Node *root, int point[], int depth)
	{
	    // Given point is not present
	    if (root == NULL)
	        return NULL;
	 
	    // Find dimension of current node
	    int cd = depth % k;
	 
	    // If the point to be deleted is present at root
	    if (arePointsSame(root->point, point))
	    {
	        // 2.b) If right child is not NULL
	        if (root->right != NULL)
	        {
	            // Find minimum of root's dimension in right subtree
	            Node *min = findMin(root->right, cd);
	 
	            // Copy the minimum to root
	            copyPoint(root->point, min->point);
	 
	            // Recursively delete the minimum
	            root->right = deleteNodeRec(root->right, min->point, depth+1);
	        }
	        else if (root->left != NULL) // same as above
	        {
	            Node *min = findMin(root->left, cd);
	            copyPoint(root->point, min->point);
	            root->right = deleteNodeRec(root->left, min->point, depth+1);
	        }
	        else // If node to be deleted is leaf node
	        {
	            delete root;
	            return NULL;
	        }
	        return root;
	    }
	 
	    // 2) If current node doesn't contain point, search downward
	    if (point[cd] < root->point[cd])
	        root->left = deleteNodeRec(root->left, point, depth+1);
	    else
	        root->right = deleteNodeRec(root->right, point, depth+1);
	    return root;
	}
	 
	// Function to delete a given point from K D Tree with 'root'
	 Node* deleteNode(Node *root, int point[])
	{
	   // Pass depth as 0
	   return deleteNodeRec(root, point, 0);
	}
};


/**  test Cases **/

// Driver program to test above functions
// int main()
// {
//     struct Node *root = NULL;
//     int points[][k] = {{3, 6}, {17, 15}, {13, 15}, {6, 12},
//                        {9, 1}, {2, 7}, {10, 19}};
 
//     int n = sizeof(points)/sizeof(points[0]);
 
//     for (int i=0; i<n; i++)
//        root = insert(root, points[i]);
 
//     int point1[] = {10, 19};
//     (search(root, point1))? cout << "Found\n": cout << "Not Found\n";
 
//     int point2[] = {12, 19};
//     (search(root, point2))? cout << "Found\n": cout << "Not Found\n";
 
//     return 0;
// }