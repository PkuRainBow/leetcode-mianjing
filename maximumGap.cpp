class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        int minN = nums[0];
        int maxN = nums[0];
        for (int i = 1; i < n; ++i) {
            maxN = max(nums[i], maxN);
            minN = min(nums[i], minN);
        }
        //average bucket size
        int len = (maxN - minN) / n + 1;
        //bucket number 
        int bucketNum = (maxN - minN) / len + 1;
        vector<int> bucketMin(bucketNum, INT_MAX);
        vector<int> bucketMax(bucketNum, INT_MIN);
        for (int i = 0; i < n; i++) {
            int index = (nums[i] - minN) / len;
            bucketMin[index] = min(bucketMin[index], nums[i]);
            bucketMax[index] = max(bucketMax[index], nums[i]);
        }
        int result = 0, pre = 0;
        for (int i = 1; i < bucketNum; i++) {
            if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN) continue;
            result = max(result, bucketMin[i] - bucketMax[pre]);
            pre = i;
        }
        return result;
    }
};