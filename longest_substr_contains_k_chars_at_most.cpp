

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
