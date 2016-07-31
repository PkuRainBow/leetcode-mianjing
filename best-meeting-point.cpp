class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return help(rows) + help(cols);
    }
    int help(vector<int> v) {
        int result = 0;
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        while (i < j)  result += v[j--] - v[i++];
        return result;
    }
};

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        int res = 0, i = 0, j = rows.size() - 1;
        while (i < j) res += rows[j] - rows[i] + cols[j--] - cols[i++];
        return res;
    }
};