class Solution {
private:
    int func(int n, vector<int> &heights){
        if(n==0) return 0;
        int left = func(n-1,heights) + abs(heights[n]-heights[n-1]);
        int right = 0;
        if(n>1) right = func(n-2,heights) + abs(heights[n]-heights[n-2]);
        return min(left,right);
    }
public:
    int frogJump(vector<int>& heights) {
        return func(heights.size()-1,heights);
    }
};