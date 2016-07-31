// the most easy to understand solution 

// 返回结果形式  ["word","1ord","w1rd","2rd","wo1d","1o1d","w2d","3d","wor1","1or1","w1r1","2r1","wo2","1o2","w3","4"]

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        //we construct following the rules 
        for (int i = 0; i < pow(2, word.size()); ++i) {
            //construct the current result string
            string out = "";
            //record the letter cnt
            int cnt = 0, t = i;
            for (int j = 0; j < word.size(); ++j) {
                if (t & 1 == 1) {
                    ++cnt;
                } else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];
                }
                t >>= 1;
            }
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        }
        return res;
    }
};

// 递归实现 返回结果形式如下

// ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(word, 0, 0, "", res);
        return res;
    }
    void helper(string word, int pos, int cnt, string out, vector<string> &res) {
        if (pos == word.size()) {
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        } else {
            helper(word, pos + 1, cnt + 1, out, res);
            helper(word, pos + 1, 0, out + (cnt > 0 ? to_string(cnt) : "") + word[pos], res);
        }
    }
};
