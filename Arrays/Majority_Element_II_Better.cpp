class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        int min = (n/3)+1;
        for(int i =0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==min){
                ans.emplace_back(nums[i]);
            }
            if(ans.size()==2) break;
        }
        return ans;
    }
};