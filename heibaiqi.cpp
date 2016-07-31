void  serialize(TreeNode* root, int N) {
	ostringstream in;
	serialize(root, in);
	return in.str();
}

void serialize(TreeNode* root, ostringstream& in, int N) {
	if(!root)   return;
	in << root->key << " ";
	for(int i = 0; i < N && root->child[i]; i++) {
		serialize(root->child[i], in);
	}
	in << "# ";
}

TreeNode* deserialize(string data) {
	istringstream out(data);
	return deserialize(out);
}

int deserialize(TreeNode *&root, istringstream& data) {
	string temp;
	data >> temp;
	if(temp == "#") {
		return 1;
	}
	/** the child node is nullptr default **/
	root = new TreeNode(stoi(temp));
	for(int i = 0; i < N; i++) {
		if(deserialize(root->child[i], data))
		break;
	}
	return 0;
}