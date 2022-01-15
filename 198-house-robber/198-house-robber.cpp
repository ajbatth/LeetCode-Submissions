class Solution {
private:
    int robbery(vector<int>&money,int idx,vector<int>&dp){
        
        if(idx>=money.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int select=money[idx]+robbery(money,idx+2,dp);
        int leave=robbery(money,idx+1,dp);
        return dp[idx]=max(select,leave);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
              return robbery(nums,0,dp);  
    }
};