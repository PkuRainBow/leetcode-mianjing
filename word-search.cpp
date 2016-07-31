class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)  return false;
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(help(board, i, j, 0, word))  return true;
            }
        }
        return false;
    }
    
    bool help(vector<vector<char>>& board, int i, int j, int len, string word){ 
        if (len == word.size())  return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())  return false;
        if(board[i][j]!=word[len] || board[i][j]=='*')  return false;
        char ch=board[i][j];
        board[i][j]='*';
        bool result= help(board, i+1, j, len+1, word) ||
                     help(board, i-1, j, len+1, word) ||
                     help(board, i, j+1, len+1, word) ||
                     help(board, i, j-1, len+1, word);
        board[i][j]=ch;
        return result;
    }
};

// use prefix tree 

const int MAX_CHARS=26;

class TrieNode{
    public:
        TrieNode(string s) : isWord(false), word(s) {
            memset(children, 0, sizeof(children));
        }
    public:
        /*** store-the-root-cur-pos-word ***/
        string word;
        bool isWord;
        TrieNode* children[MAX_CHARS];
};

class TrieTree{
    public:
        TrieTree():root(new TrieNode("")) {}
        ~TrieTree(){ freeTree(root); }
        TrieNode* getRoot(){
            return root;
        }
        
        void addWord(string& s){
            TrieNode* node=root;
            string t;
            for(int i=0; i<s.size(); i++){
                t+=s[i];
                if(node->children[s[i]-'a']==NULL){
                    node->children[s[i]-'a']=new TrieNode(t);
                }
                node=node->children[s[i]-'a'];
            }
            node->isWord=true;
        }
    private:
        void freeTree(TrieNode* node){
            for(int i=0; i<MAX_CHARS; i++){
                if(node->children[i]!=NULL){
                    freeTree(node->children[i]);
                }
            }
            delete node;
        }
        TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieTree t;
        for(int i=0; i<words.size(); i++)   t.addWord(words[i]);
        vector<string> result;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                help(board, t.getRoot(), i, j, result);
            }
        }
        return result;
    }
    
    void help(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result){
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]=='*')  return;
        char ch=board[row][col];
        root=root->children[ch-'a'];
        if(root==NULL)   return;
        if(root->isWord){
            result.push_back(root->word);
            root->isWord=false;
        }
        board[row][col]='*';
        help(board, root, row+1, col, result);
        help(board, root, row-1, col, result);
        help(board, root, row, col+1, result);
        help(board, root, row, col-1, result);
        board[row][col]=ch;
    }
};