class Solution {
    void generateCombinations(int ind, int target, vector<int> &candidates, vector<int> &comb ,vector<vector<int>> &res){
        if(target == 0){
            res.emplace_back(comb);
            return;
        }
        for(int i = ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            comb.emplace_back(candidates[i]);
            generateCombinations(i+1, target - candidates[i],candidates, comb, res);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        generateCombinations(0, target, candidates, comb, res);
        return res;
    }
};