class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); i++) {
        	if ((i&1 && nums[i] < nums[i-1]) || (!(i&1) && nums[i] > nums[i-1]) {
        		swap(nums[i], nums[i - 1]);
        	}
        }
    }
};