class Solution {
    bool BS(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid]>target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                return BS(matrix[i], target);
            }
        }
        return false;
    }
};