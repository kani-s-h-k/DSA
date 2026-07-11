class Solution {
private:
    int func(int n, int m, vector<vector<int>>&grid){
        if(n==0 && m==0)return grid[0][0];
        if(n<0 || m<0) return INT_MAX;
        int up = func(n-1,m,grid);
        int left = func(n,m-1,grid);
        int ans = min(up,left);
        if(ans==INT_MAX) return ans;
        return grid[n][m] + ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        return func(n-1,m-1,grid);
    }
};