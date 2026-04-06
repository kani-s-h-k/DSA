#include <bits/stdc++.h>
using namespace std;

bool detect(int node, int parent , vector<int> adj[], vector<int> &vis){
	vis[node]=1;
	for(auto &e:adj[node]){
		if(!vis[e]){
			if(detect(e,node,adj,vis)) return true;
		}
		else if(e!=parent) return true;
	}
	return false;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
    
int n,m;
cin>>n>>m;
vector<int> adj[n+1];


for(int i =0;i<m;i++){
	int u,v;
	cin>>u>>v;
	adj[u].emplace_back(v);
	adj[v].emplace_back(u);
}
vector<int> vis(n+1,0);
for(int i = 1;i<=n;i++){
	if(!vis[i]){
		if(detect(i,-1, adj,vis)){
			cout<<"True"<<endl;
			return 0;
		}
	}
}
cout<<"False"<<endl;
return 0;
}