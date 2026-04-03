class Solution {
public:
    bool isHeap(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n/2;i++){
            int li = 2*i+1;
            int ri = 2*i+2;
            if(li<n && nums[li]<nums[i]) return false;
            if(ri<n && nums[ri]<nums[i]) return false;
        }
        return true;
    }
};