#include <bits/stdc++.h>
using namespace std;

int main() {
	int row,col;
	cin>>row;
	cin>>col;
	vector<vector<int>>matrix(row,vector<int>(col));
	for(int i =0;i<row;i++){
	    for(int j = 0;j<col;j++){
	        cin>>matrix[i][j];
	    }
	}
	vector<pair<int,int>> temp;
	int rowI,colI;
	for(int i =0;i<row;i++){
	    for(int j = 0;j<col;j++){
	        if(matrix[i][j]==0){
	            rowI = i;
	            colI = j;
	            temp.emplace_back(i,j);
	        }
	    }
	    
	}
	for(auto it: temp){
	    for(int j =0;j<col;j++){
	        matrix[it.first][j]=0;
	    }
	    for(int i =0;i<row;i++){
	        matrix[i][it.second]=0;
	    }
	}
	for(int i =0;i<row;i++){
	    for(int j = 0;j<col;j++){
	        cout<<matrix[i][j]<<" ";
	    }
	    cout<<endl;
	}
    return 0;
}
