#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int> &arr, vector<int> &indices){
        vector<int> ans;
        for(int it: indices){
            bool found=false;
            int count =0;
            for(int i = it+1;i<arr.size();i++){
                if(arr[i]>arr[it]){
                    found=true;
                    count++;
                } 
            }
            if(!found) ans.emplace_back(0);
            else ans.emplace_back(count);
        }
        return ans;
}
int main() {
	int n1,n2;
	cin>>n1;
	vector<int> arr(n1);
	for(int i =0;i<n1;i++){
	    cin>>arr[i];
	}
	cin>>n2;
	vector<int> indices(n2);
	for(int i =0;i<n2;i++){
	    cin>>indices[i];  
	}
	vector<int> res = nge(arr,indices);
	for(auto it: res){
	    cout<<it<<" ";
	}
	
	return 0;
	

}
