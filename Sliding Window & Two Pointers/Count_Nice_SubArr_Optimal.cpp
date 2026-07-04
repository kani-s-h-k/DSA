class Solution {
private:
    int func(vector<int> &nums, int k){
        int odd =0 , count=0,l=0,r=0;
        int n = nums.size();
        while(r<n){
            if(nums[r]%2==1) odd++;
            while(odd>k){
                if(nums[l]%2==1) odd--;
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k) - func(nums,k-1);
    }
};