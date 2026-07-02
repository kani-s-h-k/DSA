class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0, l =0, r =0, count=0;
        while(r<n){
            if(nums[r]==0) count++;
            if(count>k){
                if(nums[l]==0) count--;
                l++;
            }
            if(count<=k){
                int len = r- l +1;
                maxLen = max(len, maxLen);
            }
            r++;
        }
        return maxLen;
    }
};