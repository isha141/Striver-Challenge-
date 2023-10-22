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
public:
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>ans;
          stack<TreeNode*>s;
          // s.push(root);
          while(root!=NULL || s.size()!=0){
              if(root!=NULL){
                  s.push(root);
                  root=root->left;
              }
              else{
                  if(s.size()==0) 
                        return ans;
                  auto itr=s.top();
                  s.pop();
                  ans.push_back(itr->val);
                  root=itr->right;
              }
          }
         return ans;
    }
};
