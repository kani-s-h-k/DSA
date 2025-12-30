#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i =0;i<n;i++){
	    cin>>nums[i];
	}
	int maxLen = 0;
    for(int i =0;i<n;i++){
        int sum = 0;
        for(int j =i;j<n;j++){
            sum+=nums[j];
            if(sum == 0){
                int len = j-i+1;
                maxLen = max(maxLen,len);
            }
        }
    }
    cout<<maxLen<<endl;
    return 0;
}
