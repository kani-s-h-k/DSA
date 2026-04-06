#include <bits/stdc++.h>
using namespace std;

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
	queue<int> q;
	vector<int> visited(V+1,0);
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int node = q.front();
		cout<<node<<" ";
		q.pop();
		for(auto &e: adj[node]){
			if(!visited[e]){
				visited[e]=1;
				q.push(e);
			}
		}
	}

return 0;
}