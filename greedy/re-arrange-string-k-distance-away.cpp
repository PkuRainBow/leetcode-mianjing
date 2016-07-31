class Solution {
public:
    string rearrangeString(string str, int k) {
        if(k == 0) return str;
        int length = (int)str.size(); 
        string res;
        unordered_map<char, int> dict;
        //max heap
        priority_queue<pair<int, char>> pq;

        //add the char frequency to the array 
        for (char ch : str) dict[ch]++;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            pq.push(make_pair(it->second, it->first));
        }

        while (!pq.empty()) {
            vector<pair<int, char>> cache;
            int count = min(k, length);
            for (int i = 0; i < count; i++) {
                if (pq.empty()) return "";
                auto tmp = pq.top();
                pq.pop();
                res.push_back(tmp.second);
                if (--tmp.first > 0) cache.push_back(tmp);
                length--;
            }
            for(auto p : cache) pq.push(p);
        }
        return res;
    }
};