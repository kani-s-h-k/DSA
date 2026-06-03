class Solution {
    void generateSums(int ind, int sum, vector<int> &nums, vector<int> &ans){
        if(ind ==  nums.size()){
            ans.emplace_back(sum);
            return;
        }
        generateSums(ind+1, sum+ nums[ind], nums, ans);
        generateSums(ind+1, sum, nums, ans);
    }
  public:
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        generateSums(0, sum, nums, ans);
        return ans;
    }
};