#include <bits/stdc++.h> 
int dp[101][101];
int solve(int i,int j,vector<vector<int>>&grid){
    if(i<0 || j<0)
      return 1e9;
    if(i==0  && j==0)
      return grid[0][0];
    if(dp[i][j]!=-1)
       return dp[i][j];
    int left=grid[i][j]+solve(i,j-1,grid);
    int top=grid[i][j]+solve(i-1,j,grid);
    return dp[i][j]=min(top,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    memset(dp,-1,sizeof(dp));
    return solve(n-1,m-1,grid);
}

// --------------------------Tablulation ----------------------------------
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<n;++i){
     dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int j=1;j<m;++j){
        dp[0][j]=dp[0][j-1]+grid[0][j];
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
          int  top=dp[i-1][j];
          int bottom=dp[i][j-1];
          dp[i][j]=min(top,bottom)+grid[i][j];
        }
    }
    return dp[n-1][m-1];
}
