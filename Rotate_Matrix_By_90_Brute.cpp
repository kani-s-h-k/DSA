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
	for(int i =0;i<row;i++){
	    for(int j =0;j<col;j++){
	        if(i<j && i!=j){
	            swap(matrix[i][j],matrix[j][i]);
	        }
	    }
	}
	int startCol = 0,endCol = col-1;
	while(startCol<endCol){
	    for(int i =0;i<row;i++){
	       swap(matrix[i][startCol],matrix[i][endCol]);
	        }
	    startCol++;
	    endCol--;
	}
	for(int i =0;i<row;i++){
	    for(int j =0;j<col;j++){
	        cout<<matrix[i][j]<<" ";
	    }
	    cout<<endl;
	}
}
