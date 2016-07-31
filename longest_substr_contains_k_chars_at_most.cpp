

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int k = 2;
        int longest = 0, start = 0, distinct_count = 0;
        /** record the frequencies of all the different character **/
        vector<int> visited(256, 0);
        for(int i = 0; i < s.size(); i++) {
            /** occur firstly, update the distinct_count **/
            if(visited[s[i]] == 0) {
                ++distinct_count;
            }
            ++visited[s[i]];
            /** if distinct_count bigger than k , we need to move the start pointer **/
            while(distinct_count > k) {
                --visited[s[start]];
                /** if the condition is satisfied, update distinct_count **/
                if(visited[s[start]] == 0) {
                    --distinct_count;
                }
                ++start;
            }
            /** update the longest value **/
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};

/** follow up question **/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        const int k = 2;
        int longest = 0, start = 0, distinct_count = 0;
        /** record the frequencies of all the different character **/
        vector<int> visited(256, 0);
        for(int i = 0; i < s.size(); i++) {
            /** occur firstly, update the distinct_count **/
            if(visited[s[i]] == 0) {
                ++distinct_count;
            }
            ++visited[s[i]];
            /** if distinct_count bigger than k , we need to move the start pointer **/
            while(distinct_count > k) {
                --visited[s[start]];
                /** if the condition is satisfied, update distinct_count **/
                if(visited[s[start]] == 0) {
                    --distinct_count;
                }
                ++start;
            }
            /** update the longest value **/
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};


/** follow up question **/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (str.empty() || k == 0) {
            return 0;
        }
        //sorted position of the existing char in the array
        map<int, char> last_pos; 
        //sorted letter array  recording the position
        map<char, int> windows;
        int start = 0, longest = 0;
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            //windows contains at most k distinct chars 
            if (windows.size() == k && windows.find(ch) == windows.end()) {
                auto it = last_pos.begin();
                windows.erase(it->second);
                last_pos.erase(it->first);
                start = it->first + 1;
            }
            if (windows.find(ch) != windows.end()) {
                last_pos.remove(windows[ch]);
            }
            windows[ch] = i;
            last_pos[i] = ch;
            longest = max(longest, i - start + 1);
        }
        return longest;
    }
};
