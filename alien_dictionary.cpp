class Solution {
public:
    string alienOrder(vector<string>& words) {
        set<pair<char, char> > s;   
        unordered_set<char> ch;
        vector<int> in(256, 0);
        queue<char> q;
        string result = "";
        //get the char list
        for (auto a : words) ch.insert(a.begin(), a.end());
        for (int i = 0; i < words.size() - 1; i++) {
            //find the first different chars and get the order of the 2 chars
            for (int j = 0; j < min(words[i].size(), words[i + 1].size()); j++) {
                //insert the edge 
                if (words[i][j] != words[i + 1][j]) {
                    s.insert(make_pair(words[i][j], words[i + 1][j]));
                    break;
                }
            }
        }
        //update the indegree array
        for (auto a : s) ++in[a.second];
        //push all the zero degree node into the queue
        for (auto a : ch) {
            if (in[a] == 0) {
                q.push(a);
                res += a;
            }
        }

        while (!q.empty()) {
            char c = q.front(); q.pop();
            for (auto a : s) {
                if (a.first == c) {
                    --in[a.second];
                    if (in[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }

        return res.size() == ch.size() ? res : "";
    }
};
