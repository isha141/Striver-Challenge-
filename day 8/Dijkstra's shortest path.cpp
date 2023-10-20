vector<int> dijkstra(vector<vector<int>> &edge, int V, int edges, int s)
{ 
    vector<pair<int,int>>adj[V];
    for(auto itr: edge){
        adj[itr[0]].push_back({itr[1],itr[2]});
        adj[itr[1]].push_back({itr[0],itr[2]});
    }
    vector<int>dis(V,INT_MAX); 
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        auto itr=pq.top();
        pq.pop();
        int node=itr.second;
        for(auto iit: adj[node]){
            if(dis[iit.first]>dis[node]+iit.second){
                dis[iit.first]=dis[node]+iit.second;
                pq.push({dis[iit.first],iit.first});
            }
        }
    }
    return dis;
}
