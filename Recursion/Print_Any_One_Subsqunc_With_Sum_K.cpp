class Solution{
    bool counter(int ind, int s, int sum, int n, vector<int> &nums, vector<int> &ans){
        if(ind == n){
            if(s==sum){
                for(auto it: ans){
                    cout<<it<<" ";
                }
                cout<<endl;
                return true;
            }
            return false;
        }
        s+=nums[ind];
        ans.emplace_back(nums[ind]);
        if(counter(ind+1,s,sum,n,nums,ans)) return true;
        s-=nums[ind];
        ans.pop_back();
        if(counter(ind+1,s,sum,n,nums,ans)) return true;
        return false;
    }
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int n = nums.size();
        vector<int> ans;
        counter(0,0,k,n,nums,ans);
        return 0;
    }
};