class Solution {
public:
    string frequencySort(string s) {
        auto cmp = [](const pair<char,int> &a, const pair<char,int> &b){
            return a.second<b.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> pq(cmp);
        unordered_map<char,int> mpp;
        for(char c: s){
            mpp[c]++;
        }
        for(auto  &it:mpp){
            pq.push({it.first,it.second});
        }
        string res = "";
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            res.append(p.second, p.first);
        }
        return res;
    }
};