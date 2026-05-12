class Solution {
    bool canWePlace(vector<int> &nums, int dist, int cows){
        int countCows = 1,last = nums[0];
        for(int i =1;i<=nums.size()-1;i++){
            if(nums[i]-last>=dist){
                last = nums[i];
                countCows++;
            }
            if(countCows>=cows) return true;
        }
        return false;
    }
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxi = nums[n-1],mini=nums[0];
        int low = 1, high = maxi - mini;
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(canWePlace(nums,mid,k)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};