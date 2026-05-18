class Solution {
    int maxElement(vector<vector<int>> &mat, int row, int col){
        int maxRow=-1,maxi=INT_MIN;
        for(int i = 0;i<row;i++){
            if(mat[i][col]>maxi){
                maxi = mat[i][col];
                maxRow = i;
            }
        }
        return maxRow;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int maxRowIndex = maxElement(mat,n,mid);
            int left = mid-1 >=0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid+1 < m ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid]> right) return {maxRowIndex, mid};
            else if(mat[maxRowIndex][mid] < left) high = mid - 1;
            else low = mid + 1;        
        }
        return {-1,-1};
    }
};