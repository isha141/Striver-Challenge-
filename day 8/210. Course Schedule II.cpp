class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
          vector<int>ans;
          vector<int>adj[num];
          vector<int>indeg(num,0);
          for(auto it: pre){
              adj[it[1]].push_back(it[0]);
              indeg[it[0]]++;
          } 
           queue<int>q;
          for(int i=0;i<num;++i){
              if(indeg[i]==0){
                  q.push(i);
              }
          }
          while(!q.empty()){
              auto itr=q.front();
              q.pop();
              ans.push_back(itr);
              indeg[itr]--;
              for(auto iit: adj[itr]){
                  indeg[iit]--;
                  if(indeg[iit]==0){
                      q.push(iit);
                  }
              }
          }
          if(ans.size()==num)
                return ans;
          return {};
    }
};
