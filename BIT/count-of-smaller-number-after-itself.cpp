class Solution {
    vector<int> bit;
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        bit.resize(nums.size()+1, 0);
        
        //get the ordered-index-array
        vector<int> sorted_nums(nums);
        vector<int> places(nums.size(), 0);
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            places[i] = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
            //cout<<i<<"th places:"<<places[i]<<endl;
        }
        
        for(int i=places.size()-1; i>=0; i--){
            result[i]=bit_sum(places[i]-1);
            bit_add(places[i], 1);
        }
        
        return result;
    }
    
    int bit_last(int i){
        return i&-i;
    }
    
    void bit_add(int i, int val){
        i++;
        while(i<bit.size()){
            bit[i]+=val;
            i=i+bit_last(i);
        }
    }
    
    int bit_sum(int i){
        i++;
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i=i-bit_last(i);
        }
        return sum;
    }
};

//stl based concise solution 

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> t, res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
            res[i] = d;
            t.insert(t.begin() + d, nums[i]);
        }
        return res;
    }
};