class Solution {
    void generateCombinations(int ind, int s,int n, int sum,vector<int> &candidates ,vector<vector<int>> &res,vector<int> &comb){
        if(ind==n || s>sum) return;
        if(s==sum){
            res.emplace_back(comb);
            return;
        }
        comb.emplace_back(candidates[ind]);
        generateCombinations(ind,s+candidates[ind],n,sum,candidates,res,comb);
        comb.pop_back();
        generateCombinations(ind+1,s,n,sum,candidates,res,comb);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> comb;
        generateCombinations(0,0,n,target,candidates,res,comb);
        return res;
    }
};