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
    int minj(vector<int>& nums,vector<int>&dp){
        int n=nums.size();
        dp[n-1]=0;
        for(int idx=n-2;idx>=0;idx--){
            int mini=99999;
            for(int i=1;i<=nums[idx];i++){
                if(idx+i<n){
                int jumps=1+dp[idx+i];
                mini=min(mini,jumps);
                }
            }
            dp[idx]= mini;
        }
        return dp[0];
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return minj(nums,dp);
    }
};