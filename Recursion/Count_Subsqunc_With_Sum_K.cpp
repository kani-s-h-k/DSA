class Solution{
    int counter(int ind, int s, int sum, int n, vector<int> &nums){
       //all elements should be positive for this condition if(s>sum) return 0;
        if(ind == n){
            if(s==sum) return 1;
            return 0;
        }
        s+=nums[ind];
        int left = counter(ind+1,s,sum,n,nums);
        s-=nums[ind];
        int right = counter(ind+1,s,sum,n,nums);
        return left+right;
    }
    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int n = nums.size();
        return counter(0,0,k,n,nums);
    }
};