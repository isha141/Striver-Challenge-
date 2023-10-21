class Solution
{ 
    private:
    bool solve(int node,int parent,vector<int>&vis,vector<int>&low,vector<int>&tim,vector<int>adj[],int c,int d,int &timer){
        vis[node]=1;
        low[node]=tim[node]=timer++;
        for(auto itr: adj[node]){
            if(itr==parent) continue;
            if(!vis[itr]){
                if(solve(itr,node,vis,low,tim,adj,c,d,timer))
                 return 1;
            low[node]=min(low[itr],low[node]);
            if(low[itr]>tim[node]){
             if((itr==c && node==d) || (node==c && itr==d))
               return 1;
            }
             }
            else{
                low[node]=min(low[itr],low[node]);
            }
        }
        return 0;
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int timer=0;
        vector<int>vis(V,0);
        vector<int>tim(V,0);
        vector<int>low(V,0);
        for(int i=0;i<V;++i){
            if(!vis[i]){
                if(solve(i,-1,vis,low,tim,adj,c,d,timer))
                  return 1;
            }
        }
        return 0;
    }
};
