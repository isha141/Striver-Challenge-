vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
     vector<int>dis(n+1,1e8);
     vector<pair<int,int>>adj[n+1];
     for(auto itr: edges){
         adj[itr[0]].push_back({itr[1],itr[2]});
     }
     dis[src]=0;
     for(int i=0;i<n-1;++i){
         for(auto itr: edges){
             int u=itr[0];
             int v=itr[1];
             int w=itr[2];
             if(dis[v]>dis[u]+w){
                 dis[v]=dis[u]+w;
             }
         }
     }
     return dis;
}
