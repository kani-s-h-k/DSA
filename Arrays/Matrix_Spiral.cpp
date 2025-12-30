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
	cout<<endl;
	vector<int> temp;
	int left =0,top=0,right = col-1,bottom=row-1;
	while(left<=right && top<=bottom){
	    for(int i = left;i<=right;i++){
	        temp.emplace_back(matrix[top][i]);    
	    }
	    top++;
	    for(int i =top;i<=bottom;i++){
	        temp.emplace_back(matrix[i][right]);
	    }
	    right--;
	    if(top<=bottom){
	        for(int i = right;i>=left;i--){
	            temp.emplace_back(matrix[bottom][i]);
	        }
	        bottom--;
	    }
	    if(left<=right){
	        for(int i = bottom;i>=top;i--){
	        temp.emplace_back(matrix[i][left]);
	    }
	    left++; 
	    }
	    
	}
	
    for(auto it:temp){
        cout<<it<<" ";
    }

}
