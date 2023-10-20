#include<bits/stdc++.h>
// int dp[101][101];
int solve(int i,int len,vector<int>&price,int n){
	   if(i>=n)  
	   return 0;
	   if(len==0) return 0;
	   int take=0;
	   int not_take=0;
	   if(dp[i][len]!=-1) 
	    return dp[i][len];
	   if(len>=i+1)
	   take=price[i]+solve(i,len-i-1,price,n);
	   not_take=solve(i+1,len,price,n);
	   return dp[i][len]=max(take,not_take);
} 

// -------------------------------------------------- Tablulation ----------------------------------------------------- 

int cutRod(vector<int> &price, int n)
{   
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	for(int i=0;i<=n;++i){
		dp[0][i]=price[0]*i;
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=n;++j){
			int not_take=dp[i-1][j];
			int take=0;
			if(j>=i+1){
				take=dp[i][j-i-1]+price[i];
			}
			dp[i][j]=max(take,not_take);
		}
	}
	return dp[n-1][n];
}
 
