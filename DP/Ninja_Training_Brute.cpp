class Solution {
    int func(int n, int last,vector<vector<int>>& matrix){
        if(n==0){
            int maxi = INT_MIN;
            for(int i= 0;i<=2;i++){
                if(i!=last) maxi = max(maxi,matrix[0][i]);
            }
            return maxi;
        }
        int maxi = INT_MIN,points = 0;
        for(int i= 0;i<=2;i++){
            if(i!=last) points = matrix[n][i] + func(n-1,i,matrix);
            maxi = max(maxi,points);
        }
        return maxi;
    }
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return func(n-1, 3, matrix);
    }
};