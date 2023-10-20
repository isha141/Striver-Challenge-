class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here 
        string ans="";
        vector<int>adj[k];
        for(int i=0;i<n-1;++i){
            string a=dict[i];
            string b=dict[i+1];
            for(int j=0;j<min(a.size(),b.size());++j){
                if(a[j]!=b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        vector<int>indeg(k,0);
        for(int i=0;i<k;++i){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<k;++i){
            if(indeg[i]==0 && adj[i].size()){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            ans+=(itr+'a');
            indeg[itr]--;
            for(auto iit: adj[itr]){
                indeg[iit]--;
                if(indeg[iit]==0)
                q.push(iit);
            }
        }
        return ans;
    } 
}; 

