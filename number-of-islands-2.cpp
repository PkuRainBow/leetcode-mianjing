class Solutions {
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        roots = vector<int>(m * n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        for (auto pos : positions) {
            int x = pos.first, y = pos.second, idx_p = x * n + y;
            roots[idx_p] = idx_p;
            ++island;
            for (auto dir : dirs) {
                int row = x + dir.first, col = y + dir.second, idx_new = row * n + col;
                if (row >= 0 && row < m && col >= 0 && col < n && roots[idx_new] != -1) {
                    int rootNew = findRoot(idx_new), rootPos = findRoot(idx_p);
                    if (rootPos != rootNew) {
                        roots[rootPos] = rootNew;
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }

private:
    vector<int> roots;
    int findRoot(int index) {
        while (index != roots[index]) {
            roots[index] = root[root[index]];
            index = roots[index];
        }
        return index;
    }
};


class Solutions2 {
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        roots = vector<int>(m * n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        for (auto pos : positions) {
            int x = pos.first, y = pos.second, idx_p = x * n + y;
            roots[idx_p] = idx_p;
            ++island;
            for (auto dir : dirs) {
                int row = x + dir.first, col = y + dir.second, idx_new = row * n + col;
                //roots[] can check whether the node is island, as the empty node's root is -1
                if (row >= 0 && row < m && col >= 0 && col < n && roots[idx_new] != -1) {
                    int root_new = find(idx_new), root_pos = find(idx_p);
                    if (root_new != root_pos) {
                        roots[root_pos] = root_new;
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }

private:
    vector<int> roots;
    int findRoot(int index) {
        while (index != roots[index])
            index = roots[index];
        return index;
    }
};
