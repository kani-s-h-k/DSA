class Solution {
private:
    int func(int i, int prev, vector<int> &nums){
        if(i<0) return 0;
        int take = INT_MIN;
        if(prev == -1 || nums[i]<nums[prev]) take = 1 + func(i-1,i,nums);
        int notTake = func(i-1,prev,nums);
        return max(take,notTake);
    }
public:
    int LIS(vector<int>& nums) {    
        int n = nums.size();
        return func(n-1,-1,nums);
    }    
};