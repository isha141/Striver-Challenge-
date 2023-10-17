class Solution
{
    int d=256;
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>ans;
            int m=pat.size();
            int n=txt.size();
            int mod=INT_MAX;
            // step 1--> calculate the hash value  
            int hashvalue=1;
            for(int i=0;i<m-1;++i){
                hashvalue=(hashvalue*d)%mod;
            }
            int textval=0;
            int patval=0;
            for(int i=0;i<m;++i){
                textval=(textval*d+txt[i]-'a')%mod;
                patval=(patval*d+ pat[i]-'a')%mod;
            }
            for(int i=0;i<=n-m;++i){
                if(patval==textval){
                    bool flag=0;
                    for(int j=0;j<m;++j){
                        if(txt[i+j]!=pat[j]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        ans.push_back(i+1);
                    }
                }
                if(i<=n-m){
                    textval=(d*(textval-(txt[i]-'a')*hashvalue)+txt[i+m]-'a')%mod;
                }
                if(textval<0){
                    textval+=mod;
                }
            }
            if(ans.size())
              return ans;
            return {-1};
        }
     
}; 

