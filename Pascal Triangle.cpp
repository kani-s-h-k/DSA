class Solution {
public:
    vector<int> generateRow(int row){
        int ans =1;
        vector<int> ansRow;
        ansRow.emplace_back(1);
        for(int col =1;col<row;col++){
            ans=ans*(row-col);
            ans = ans/col;
            ansRow.emplace_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for(int i =1;i<=numRows;i++){
            pascal.emplace_back(generateRow(i));
        }
        return pascal;
    }
};