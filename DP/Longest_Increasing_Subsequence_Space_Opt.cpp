class Solution {
public:
    int LIS(vector<int>& nums) {    
        int n = nums.size();
        vector<int> next(n+1,0),curr(n+1,0);
        for(int i= n-1;i>=0;i--){
            for(int j = i-1;j>=-1;j--){
                int notTake = next[j+1];
                int take = INT_MIN;
                if(j==-1 || nums[i]>nums[j]) take = 1 + next[i+1];
                curr[j+1] = max(take,notTake);
            }
            next = curr;
        }
        return next[0];
    }    
};