class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>mp;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                int x=itr.first;
                Node *temp=itr.second;
                mp[x]=temp->data;
                if(temp->left)
                 q.push({x-1,temp->left});
                if(temp->right){
                    q.push({x+1,temp->right});
                }
            }
        }
        for(auto itr: mp){
            ans.push_back(itr.second);
        }
        return ans;
    }
}; 
