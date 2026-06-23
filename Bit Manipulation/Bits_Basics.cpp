#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string convert2binary(int n){
	if(n==0) return "0";
	string res = "";
	while(n!=0){
		if(n%2==1) res+='1';
		else res+='0';
		n=n/2;
	}
	reverse(res.begin(),res.end());
	return res;
}

int convert2decimal(string s){
	int ans = 0, pow = 1;
	int n = s.size();
	for(int i = n-1;i>=0;i--){
		if(s[i]=='1') ans+=pow;
		pow*=2;
	}
	return ans;
}

int convert2decimalBetter(string s){
	int ans = 0;
	for(char c: s){
		ans = ans* 2 + (c-'0');
	}
	return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<"Decimal -> Binary: "<<convert2binary(n)<<endl;
	// cout<<"Binary -> Decimal: "<<convert2decimal(s)<<endl;
	cout<<"Binary -> Decimal: "<<convert2decimalBetter(s)<<endl;
	return 0;
}