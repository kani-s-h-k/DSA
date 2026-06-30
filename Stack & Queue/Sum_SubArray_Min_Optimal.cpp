class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[i]<= arr[st.top()]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> previousSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[i]< arr[st.top()]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int> &arr) {
        vector<int> nse = nextSmallerElement(arr), pse = previousSmallerElement(arr);
        long long ans = 0, mod = (int)(1e9 + 7);
        for(int i = 0; i<arr.size();i++){
            int leftElements = i - pse[i];
            int rightElements = nse[i] - i;
            ans = (ans + 1LL * leftElements * rightElements * arr[i]) % mod;
        }
        return (int)ans;
    }
};
