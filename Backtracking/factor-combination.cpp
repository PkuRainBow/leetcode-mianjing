class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> path;
        helper(n, 2, path, result);
        return result;
    }
    void helper(int remain, int start, vector<int> path, vector<vector<int>> &result) {
        if (remain == 1) {
            if (path.size() > 1) result.push_back(path);
        } else {
            for (int i = start; i <= remain; i++) {
                if (remain%i == 0) {
                    path.push_back(i);
                    helper(remain/i, i, path, result);
                    path.pop_back();
                }
            }
        }
    }
};