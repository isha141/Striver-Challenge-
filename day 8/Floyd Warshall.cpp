int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
         vector<vector<int>>matrix(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<=n;++i){
            matrix[i][i]=0;
        }
        for(auto itr: edges){
            matrix[itr[0]][itr[1]]=itr[2];
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    if(matrix[i][k]==1e9 || matrix[k][j]==1e9){ 
                        continue;
                    }
                    if(matrix[i][j]>matrix[i][k]+matrix[k][j]){
                            matrix[i][j]=matrix[i][k]+matrix[k][j];
                    }
                }
            }
        }
        return matrix[src][dest];
}
