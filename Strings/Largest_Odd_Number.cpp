class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length()-1;
        while(i>=0){
            int n = num[i]-'0';
            if(n%2!=0) break;
            i--;
        }
        return num.substr(0,i+1);
    }
};