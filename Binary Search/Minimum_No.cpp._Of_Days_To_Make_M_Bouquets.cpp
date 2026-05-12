class Solution {
    bool possible(vector<int> &nums, int day, int m, int k){
        int count = 0,ans=0;
        for(auto it: nums){
            if(it<=day) count++;
            else{
                ans += count/k;
                count = 0;
            }
        }
        ans += count/k;
        if(ans>=m) return true;
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<(long long)m*k) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1; 
        }
        return ans;
    }
};