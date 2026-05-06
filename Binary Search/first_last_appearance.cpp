class Solution {
    int firstBS(vector<int> &nums,int target){
        int low = 0, high = nums.size()-1,first = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid]<target) low = mid + 1;
            else high = mid - 1;
        }
        return first;
    }

    int lastBS(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1,last = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                last = mid;
                low= mid+1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid - 1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = firstBS(nums,target);
        if(lb==-1) return {-1,-1};
        int ub = lastBS(nums,target);
        return {lb,ub};
    }
};