class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int maxLen = 0;
        for(int i= 0;i<n;i++){
            set<int> st;
            for(int j = i; j<n;j++){
                st.insert(fruits[j]);
                if(st.size()>2) break;
                maxLen = max(maxLen, j- i + 1);
            }
        }
        return maxLen;
    }
};