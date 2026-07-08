class Solution {
private:
    int func(int n, vector<int> &heights, int k){
        if(n==0) return 0;
        int minSteps = INT_MAX;
        for(int i = 1;i<=k;i++){
            if(n-i>=0){
                int jump = func(n-i,heights,k) + abs(heights[n] - heights[n-i]);
                minSteps = min(minSteps, jump);
            }
        }
        return minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return func(n-1,heights,k);
    }
};
