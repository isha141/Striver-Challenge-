class Solution{
    private: 
    bool ok(int node,int color,bool graph[101][101],int n,vector<int>&col){
        for(int i=0;i<n;++i){
            if(i!=node && graph[i][node]==1 && col[i]==color)
              return 0;
        }
        return 1;
    }
    int solve(int node,bool graph[101][101],int m,int n,vector<int>&col){
        if(node>=n)
           return 1;
        
        for(int j=0;j<m;++j){
            if(ok(node,j,graph,n,col)){
                col[node]=j;
                if(solve(node+1,graph,m,n,col)){
                     return 1;
                }
                col[node]=-1;
            }
        }
        return 0;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>col(n,-1);
        return solve(0,graph,m,n,col);
    }
}; 

