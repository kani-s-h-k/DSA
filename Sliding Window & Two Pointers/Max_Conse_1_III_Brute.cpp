class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0;i<n;i++){
            int count = 0,len=0;
            for(int j =i;j<n;j++){
                if(nums[j]==0){
                    if(count==k) break;
                    count++;
                }
                len = j - i +1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};