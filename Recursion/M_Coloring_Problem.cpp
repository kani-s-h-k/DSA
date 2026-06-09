class Solution{
    bool possible(int node, int n, vector<int> &color, vector<vector<int>> &edges, int col){
    for(auto &e: edges){
        int u = e[0];
        int v = e[1];
        if(u==node && color[v]==col) return false;
    }
    return true;
}
    bool solve(int node, int m, int n, vector<vector<int>> &edges, vector<int> &color){
        if(node==n) return true;
        for(int i = 1;i<=m;i++){
            if(possible(node,n,color,edges,i)){
                color[node]=i;
                if(solve(node+1,m,n,edges,color)) return true;
                color[node]=0;
            }
        }
        return false;
    }
public:
    bool graphColoring(vector<vector<int> >& edges, int m, int n) {
    	vector<int> color(n,0);
        return solve(0,m,n,edges,color);
    }
};