class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        vector<int> front1(n+1,0),front2(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                if(buy) curr[buy] = max(front1[0]- prices[i],front1[1]);
                else curr[buy] = max(front2[1] + prices[i],front1[0]);
            }
            front2 = front1;
            front1=curr;
        }
        return front1[1];
    }
};