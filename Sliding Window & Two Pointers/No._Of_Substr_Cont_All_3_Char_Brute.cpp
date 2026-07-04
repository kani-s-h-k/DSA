class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(),count=0;
        for(int i= 0;i<n;i++){
            int hash[3]={0};
            for(int j= i;j<n;j++){
                hash[s[j]-'a']=1;
                if(hash[0]+hash[1]+hash[2]==3){
                    count += n- j;
                    break;
                }
            }
        }
        return count;
    }
};