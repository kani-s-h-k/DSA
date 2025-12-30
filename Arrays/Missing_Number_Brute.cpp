#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++){
	    cin>>arr[i];
	}
    for(int i =0;i<n;i++){
        bool found = false;
        for(int j =0;j<n;j++){
            if(i==arr[j]){
                found = true;
                break;
            }
        }
        if(!found){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}
