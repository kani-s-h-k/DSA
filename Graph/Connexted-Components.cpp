#include <bits/stdc++.h>
using namespace std;

int count(int V, vector<vector<int>> &edges){
	vector<vector<int>> adj(V);
	for(auto &e:edges){
		adj[e[0]].emplace_back(e[1]);
		adj[e[1]].emplace_back(e[0]);
	}
	int comps = 0;
	vector<int> visited(V,0);
	for(int i = 0;i<V;i++){
		if(!visited[i]){
			visited[i]=1;
			comps++;
			queue<int> q;
			q.push(i);

			while(!q.empty()){
				int node = q.front();
				q.pop();

				for(auto &e:adj[node]){
					if(!visited[e]){
						visited[e]=1;
						q.push(e);
					}
				}
			}
		}
	}
	return comps;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("E:/sublime/input.txt","r",stdin);
	freopen("E:/sublime/output.txt","w",stdout);
#endif
						//Code Starts Here
    int V = 5;
    vector<vector<int>> edges = {{1,2},{0,1},{3,4}};
    cout<<count(V,edges)<<endl;
    return 0;
}