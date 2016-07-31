//Manacher Algorithm Implementation 
string Manacher(string s) {
    //start use $ char
    string t = "$#";
    for (int i = 0; i < s.size(); i++) {
        t += s[i];
        t += "#";
    }
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); i++) {
        p[i] = mx > i ? min(p[2*id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i-p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

//# 1  https://leetcode.com/problems/palindrome-number/ 
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};


//# 2
//https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        if(len<=1)  return true;
        int left=0, right=len-1;
        while(left<right){
            while(left<right && !check(s[left])) left++;
            while(right>left && !check(s[right])) right--;
           // if(left==len || right==-1)  return true;
            if(toupper(s[left])!=toupper(s[right]))  return false;
            left++;
            right--;
        }
        return true;
    }
    
    bool check(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9');
    }
};

//# 3
//https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curPath;
        dfs(s,curPath,result);
        return result;
    }

    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start  < end) {
            if (s[start] == s[end]) {
                start ++;
                end --;
            } else {
                return false;
            }
        }
        return true;
    }

    void dfs(string s, vector<string>& curPath, vector<vector<string>>& result) {
        if (s.size() == 0) {
            result.push_back(curPath);
            return;
        } else {
            for (int i = 1; i <= s.size(); i ++) {
                string curWord = s.substr(0,i);
                string nextWord = s.substr(i);
                if (isPalindrome(curWord)) {
                    curPath.push_back(curWord);
                    dfs(nextWord, curPath, result);
                    curPath.pop_back();
                }
            }
        }
    }
};

//# 3
// https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, n);
        for(int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                    //case : j == 0
                    if (isPalindrome[0][i]) dp[i] = 0;
                    else {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};


//# 4 
// shortest palindrome string 
// https://leetcode.com/problems/shortest-palindrome/
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        int n = s.size(), len;
        //find the longest palindrome pre-string
        for (len = n; len >= 0; len--) {
            if (s.substr(0, len) == rev_s.substr(n - len))
                break;
        }
        return rev_s.substr(0, n - len) + s;
    }
};

//# 5 
// reverse palindrome linked list 
// https://leetcode.com/problems/palindrome-linked-list/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        reverse(slow);
        ListNode* s_head = head, *t_head = slow->next;
        while (s_head && t_head) {
            if(s_head->val == t_head->val) { s_head = s_head->next; t_head = t_head->next; }
            else return false;
        }
        return true;
    }
    
    void reverse(ListNode* head) {
        ListNode* start = head->next, *cur = start->next;
        while (cur) {
            start->next = cur->next;
            cur->next = head->next;
            head->next = cur;
            cur = start->next;
        }
        return;
    }
};

//palindrome pairs 
//https://leetcode.com/problems/palindrome-pairs/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j <= words[i].length(); j++) {
                //suffix string is palindrome, so we can add at the end of the string
                if (is_palindrome(words[i], j, words[i].size() - 1)) {
                    string suffix = words[i].substr(0, j);
                    reverse(suffix.begin(), suffix.end());
                    if (dict.find(suffix) != dict.end() && i != dict[suffix]) {
                        result.push_back({i, dict[suffix]});
                    }
                }
                if(j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string prefix = words[i].substr(j);
                    reverse(prefix.begin(), prefix.end());
                    if (dict.find(prefix) != dict.end() && dict[prefix] != i) {
                        result.push_back({dict[prefix], i});
                    }
                }
            }
        }
        return result;
    }
    
    bool is_palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

//palindrome permutation 
class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> t;
        for (auto a : s) {
            if (t.find(a) == t.end()) t.insert(a);
            else t.erase(a);
        }
        return t.empty() || t.size() == 1;
    }
};

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (auto a : s) {
            b.flip(a);
        }
        return b.count() < 2;
    }
};

//palindrome permutation 2

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        for (auto it : m) {
            if (it.second & 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return res;
    }
    void permute(string &t, int start, string mid, vector<string> &res) {
        if (start >= t.size()) {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        } 
        for (int i = start; i < t.size(); ++i) {
            if (i != start && t[i] == t[start]) continue;
            swap(t[i], t[start]);
            permute(t, start + 1, mid, res);
            swap(t[i], t[start]);
        }
    }
};