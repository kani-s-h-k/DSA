class Solution {
  private:
    int func(int ind1, int ind2,string str1, string str2){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(str1[ind1]==str2[ind2]) return 1 + func(ind1-1,ind2-1,str1,str2);
        return max(func(ind1-1,ind2,str1,str2) , func(ind1,ind2-1,str1,str2));
    }
  public:
    int lcs(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        return func(n-1,m-1,str1,str2);
    }
};
