#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
    int n,m;
    cin>>n>>m;
    								// Adjacency List
	// vector<int> adj[n+1];
	// for(int i = 0;i<m;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	adj[u].emplace_back(v);
	// 	adj[v].emplace_back(u);
	// }

									// Adjacency Matrix    
    // int arr[n+1][n+1];
    // for(int i = 0;i<m;i++){
    // 	int u,v;
    // 	cin>>u>>v;
    // 	adj[u][v]=1;
    // 	adj[v][u]=1;
    // }

    // Note: For directed graph dont do anyhing for adj[v][u] for both the approaches

    								// Weighted Graph Using Adj Matrix
    // int arr[n+1][n+1];
    // for(int i = 0;i<m;i++){
    // 	int u,v,w;
    // 	cin>>u>>v>>w;
    // 	adj[u][v]=w;
    // 	adj[v][u]=w;

    // }

    								// Weighted Graph Using Adj List
    vector<pair<int,int>> adj[n+1];
    for(int i = 0;i<m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].emplace_back(v,w);
    	adj[v].emplace_back(u,w);
    }

    return 0;
}