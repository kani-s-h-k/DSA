#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    int r,c;
    for(int i =0;i<row;i++){
        if(board[i][col]==1) return false; 
    }
    r=row-1;
    c=col-1;
    while(r>=0 && c>=0){
        if(board[r][c]==1) return false;
        r--;
        c--;
    }
    r=row-1;
    c=col+1;
    while(r>=0 && c<n){
        if(board[r][c]==1) return false;
        r--;
        c++;
    }
    return true;
    
}

void nQueen(vector<vector<int>> &board, int row, int n){
    if(row>=n){
        for(int i =0;i<n;i++){
    	    for(int j =0;j<n;j++){
    	        cout<<board[i][j]<<" ";
    	    }
	        cout<<endl;
	    }
	    cout<<endl;
        return ;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j]=1;
            nQueen(board,row+1,n);
            board[row][j]=0;
        }
    }
}

int main() {
	int n;
	cin>>n;
	vector<vector<int>> board(n,vector<int>(n));
	for(int i =0;i<n;i++){
	    for(int j =0;j<n;j++){
	        board[i][j]=0;
	    }
 	}
    nQueen(board, 0,n);
	return 0;
}
