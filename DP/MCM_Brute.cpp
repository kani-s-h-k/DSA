class Solution{
    private:
        int mcm(int i, int j,vector<int> &nums){
            if(i==j) return 0;
            int mini = 1e9;
            for(int k= i;k<=j-1;k++){
                int operations = (nums[i-1] * nums[k] * nums[j]) + mcm(i,k,nums) + mcm(k+1,j,nums);
                mini = min(mini,operations);
            }
            return mini;
        }
	public:
		int matrixMultiplication(vector<int>& nums){
            int n = nums.size();
            if(n==1) return 0;
            return mcm(1,n-1,nums);
    	}
};