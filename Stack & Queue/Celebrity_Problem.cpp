class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int top = 0, down =n-1;
        while(top<down){
            if(M[top][down]==1) top++;
            else down--;
        }
        for(int i =0;i<n;i++){
            if(i!=top && (M[top][i]==1 || M[i][top]==0)) return -1;
        }
        return top;
    }
};
