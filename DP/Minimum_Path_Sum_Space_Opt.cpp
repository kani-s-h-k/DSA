class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m,0);
        for(int i = 0;i<n;i++){
            vector<int> temp(m,0);
            for(int j = 0;j<m;j++){
                if(i==0 && j==0){
                    temp[i] = grid[0][0];
                    continue;
                };
                int up = INT_MAX,left= INT_MAX;
                if(i>0) up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j] = grid[i][j] + min(up,left);
            }
            prev = temp;
        }
        return prev[m-1];
    }
};