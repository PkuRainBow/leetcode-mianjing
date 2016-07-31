class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; i++) {
            int highBit = 1 << i;
            int len = res.size();
            for (int j = len - 1; j >= 0; --j) {
                res.push_back(highBit + res[j]);
            }
        }
        return res;
    }
};