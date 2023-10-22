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
class info{
   public:
    TreeNode *root;
    bool flag;
    stack<TreeNode*>s;
    info(TreeNode *root,bool flag){
          this->root=root;
          this->flag=flag; 
          inorder(root,flag);
    }
    void inorder(TreeNode *root,bool flag){
          while(root!=NULL){
              s.push(root);
              if(!flag)
                  root=root->left;
              else
                  root=root->right;
          }
    }
    int getval(bool flag){
          auto itr=s.top();
           s.pop();
           if(flag==0){
               inorder(itr->right,0);
           }
           else{
               inorder(itr->left,1);
           }
         return itr->val;
    }  
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
         if(root==NULL) 
               return 0;
        info obj1(root,0); //   small->bigger;
        info obj2(root,1); //   bigger->smaller;
        int a=obj1.getval(0);
        int b=obj2.getval(1);
        cout<<a<<"->"<<b<<endl;
        while(a<b){ 
             // cout<<a<<"-->"<<b<<endl;
            if(a+b==k)
                  return 1;
             else if(a+b<k){
                 a=obj1.getval(0);
             }
             else{
                 b=obj2.getval(1);
             }
        }
         return 0;
    }
};
