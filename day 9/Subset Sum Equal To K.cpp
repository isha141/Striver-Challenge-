#include <bits/stdc++.h> 
int dp[1001][1001];
int solve(int i,int n,int k,vector<int>&arr){
      if(k==0)
        return 1;
    if(i>=n)
       return 0;
    if(k<0) return 0;
    if(dp[i][k]!=-1)
       return dp[i][k];
    int take=solve(i+1,n,k-arr[i],arr);
    int not_take=solve(i+1,n,k,arr);
    return dp[i][k]=(take | not_take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) { 
    memset(dp,-1,sizeof(dp));
    return solve(0,n,k,arr);
}


// -------------------------------Tablulation ----------------------------------
bool subsetSumToK(int n, int k, vector<int> &arr) { 
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    if(arr[0]<=k){
        dp[0][arr[0]]=1;
    }
    for(int i=0;i<n;++i){
        dp[i][0]=1;
    }
    for(int i=1;i<n;++i){
      for(int j=1;j<=k;++j){
          bool not_take=dp[i-1][j];
          int take=0;
          if(arr[i]<=j){
              take=dp[i-1][j-arr[i]];
          }
          dp[i][j]=(take | not_take);
      }        
    }
    return dp[n-1][k];
}
