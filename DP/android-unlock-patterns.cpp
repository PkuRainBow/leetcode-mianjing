class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int result = 0;
        vector<bool> visited(10, false);
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;
        result += dfs(1, 1, 0, m, n, jumps, visited) * 4;
        result += dfs(2, 1, 0, m, n, jumps, visited) * 4;
        result += dfs(5, 1, 0, m, n, jumps, visited);
        return result;
    }

    int dfs(int num, int len, int res, int m, int n, vector<vector<int>> &jumps, vector<bool> &visited) {
        if (len >= m) res++;
        len++;
        if (len > n) return res;
        visited[num] = true;
        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                result = dfs(next, len, result, m, n, jumps, visited);
            }
        }
        visited[num] = false;
        return result;
    }
}; 


// solution pattern by fff 

class Solution {
public:
    int dfs(vector<vector<int>>& skip, vector<bool>& visit, int remain, int cur) {
        if (remain == 0) return 1;
        visit[cur] = true;
        int count = 0;
        for (int i = 1; i <= 9; i++) {
            if (visit[i]) continue;
            if (skip[cur][i] == 0 || visit[skip[cur][i]]) {
                count += dfs(skip, visit, remain - 1, i);
            }
        }
        visit[cur] = false;
        return count;
    }

    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10,vector<int>(10,0));
        skip[1][3] = skip[3][1] = 2;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[1][9]=skip[9][1]=skip[2][8]=skip[8][2]=skip[3][7]=skip[7][3]=skip[4][6]=skip[6][4]=5;
        int number = 0;
        vector<bool> visit(10,false);
        visit[0] = true;
        for (int length = m; length <= n; length ++) {
            number += dfs(skip, visit, length-1, 2) * 4;
            number += dfs(skip, visit, length-1, 1) * 4;
            number += dfs(skip, visit, length-1, 5);
        }
        return number;
    }
};