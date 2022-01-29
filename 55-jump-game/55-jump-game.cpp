class Solution {
private:
    bool jump(vector<int>& nums,int idx,vector<int>&dp){
        int n=nums.size();
        if(idx>=n-1){
            if(idx==n-1) return true;
            return false;
        }
        if(dp[idx]!=-1)return dp[idx];
        
        bool pick=0;
        for(int i=1;i<=nums[idx];i++){
            if(pick)return pick;
            pick=jump(nums,idx+i,dp);
        }
        return dp[idx]= pick;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return jump(nums,0,dp);
    }
};