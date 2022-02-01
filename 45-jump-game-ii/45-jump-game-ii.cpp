class Solution {
private:
    int minjump(vector<int>& nums,int idx,vector<int>&dp){
        int n=nums.size();
        if(dp[idx]!=-1)return dp[idx];
        if(idx>=n-1){
            if(idx==n-1) return 0;
            return 999999;
        }
        int mini=99999;
        for(int i=1;i<=nums[idx];i++){
            if(idx+i<n){
            int jumps=1+minjump(nums,idx+i,dp);
            mini=min(mini,jumps);
            }
        }
        return dp[idx]= mini;
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return minjump(nums,0,dp);
    }
};