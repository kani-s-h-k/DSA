class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> prev(n+1,0);
        for(int i= 0;i<=n;i++) prev[i] = i*price[0];
        for(int i= 1;i<n;i++){
            for(int j = 0;j<=n;j++){
                int notTake = prev[j];
                int take = INT_MIN;
                int rodLength = i+1;
                if(j>=rodLength) take = price[i] + prev[j-rodLength];
                prev[j] = max(take,notTake);
            }
        }
        return prev[n];
    }
};