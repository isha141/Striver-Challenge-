class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
          vector<int>ans;
          int n=n1.size();
          int m=n2.size();
          map<int,int>mp;
          for(auto itr: n1)
                mp[itr]=-1;
          stack<int>s;
          for(int i=m-1;i>=0;--i){
              while(!s.empty() && s.top()<n2[i])
                   s.pop();
              if(s.size()){
                  mp[n2[i]]=s.top();
              }
              s.push(n2[i]);
          }
          for(int i=0;i<n;++i){
              ans.push_back(mp[n1[i]]);
          }
          return ans;
    }
};
