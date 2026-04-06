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
    vector<int> adj[n];
    for(int i = 0;i<m;i++){
    	int u,v;
    	cin>>u>>v;
    	adj[u].emplace_back(v);
    }
    vector<int> indeg(n,0);
    for(int i =0;i<n;i++){
        for(auto &it: adj[i]){
            indeg[it]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.emplace_back(node);
        for(auto &it: adj[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}