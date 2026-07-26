class Solution {
  public:
    int minDifference(vector<int>& nums) {
        // code here
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        vector<bool> dp(target+1,false),curr(target+1,false);
        dp[0]=curr[0]= true;
        if(target>=nums[0]) dp[nums[0]]= true;
        for(int i =1;i<n;i++){
            for(int j = 1;j<=target;j++){
                bool notTake = dp[j];
                bool take = false;
                if(j>=nums[i]) take = dp[j-nums[i]];
                curr[j] = take || notTake;
            }
            dp = curr;
        }
        int mini = INT_MAX;
        for(int s1=0;s1<=target/2;s1++){
           if(dp[s1]){
                int diff = abs((2*s1 - target));
                mini = min(mini,diff);
            }
        }
        return mini;
    }
};
