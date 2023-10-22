class Solution {
    private:
    map<Node*,Node*>mp;
    Node *head=NULL;
    void findparent(Node *root,int target){
        if(root==NULL)
         return;
        if(root->data==target){
            head=root;
        }
        findparent(root->left,target);
        findparent(root->right,target);
        if(root->left)
        mp[root->left]=root;
        if(root->right)
        mp[root->right]=root;
    }
    int solve(){
        queue<Node *>q;
        q.push(head);
        int ans=0;
        map<Node*,int>vis;
        vis[head]=1;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                // cout<<itr->data<<"-->"<<endl;
                if(itr->left  && vis.find(itr->left)==vis.end()){
                    vis[itr->left]=1;
                    q.push(itr->left);
                }
                if(itr->right && vis.find(itr->right)==vis.end()){
                    vis[itr->right]=1;
                    q.push(itr->right);
                }
                if(mp.find(itr)!=mp.end() && vis.find(mp[itr])==vis.end()){
                    vis[mp[itr]]++;
                    q.push(mp[itr]);
                }
            }
            if(q.size())
            ans+=1;
        }
        return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
       if(root==NULL) return 0;
       findparent(root,target); 
       return solve();
    }
}; 
