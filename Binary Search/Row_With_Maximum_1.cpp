#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
		int n;
        cin>>n;
        vector<vector<int>> nums(n,vector<int>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>nums[i][j];
            }
        }
        int count_max = 0;
        int index = -1;
        for(int i = 0;i<n;i++){
            auto lb = lower_bound(nums[i].begin(),nums[i].end(),1);
            int countOnes = lb == nums[i].end() ? 0 : nums[i].end() - lb;
            if(countOnes> count_max){
                count_max = countOnes;
                index = i;
            }
        }
        cout<<index<<endl;
    return 0;
}