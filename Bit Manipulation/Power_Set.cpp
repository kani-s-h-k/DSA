class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for(int num = 0;num<=(1<<n)-1;num++){
            vector<int> comb;
            for(int i = 0;i<n;i++){
                if((num & (1<<i))!=0) comb.emplace_back(nums[i]);
            }
            ans.emplace_back(comb);
        }
        return ans;
    }
};