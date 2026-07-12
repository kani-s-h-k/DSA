class Solution {
private:
    int func(int i, int j1, int j2,int n, int m,vector<vector<int>> &grid){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        int maxi = -1e8;
        for(int k= -1;k<=1;k++){
            for(int l = -1;l<=1;l++){
                if(j1==j2) maxi = max(maxi,grid[i][j1] + func(i+1,j1+k,j2+l,n,m,grid));
                else maxi = max(maxi,grid[i][j1] + grid[i][j2] + func(i+1,j1+k,j2+l,n,m,grid));
            }
        }
        return maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n =  grid.size(), m = grid[0].size();
        return func(0,0,m-1,n,m,grid);
    }
};