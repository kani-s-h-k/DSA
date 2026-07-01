class Solution
{
    private:
    vector<int> previousGreaterElement(vector<int> nums,int n){
        vector<int> pge(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top();
            st.push(i);
        }
        return pge;
    }
    public:
    vector <int> stockSpan(vector<int> arr, int n) {
        vector<int> pge = previousGreaterElement(arr,n);
        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.emplace_back(i-pge[i]);
        }
        return ans;
    }
};
