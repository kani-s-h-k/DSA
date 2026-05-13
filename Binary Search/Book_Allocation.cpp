class Solution {
    bool possible(vector<int> &nums, int barrier, int m){
        int students = 1, pages = 0;
        for(auto it: nums){
            if(it > barrier) return false;
            if(pages + it > barrier){
                students++;
                pages = it;
            }
            else pages+=it;
        }
        if(students>m) return false;
        return true;
    }
public:
    int findPages(vector<int> &nums, int m)  {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(nums,mid,m)){
                ans = mid;            
                high = mid - 1;    
            }
            else low = mid + 1;
        }
        return ans;
    }
};