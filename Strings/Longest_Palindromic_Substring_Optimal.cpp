class Solution {
    string helper(string &s, int left, int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right - left - 1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i =0 ;i<n;i++){
            string odd = helper(s,i,i);

            if(odd.size()>ans.size()) ans = odd;

            string even = helper(s,i,i+1);

            if(even.size()>ans.size()) ans = even;
        }
        return ans;
    }
};