class Solution {
private:
    bool is_possible(vector<int>& nums,int idx,int target,vector<vector<int>>&dp){
        if(dp[idx][target]!=-1)return dp[idx][target];
        if(target==0)return true;
        if(idx==0){
            return target==nums[idx];
        }
        bool take=false;
        if(target>=nums[idx])take=is_possible(nums,idx-1,target-nums[idx],dp);
        bool nottake=is_possible(nums,idx-1,target,dp);
        
        return dp[idx][target]=(take|nottake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        
        return is_possible(nums,n-1,sum/2,dp);
    }
};