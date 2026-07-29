class Solution {
  private:
  public:
    int knapsack(int weight, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(weight+1,0), curr(weight+1,0);
        for(int i = wt[0];i<=weight;i++) prev[i] = val[0];
        for(int ind = 1;ind<n;ind++){
            for(int W = 0;W<=weight;W++){
                int notTake = prev[W];
                int take= INT_MIN;
                if(wt[ind]<=W) take = val[ind] + prev[W-wt[ind]];
                curr[W] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[weight];
    }
};