class Solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int num = 0;num<=(1<<n)-1;num++){
            vector<int> substr;
            for(int i = 0;i<n;i++){
                if((num & (1<<i))!=0) substr.emplace_back(nums[i]);
            }
            res.emplace_back(substr);
        }
        return res;
    }
};