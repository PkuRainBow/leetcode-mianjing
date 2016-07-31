class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        dfs(s, 0, "", result);
        return result;
    }
    
    void dfs(string s, int n, string out, vector<string>& result) {
        if (n == 4) {
            if (s.empty()) result.push_back(out);
        }
        else {
            //current number must be 1/2/3 number consisted of
            for (int k = 1; k < 4; k++) {
                if (s.size() < k) break;
                int val = stoi(s.substr(0, k));
                if (val > 255 || k != std::to_string(val).size()) continue;
                dfs(s.substr(k), n + 1, out + s.substr(0, k) + (n == 3 ? "" : "."), result);
            }
        }
    }
};