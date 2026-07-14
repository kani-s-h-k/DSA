class Solution{
private:
    bool func(int ind, vector<int> &arr, int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return arr[ind] == target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = func(ind-1, arr, target,dp);
        bool take = false;
        if(target>=arr[ind]) take = func(ind-1,arr,target-arr[ind],dp);
        return dp[ind][target] = take || notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        if(target==0) return true;
        vector<vector<int>> dp(101,vector<int>(5e3+1,-1));
        int n = arr.size();
        return func(n-1,arr,target,dp);
    }
};