class Solution
{
public:
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> prev(W+1,0);
        for(int i = 0;i<=W;i++) if(i>=wt[0]) prev[i] = (i/wt[0]) * val[0];
        for(int i= 1;i<n;i++){
            for(int j = 0;j<=W;j++){
                int notTake = prev[j];
                int take = INT_MIN;
                if(j>=wt[i]) take = val[i] + prev[j-wt[i]];
                prev[j]= max(take,notTake);
            }
        }
        return prev[W];
    }
};
