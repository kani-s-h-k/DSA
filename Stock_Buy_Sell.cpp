#include <bits/stdc++.h>
using namespace std;

int main() {
    int start;
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
    int maxProfit = 0, mini = arr[0];
    for(int i =1;i<n;i++){
        int profit = arr[i] - mini;
        maxProfit = max(maxProfit,profit);
        mini = min(arr[i],mini);
    }
    cout<<maxProfit<<endl;
    return 0;
}
