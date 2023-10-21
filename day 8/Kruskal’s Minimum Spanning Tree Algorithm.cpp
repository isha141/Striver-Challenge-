bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
	 return a.first<b.first;
}
class disjoint{
	public:
	vector<int>rank;
	vector<int>parent;
	disjoint(int n){
		rank.resize(n,0);
		parent.resize(n,0);
		for(int i=0;i<n;++i){
			parent[i]=i;
		}
	}
	int findparent(int u){
		if(parent[u]==u)
		  return u;
		return parent[u]=findparent(parent[u]);
	}
	void unionbyRank(int u,int v){
		u=findparent(u);
		v=findparent(v);
		if(u==v)
		  return ;
		if(rank[u]<rank[v]){
			parent[u]=v;
			rank[v]++;
		}
		else{
			parent[v]=u;
			rank[u]++;
		}
	}
};
int kruskalMST(int n, vector<vector<int>> &edges)
{ 
	 disjoint obj(n+2);
	 vector<pair<int,pair<int,int>>>ds;
	 for(auto itr: edges){
		 ds.push_back({itr[2],{itr[0],itr[1]}});
   }
	 sort(ds.begin(),ds.end(),cmp);
	//  for(auto itr: ds)
	//   cout<<itr.first<<"->"<<itr.second.first<<"-"<<itr.second.second<<endl;
	 int m=edges.size();
	 int ans=0;
	 for(int i=0;i<m;++i){
	
      int u=ds[i].second.first;
	  int v=ds[i].second.second;
	  if(obj.findparent(u)!=obj.findparent(v)){
		    obj.unionbyRank(u,v);
			ans+=ds[i].first;
	  }
	 }
	 return ans;
}
