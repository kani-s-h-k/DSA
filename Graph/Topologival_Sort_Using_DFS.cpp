#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[],vector<int> &vis, stack<int> &st){
	vis[node]=1;
	for(auto &e: adj[node]){
		if(!vis[e]) dfs(e,adj,vis,st);
	}
	st.push(node);
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    vector<int> vis(n,0);
    stack<int> st;
    for(int i = 0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	adj[u].emplace_back(v);
    }
    for(int i = 0;i<n;i++){
    	if(!vis[i]) dfs(i,adj,vis,st); 
    }

    vector<int> ans;
    while(!st.empty()){
    	ans.emplace_back(st.top());
    	st.pop();
    }
    for(auto it: ans){
    	cout<<it<<" ";
    }
    return 0;
}