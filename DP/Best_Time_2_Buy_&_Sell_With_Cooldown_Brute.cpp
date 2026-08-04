class Solution {
private:
    int func(int i, int buy, vector<int> &prices){
        if(i>=prices.size()) return 0;
        if(buy){
            return max(func(i+1,0,prices) - prices[i],func(i+1,1,prices));
        }
        else{
            return max(func(i+2,1,prices) + prices[i],func(i+1,0,prices));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return func(0,1,prices);
    }
};