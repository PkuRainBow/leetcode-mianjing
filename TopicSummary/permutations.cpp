// Permutations  https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start >= nums.size()) result.push_back(nums);
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};

// 排序问题 2 
//使用set进行去重操作
//swap based solution 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
    
    void dfs(vector<int>& nums, int start, set<vector<int>>& result) {
        if (start >= nums.size()) result.insert(nums);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[start]) continue;
            swap(nums[start], nums[i]);
            dfs(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};

//construction based solution 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> path;
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        helper(0, nums, used, path, result);
        return result;
    }
    
    void helper(int index, vector<int>&nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        if (index == nums.size()) {
            //vector<int> v = path;
            result.push_back(path);
        } else {
            for (int i = 0; i < nums.size(); i ++) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                helper(index+1,nums,used,path,result);
                path.pop_back();
                used[i] = false;
                while (i + 1 < nums.size() && nums[i+1] == nums[i]) i ++;
            }
        }
    }
};

//子集合问题 2
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();) {
            //count the number of repeated elements
            int count = 0;
            while (count + i < nums.size() && nums[count + i] == nums[i]) count++;
            //record the previous count of existing set
            int prevCnt = result.size();
            for (int k = 0; k < prevCnt; k++) {
                vector<int> instance = result[k];
                //add the repeat element for [1-k] times 
                for (int j = 0; j < count; j++) {
                    instance.push_back(nums[i]);
                    result.push_back(instance);
                }
            }
            i += count;
        }
        return result;
    }
};

/**
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
**/
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string num = "123456789";
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)  dp[i] = dp[i - 1] * i;
        k--;
        for (int i = n; i >= 1; i--) {
            int j = k / dp[i - 1];
            k %= dp[i - 1];
            result.push_back(num[j]);
            num.erase(j, 1);
        }
        return result;
    }
};

/** lintcode permutation index 1 :　http://www.lintcode.com/en/problem/permutation-index/ **/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     * 
     * a_N * n! + ...  a_3 * 3！ + a_2 * 2！ + 1
     * 
     * 其中 a_i record the smaller number count in the right of the position i
     */
    long long permutationIndex (vector<int> &A) {
    	long long index = 1;
    	int position = 2;
    	long long factor = 1;
    	for (int i = A.size（) - 2； i >= 0; i--) {
			int successors = 0;
			for (int j = i + 1; j < A.size(); j++) {
				if (A[i] > A[j]) {
					successors++;
				}
			}
			index += successors * factor;
			factor *= position;
			position++;
		}
		return index;
    }
};

/** lintcode permutation index 2 :　http://www.lintcode.com/en/problem/permutation-index/ **/
/**
Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers,
 which are ordered in lexicographical order. The index begins at 1.
**/
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        // Position 1 is paired with factor 0 and so is skipped.
        int position = 2;
        long long factor = 1;
        unordered_map<int, int> number_to_count;
        ++number_to_count[A.back()];
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            unordered_map<int, int> successor_to_count;
            ++number_to_count[A[i]];
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successor_to_count[A[j]];
                }
            }
            for (const auto& kvp : successor_to_count) {
                index += factor * kvp.second / number_to_count[A[i]];
            }
            factor = factor * position / number_to_count[A[i]];
            ++position;
        }
        return index;
    }
};

// previous permutations 

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int k = -1, l = 0;

        // Find the last index k before the increasing sequence.
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                k = i;
            }
        }

        if (k >= 0) {
            // Find the largest number which is smaller than the value of the index k,
            // and swap the values.
            for (int i = k + 1; i < nums.size(); ++i) {
                if (nums[i] < nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }

        // Reverse the sequence after the index k.
        reverse(nums.begin() + k + 1, nums.end());

        return nums;
    }
};