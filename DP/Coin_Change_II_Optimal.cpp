class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        vector<unsigned long long> prev(amount+1,0);
        prev[0]=1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=amount;j++){
                unsigned long long notTake = prev[j];
                unsigned long long take = 0;
                if(j>=coins[i]) take = prev[j-coins[i]];
                prev[j] = take + notTake;
            }
        }
        return (int)(prev[amount]);
    }
};