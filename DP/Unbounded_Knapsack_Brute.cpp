class Solution
{
private:
    int func(int ind, int W, vector<int> &wt, vector<int> &val){
        if(ind==0){
            if(W>=wt[ind]) return (W/wt[ind]) * val[ind];
            return 0;
        }
        int notTake = func(ind-1,W,wt,val);
        int take = INT_MIN;
        if(W>=wt[ind]) take = val[ind] + func(ind,W-wt[ind],wt,val);
        return max(take,notTake);
    }

public:
   int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        return func(n-1,W,wt,val);
    }
};
