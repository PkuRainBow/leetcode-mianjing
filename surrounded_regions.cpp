class Solution {
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()<=1 || board[0].size()<=1) return;
        
        int m=board.size(), n=board[0].size();
        deque<pair<int, int>> q;
        for(int i=0; i<n; i++){
            if(board[0][i]=='O')   q.push_back(make_pair(0, i));
            if(board[m-1][i]=='O') q.push_back(make_pair(m-1, i));
        }
        for(int i=1; i<m-1; i++){
            if(board[i][0]=='O')   q.push_back(make_pair(i, 0));
            if(board[i][n-1]=='O') q.push_back(make_pair(i, n-1));
        }
        
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop_front();
            //mark as the special character 
            board[temp.first][temp.second] = 'N';
            for (auto dir : dirs) {
                int x = temp.first + dir[0];
                int y = temp.second + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                    q.push_back(make_pair(x, y));
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'N') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        return;
    }
};