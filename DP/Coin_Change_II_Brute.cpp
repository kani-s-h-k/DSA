class Solution {
private:
    int func(int ind, int target, vector<int> &coins){
        if(ind==0){
            if(target%coins[ind]==0) return 1;
            return 0;
        }
        int notTake = func(ind-1,target,coins);
        int take = 0;
        if(target>=coins[ind]) take = func(ind,target-coins[ind],coins);
        return take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        return func(n-1,amount,coins);
    }
};