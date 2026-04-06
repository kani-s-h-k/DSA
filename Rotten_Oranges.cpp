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
    vector<vector<int>> grid(n,vector<int>(m));
    queue<pair<pair<int,int>,int>> q;
    int vis[n][m];
    int cntfresh=0;
    for(int i = 0;i<n;i++){
    	for(int j = 0;j<m;j++){
    			int x;
    			cin>>x;
    			grid[i][j]=x;
    			if(x==2) {
    				q.push({{i,j},0});
    				vis[i][j]=2;
    			}
    			else vis[i][j]=0;
    			if(grid[i][j]==1) cntfresh++;
    	}
    }
    int tm =0;
    int drow[]={-1,0,+1,0};
    int dcol[]={0,+1,0,-1};
    int cnt =0;
    while(!q.empty()){
    	int r = q.front().first.first;
    	int c = q.front().first.second;
    	int t = q.front().second;
    	tm = max(tm,t);
    	q.pop();
    	for(int i = 0;i<4;i++){
    		int nrow = r+drow[i];
    		int ncol = c+dcol[i];
    		if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
    			q.push({{nrow,ncol},t+1});
    			vis[nrow][ncol]=2;
    			cnt++;
    		}
    	}
    }

    if(cnt!=cntfresh) cout<<-1<<endl;
    else cout<<tm<<endl;
    return 0;
}