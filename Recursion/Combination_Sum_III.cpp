class Solution {
    void generateCombinations(int ind,vector<int>&nums, int sum, int n, int k, vector<int> &comb, vector<vector<int>> &res){
        if(comb.size()==k){
            if(sum == n) res.emplace_back(comb);
            return;
        }
        if(ind == nums.size()) return;
        comb.emplace_back(nums[ind]);
        generateCombinations(ind+1,nums,sum+nums[ind],n,k,comb,res);
        comb.pop_back();
        generateCombinations(ind+1, nums, sum, n, k, comb, res); 
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        generateCombinations(0,nums,0,n,k, comb, res);
        return res;
    }
};