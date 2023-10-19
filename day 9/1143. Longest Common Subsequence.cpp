int dp[1001][1001];
class Solution {
    private:
    int n,m;
    int solve(int i,int j,string &a,string &b){
        if(i>=n || j>=m)
              return 0;
        int take=0;
        int not_take=0;
        if(dp[i][j]!=-1)
              return dp[i][j];
        if(a[i]==b[j])
            take=1+solve(i+1,j+1,a,b);
        not_take=max(solve(i+1,j,a,b),solve(i,j+1,a,b));
        return dp[i][j]=max(take,not_take);
    }
public:
    int longestCommonSubsequence(string a, string b) {
          n=a.size();
          m=b.size();
          memset(dp,-1,sizeof(dp));
          return solve(0,0,a,b);
    }
};



// -------------------------------------------------- Tabulation ------------------------------------------------------- 

int longestCommonSubsequence(string a, string b) {
          n=a.size();
          m=b.size();
          vector<vector<int>>dp(n+1,vector<int>(m+1,0));
          for(int i=1;i<=n;++i){
              for(int j=1;j<=m;++j){
                  int take=0;
                  int not_take=0;
                  if(a[i-1]==b[j-1]){
                      take=1+dp[i-1][j-1];
                  }
                  not_take=max(dp[i-1][j],dp[i][j-1]);
                  dp[i][j]=max(take,not_take);
              }
          }
          return dp[n][m];
}
