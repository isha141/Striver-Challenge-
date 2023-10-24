class info{
    public:
    int size;
    int mini;
    int maxi;
    info(int mini,int maxi,int size){
         this->mini=mini;
         this->maxi=maxi;
         this->size=size;
    }
};
// int ans=0;
info solve(TreeNode *root){
        if(root==NULL){
            return {INT_MAX,INT_MIN,0};
        }
        if(root->left==NULL && root->right==NULL){
            return {root->data,root->data,1};
        }
        auto l=solve(root->left);
        auto r=solve(root->right);
        if(root->data>l.maxi && root->data<r.mini)
          return {min(l.mini,root->data),max(r.maxi,root->data),l.size+r.size+1};
        return {INT_MIN,INT_MAX,max(l.size,r.size)};
}
int largestBST(TreeNode * root) 
{
    // Write your code here. 
    if(root==NULL) return 0;
    return solve(root).size;
    // return ans;
}
