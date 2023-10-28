class Solution {
    private:
    vector<vector<int>>ans;
    int n;
    void solve(int i,vector<int>&ds,vector<int>&nums){
        ans.push_back(ds);
        for(int j=i;j<n;++j){
            if(j>i && nums[j]==nums[j-1])
                continue;
          ds.push_back(nums[j]); 
            solve(j+1,ds,nums);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
            n=nums.size();
            vector<int>ds;
            solve(0,ds,nums);
            return ans;
    }
};
