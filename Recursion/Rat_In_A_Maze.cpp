class Solution{
    void generatePath(int r, int c, string s, vector<string> &ans,vector<vector<int>> &grid,vector<vector<int>> &hash){
        if(r<0 || c<0 || r>=grid.size() || c>=grid.size() || hash[r][c]==1 || grid[r][c]==0) return;
        if(r==grid.size()-1 && c == grid.size()-1 ){
            ans.emplace_back(s);
            return;
        }
        hash[r][c]=1;
        generatePath(r+1,c,s+"D",ans,grid,hash);
        generatePath(r-1,c,s+"U",ans,grid,hash);
        generatePath(r,c+1,s+"R",ans,grid,hash);
        generatePath(r,c-1,s+"L",ans,grid,hash);
        hash[r][c]=0;
    }
    public:
    vector<string> findPath(vector<vector<int> > &grid) {
        int n = grid.size();
        if(grid[0][0]==0) return {};
        vector<string> ans;
        vector<vector<int>> hash(n,vector<int>(n,0));
        generatePath(0,0,"",ans,grid,hash);
        return ans;
    }
};