class Solution {
public:
    int largestRect(vector<int> &nums){
        int nse, pse,element;
        int n = nums.size();
        int maxArea = INT_MIN;
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea=max(maxArea, (nse-pse-1)*nums[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            element = st.top();
            st.pop();
            nse = n;
            pse = st.empty()?-1:st.top();
            maxArea=max(maxArea, (nse-pse-1)*nums[element]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> p(n,vector<int>(m));
        int maxArea = 0;
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i =0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                p[i][j]=sum;
            }
        }
        for(int i =0;i<n;i++){
            maxArea = max(maxArea, largestRect(p[i]));
        }
        return maxArea;
    }
};