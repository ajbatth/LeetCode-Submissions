class Solution {
private:
    int robb(vector<int>& money,int idx,vector<int>&dp){
        if(idx>=money.size()){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int robbed=money[idx]+robb(money,idx+2,dp);
        int not_robbed=robb(money,idx+1,dp);
        return dp[idx]= max(robbed,not_robbed);
    }
    
public:
    int rob(vector<int>& nums) {
        vector<int>first,last,dp1(nums.size(),-1),dp2(nums.size(),-1);
        if(nums.size()==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0)last.push_back(nums[i]);
            if(i!=nums.size()-1)first.push_back(nums[i]);
        }
        int f=robb(first,0,dp1);
        
        int l= robb(last,0,dp2);
        return max(f,l);
        
    }
};