#include <bits/stdc++.h> 
int dp[101][1002];
int solve(int i,vector<int>&weight,vector<int>&value,int n,int maxi){
    if(maxi==0)
      return 0;
    if(i>=n) 
      return 0;
    if(maxi<0)
      return INT_MIN;
    if(dp[i][maxi]!=-1)
      return dp[i][maxi];
    int take=0;
    if(maxi>=weight[i])
     take=value[i]+solve(i+1,weight,value,n,maxi-weight[i]);
    int not_take=solve(i+1,weight,value,n,maxi);
    return dp[i][maxi]=max(take,not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   memset(dp,-1,sizeof(dp));
    return solve(0,weight,value,n,maxWeight);
}


// -----------------------------------Tabluation ---------------------------------

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{  
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
    for(int i=weight[0];i<=maxWeight;++i){
      dp[0][i]=value[0];
    }
    for(int i=1;i<n;++i){
      for(int j=1;j<=maxWeight;++j){
         int not_take=0;
         int take=0;
         not_take=dp[i-1][j];
         if(j>=weight[i]){
           take=value[i]+dp[i-1][j-weight[i]];
         }
         dp[i][j]=max(take,not_take);
      }
    }
    return dp[n-1][maxWeight];
} 
