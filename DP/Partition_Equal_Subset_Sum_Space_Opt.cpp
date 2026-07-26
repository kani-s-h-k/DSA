class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0);
        if(target%2==1) return false;
        target /=2;
        vector<bool> prev(target+1,false),curr(target+1,false);
        prev[0]=curr[0]=true;
        if(target>=nums[0]) prev[nums[0]] = true;
        for(int i = 1;i<n;i++){
            for(int j =1;j<=target;j++){
                bool notTake = prev[j];
                bool take = false;
                if(j>=nums[i]) take = prev[j-nums[i]];
                curr[j] = notTake || take;
            }
            prev = curr;
        }
        return prev[target];
    }
};