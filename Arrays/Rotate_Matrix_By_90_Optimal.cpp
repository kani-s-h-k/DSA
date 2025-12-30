#include <bits/stdc++.h>
using namespace std;

int main() {
	int row,col;
	cin>>row;
	cin>>col;
	vector<vector<int>> matrix(row,vector<int>(col));
	for(int i =0;i<row;i++){
	    for(int j =0;j<col;j++){
	        cin>>matrix[i][j];
	    }
	}
	for(int i =0;i<=row-2;i++){
	    for(int j =i+1;j<=row-1;j++){
	        swap(matrix[i][j],matrix[j][i]);
	    }
	}
    for(int i =0;i<row;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
	for(int i =0;i<row;i++){
	    for(int j =0;j<col;j++){
	        cout<<matrix[i][j]<<" ";
	    }
	    cout<<endl;
	}
}
