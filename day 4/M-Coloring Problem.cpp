class Solution{
    private:
    bool ok(int node,int color,vector<int>&col,bool graph[101][101]){
          for(int i=0;i<101;++i){
              if(i!=node && graph[node][i]==1 && col[i]==color)
               return 0;
          }
        return 1;
    }
    bool solve(int node,bool graph[101][101],int m,int n,vector<int>&col){
            if(node>=n)
            return 1;
            // cout<<node<<"-->"<<endl;
            for(int i=1;i<=m;++i){
              if(ok(node,i,col,graph)){
                  col[node]=i;
                  if(solve(node+1,graph,m,n,col))
                    return 1;
                  col[node]=-1;
              }
            }
          return 0;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // cout<<"high"<<endl;
        vector<int>col(n,-1);
        return solve(0,graph,m,n,col);
        return 0;
    }
    
};
