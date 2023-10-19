// ----------------------------------------Memoization ------------------------------------------
int solve(int i,int last,vector<vector<int>>&points,int n,vector<vector<int>>&dp){
    if(i>=n)
      return 0;
    if(dp[i][last+1]!=-1)
       return dp[i][last+1];
    int take=0;
    int not_take=0;
    if(last==-1){
        take=max(points[i][0]+solve(i+1,0,points,n,dp),max(points[i][1]+solve(i+1,1,points,n,dp), 
        points[i][2]+solve(i+1,2,points,n,dp)));
    }
    if(last==0){
        take=max(points[i][1]+solve(i+1,1,points,n,dp),points[i][2]+solve(i+1,2,points,n,dp));
    }
    if(last==1){
        take=max(points[i][0]+solve(i+1,0,points,n,dp),points[i][2]+solve(i+1,2,points,n,dp));
    }
    if(last==2){
        take=max(points[i][1]+solve(i+1,1,points,n,dp),points[i][0]+solve(i+1,0,points,n,dp));
    }
    not_take=solve(i+1,last,points,n,dp);
    return dp[i][last+1]=max(take,not_take);
}
int ninjaTraining(int n, vector<vector<int>> &points)
{   vector<vector<int>>dp(n,vector<int>(4,-1));
     return solve(0,-1,points,n,dp);
} 



// -------------------------------------------------Tabulation -------------------------------------------- 


int ninjaTraining(int n, vector<vector<int>> &points)
{   vector<vector<int>>dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]); 
    dp[0][1]=max(points[0][0],points[0][2]);;
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int i=1;i<n;++i){
        for(int last=0;last<=3;++last){
            for(int day=0;day<=2;++day){
                if(last!=day){
                    dp[i][last]=max(dp[i][last],points[i][day]+dp[i-1][day]);
                }
            }
        }
    }
    return dp[n-1][3];
}
