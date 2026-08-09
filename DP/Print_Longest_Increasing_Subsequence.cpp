class Solution {
  public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        int n = arr.size(),maxi=1,lastIndex = 0;
        vector<int> dp(n,1),hash(n,0);
        for(int i = 0;i<n;i++){
            hash[i]=i;
            for(int j =0;j<=i-1;j++){
                if(arr[i]>arr[j] && 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.emplace_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            temp.emplace_back(arr[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};