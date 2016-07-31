//基本思路是遍历所有的位置是1 （建筑物）的点，然后从当前建筑物开始BFS访问所有的空的位置，改变他们的值减去1，然后他们的距离统计在sum 矩阵中，这样我们最后一次的时候就会得到
// 到达所有建筑物最近的点的距离总和是多少

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int result = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sum = grid;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) {
                    result = INT_MAX;
                    vector<vector<int>> dist = grid;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()) {
                        int i = q.front().first, j = q.front().second;
                        q.pop();
                        for (int k = 0; k < dirs.size(); k++) {
                            int x = i + dirs[k][0], y = j + dirs[k][1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
                                --grid[x][y];
                                dist[x][y] = dist[i][j] + 1;
                                sum[x][y] += dist[x][y] - 1;
                                q.push({x, y});
                                result = min(result, sum[x][y]);
                            }
                        }
                    }
                }
                --val;
            }
        }
    }
};