#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int node,vector<int> adj[],vector<int> &dfs, vector<int> &visited){
	visited[node] = 1;
	dfs.emplace_back(node);
	for(auto &e:adj[node]){
		if(!visited[e]){
			dfsTraversal(e,adj,dfs,visited);
		}
	}
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
	int V,E,s;
	cin>>V>>E; 
	vector<int> adj[V+1];
	for(int i = 0;i<E;i++){
		int u,v;
		cin>>u>>v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}  
	cin>>s;
	vector<int> dfs;
	vector<int> visited(V+1,0);
	dfsTraversal(s,adj,dfs,visited);
	for(auto it: dfs){
		cout<<it<<" ";
	}

return 0;
}