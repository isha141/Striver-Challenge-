class Solution {
    vector<vector<int>>ans;
    int n;
    void solve(int i,vector<int>&nums,vector<int>&ds){
        ans.push_back(ds);
        if(i>=n) return;
        for(int j=i;j<n;++j){
            if(j>i && nums[j]==nums[j-1]) 
                continue;
            ds.push_back(nums[j]);
            solve(j+1,nums,ds);
            ds.pop_back();
        }
        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<int>ds;
         n=nums.size();
         sort(nums.begin(),nums.end());
         solve(0,nums,ds);
         return ans;
    }
};
