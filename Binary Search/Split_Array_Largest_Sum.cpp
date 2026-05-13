class Solution {
    bool possible(vector<int> &nums, int barrier, int k){
        int splits = 1, sum = 0;
        for(auto it: nums){
            if(sum+it>barrier){
                splits++;
                sum = it;
            }
            else sum+=it;
        } 
        if(splits>k) return false;
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end()), high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(nums,mid,k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};