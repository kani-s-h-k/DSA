class Solution {
    bool possible(vector<int> &nums, int weight, int days){
        int total = 0,cnt = 1;
        for(auto it: nums){
            total+=it;
            if(total>weight){
                cnt++;
                total = it;
            }
        }
        if(cnt<=days) return true;
        return false;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low  = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(weights,mid,days)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};