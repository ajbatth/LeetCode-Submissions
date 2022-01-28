class Solution {
private:
    int dne(vector<int>&nums,int idx,vector<int>&dp){
        int n=nums.size();
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        
        int pick=0,not_pick=0;
        int i=idx;
        for(;i<n && nums[i]==nums[idx];i++){
            pick+=nums[i];
        }
        int j=i;
        while(i<n && nums[i]==nums[idx]+1) i++;
        pick+=dne(nums,i,dp);
        
        not_pick+=dne(nums,j,dp);
        return dp[idx]= max(pick,not_pick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
       //int maxi=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int maxi=nums.size()+1;
        vector<int>dp(maxi,-1);
        return dne(nums,0,dp);
    }
};