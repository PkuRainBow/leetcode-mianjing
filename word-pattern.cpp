//use ont map
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0;
        for (string word; in >> word; ++i) {
            //pattern exist
            if (m.find(pattern[i]) != m.end()) {
                if (m[pattern[i]] != word) return false;
            } 
            //
            else {
                for (unordered_map<char, string>::iterator it = m.begin(); it != m.end(); ++it) {
                    if (it->second == word) return false;
                }
                m[pattern[i]] = word;
            }
        }
        return i == pattern.size();
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0;
        for (string word; in >> word; i++) {
            if (m1.find(pattern[i]) != m1.end() || m2.find(word) != m2.end()) {
                if (m1[pattern[i]] != m2[word]) return false;
            }
            else {
                m1[pattern[i]] = m2[word] = i + 1;
            }
        }
        return i == pattern.size();
    }
};


/**
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:

pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
 

Notes:
You may assume both pattern and str contains only lowercase letters.
**/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        return helper(pattern, 0, str, 0, m);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i = r; i < str.size(); ++i) {
            string t = str.substr(r, i - r + 1);
            //exist matching pair
            if (m.count(c) && m[c] == t) {
                if (helper(pattern, p + 1, str, i + 1, m)) return true;
            } 
            //字符没有出现过
            else if (!m.count(c)) {
                bool b = false;
                //check whether the word exist before 
                for (auto it : m) {
                    if(it.second == t) b = true;
                }
                if(!b) {
                    m[c] = t;
                    if (helper(pattern, p + 1, str, i + 1, m)) return true;
                    m.erase(c);
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<string, char> s_to_p;
        unordered_map<char, string> p_to_s;
        return helper(pattern, str, s_to_p, p_to_s);
    }
    
    bool helper(string pattern, string str, unordered_map<string, char>& s_to_p, unordered_map<char, string>& p_to_s) {
        if (pattern.empty()) return str.empty();
        if (p_to_s.find(pattern[0]) != p_to_s.end()) {
            string tmp = p_to_s[pattern[0]];
            if (str.substr(0, tmp.size()) == tmp) {
                return helper(pattern.substr(1), str.substr(tmp.size()), s_to_p, p_to_s);
            } else {
                return false;
            }
        } else {
            for (int i = 1; i <= str.size(); i ++) {
                string cur = str.substr(0, i);
                if (s_to_p.find(cur) != s_to_p.end()) continue;
                s_to_p[cur] = pattern[0];
                p_to_s[pattern[0]] = cur;
                if (helper(pattern.substr(1), str.substr(i), s_to_p, p_to_s)) {
                    return true;
                }
                s_to_p.erase(cur);
                p_to_s.erase(pattern[0]);
            }
            return false;
        }
    }
};
