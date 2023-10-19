int dp[103];
class Solution { 
    private:
    int n;
    int solve(int i,vector<int>&nums){
        if(i>=n)
             return 0;
        int take=0;
        int not_take=0;
        if(dp[i]!=-1)
              return dp[i];
        take=nums[i]+solve(i+2,nums);
        not_take=solve(i+1,nums);
        return dp[i]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
          n=nums.size();
          dp[0]=nums[0];
          for(int i=1;i<n;++i){
            int take=nums[i];
              if(i-2>=0){
                  take+=dp[i-2];
              }
             int not_take=dp[i-1];
              dp[i]=max(take,not_take);
          }
          return dp[n-1];
    }
};
