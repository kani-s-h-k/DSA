class Solution {
private:
    vector<int> nextGreaterElement(vector<int> &nums){
        int n = nums.size();        
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> previousGreaterElement(vector<int> &nums){
        int n = nums.size();        
        vector<int> pge(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }
        return pge;       
    }
    vector<int> nextSmallerElement(vector<int> &nums){
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[i]<= nums[st.top()]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> previousSmallerElement(vector<int> &nums){
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[i]< nums[st.top()]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge = nextGreaterElement(nums), pge = previousGreaterElement(nums), nse = nextSmallerElement(nums), pse = previousSmallerElement(nums);
        long long minimumSum = 0, maximumSum = 0;
        for(int i = 0;i<n;i++){
            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;
            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;
            minimumSum = minimumSum + 1LL* leftMin * rightMin * nums[i];
            maximumSum = maximumSum + 1LL * leftMax * rightMax * nums[i];
        }
        return maximumSum - minimumSum;
    }
};