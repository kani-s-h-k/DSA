#include <bits/stdc++.h>
using namespace std;

bool detect(int i , vector<int> adj[], vector<int> &vis){
	queue<pair<int,int>> q;
	q.push({i,-1});
	vis[i]=1;
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto &e:adj[node]){
			if(!vis[e]){
				vis[e]=1;
				q.push({e,node});
			}
			else if(e!=parent){
				return true;
			}
		}
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
		if(detect(i, adj,vis)){
			cout<<"True"<<endl;
			return 0;
		}
	}
}
cout<<"False"<<endl;
return 0;
}