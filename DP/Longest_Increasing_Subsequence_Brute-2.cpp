class Solution {
public:
    int LIS(vector<int>& arr) {    
        int n = arr.size(),maxi=1;
        vector<int> dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j =0;j<=i-1;j++){
                if(arr[i]>arr[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
                maxi = max(maxi,dp[i]);
            }
        }
        return maxi;
    }    
};