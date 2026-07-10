class Solution {
private:
    int func(int m, int n){
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        return func(m-1,n) + func(m,n-1);
    }
public:
    int uniquePaths(int m, int n) {
        return func(m-1,n-1);
    }
};