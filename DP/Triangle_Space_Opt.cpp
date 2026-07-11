class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);
        for(int i = 0;i<triangle[n-1].size();i++) prev[i] = triangle[n-1][i];
        for(int i = n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=0;j<triangle[i].size();j++){
                int down = prev[j];
                int diag = prev[j+1];
                temp[j] = triangle[i][j] + min(down,diag);
            }
            prev = temp;
        }
        return prev[0];
        
    }
};