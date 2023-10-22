/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    TreeNode *solve(int prestart,int preend,vector<int>&pre,int instart,int inend,map<int,int>&mp){
           if(prestart>preend || instart>inend)
                 return NULL;
           int inroot=mp[pre[prestart]];
           int numsleft=inroot-instart;
           TreeNode *root=new TreeNode(pre[prestart]);
           root->left=solve(prestart+1,prestart+numsleft,pre,instart,inroot-1,mp);
           root->right=solve(prestart+numsleft+1,preend,pre,inroot+1,inend,mp);
           return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size(); 
        map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[in[i]]=i;
        }
        return solve(0,n-1,pre,0,n-1,mp);
    }
};
