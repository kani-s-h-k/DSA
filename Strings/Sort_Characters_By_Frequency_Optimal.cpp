class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        vector<string> bucket(n+1);
        for(char c: s){
            mpp[c]++;
        }
        for(auto &it: mpp){
            bucket[it.second].append(it.second,it.first);
        }
        string res = "";
        for(int i = n;i>=1;i--){
            res+=bucket[i];
        }
        return res;
    }
};