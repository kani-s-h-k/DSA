class Solution {
private:
    int func(int i,int j, vector<vector<int>> &triangle){
        if(i==triangle.size()-1) return triangle[i][j];
        int down = func(i+1,j,triangle);
        int diag = func(i+1,j+1,triangle);
        return triangle[i][j] + min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return func(0,0,triangle);
    }
};