class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    vector<string> find(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> t = find(m - 2, n);
        vector<string> res;
        for (auto a : t) {
            if (m != n) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};


class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int count = 0;
        for(int len = low.length(); len <= high.length(); len++) {
            string temp(len, '0');
            dfs(low, high, temp, 0, len - 1, count, mp);
        }
        return count;
    }
    void dfs(string low, string high, string str, int left, int right, int &count, map<char, char> &mp) {
        if(left > right) {
            /** filter all the numbers that are not in the [low, upper] **/
            if((str.length() == low.length() && str.compare(low) < 0) ||
               (str.length() == high.length() && str.compare(high) > 0)) return;
            count++;
            return;
        }
        /** loop for all the possible cases **/
        for(auto p : mp) {
            str[left] = p.first;
            str[right] = p.second;
            /** pass the illegal cases **/
            if(str.size() != 1 && str[0] == '0') continue;
            if(left < right || left == right && p.first == p.second) dfs(low, high, str, left + 1, right - 1, count, mp);
        }
    }
};

/** problem description **/
/**
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
**/



class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        find(low, high, "", res);
        find(low, high, "0", res);
        find(low, high, "1", res);
        find(low, high, "8", res);
        return res;
    }
    void find(string low, string high, string w, int &res) {
    	//length should be checked first 
        if (w.size() >= low.size() && w.size() <= high.size()) {
            if ((w.size() == low.size() && w.compare(low) < 0) || (w.size() == high.size() && w.compare(high) > 0)) {
                return;
            }
            if (w.size() > 1 && w[0] == '0') return;
            ++res;
        }
        //small cut edges strategy 
        if (w.size() + 2 > high.size()) return;
        find(low, high, "0" + w + "0", res);
        find(low, high, "1" + w + "1", res);
        find(low, high, "6" + w + "9", res);
        find(low, high, "8" + w + "8", res);
        find(low, high, "9" + w + "6", res);
    }
};
