class Solution {
    bool possible(vector<int> &nums, int i, int threshold){
        int sum = 0;
        for(auto it: nums){
            sum += ceil((double)it/i);
        }
        if(sum<=threshold) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(nums,mid,threshold)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return -1;
    }
};