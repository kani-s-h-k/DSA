class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size(),maxi=1;
        vector<int> dp(n,1),count(n,1);
        for(int i= 0;i<n;i++){
            for(int j= 0;j<=i-1;j++){
                if(arr[i]>arr[j]){
                    if(1+dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }
                    else if(1 + dp[j] == dp[i]) count[i]+=count[j];
                }
            }
            maxi=max(maxi,dp[i]);

        }
        int cnt =0;
        for(int i =0;i<n;i++){
            if(dp[i]==maxi) cnt += count[i];
        }
        return cnt;
    }
};