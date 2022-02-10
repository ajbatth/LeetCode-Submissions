class Solution {
private:
    int maxP(vector<int>&prices,int idx,bool bought,int bought_price,vector<vector<int>>&dp){
        int n=prices.size();
        if(idx>=n-1){
            if(idx==n-1 && bought) return prices[idx]-bought_price;
            // if(idx==n-1 && !bought) return 0;
            return 0;
        }
        if(dp[idx][bought]!=-1)return dp[idx][bought];
        
        int profit=-9999999;
        if(!bought){
            for(int i=idx;i<n;i++){
                int pro= maxP(prices,i+1,true,prices[i],dp);
                profit=max(pro,profit);
            }
        }
        else{
            
            for(int i=idx;i<n;i++){
                int pro=prices[i]-bought_price+maxP(prices,i+2,false,0,dp);
                profit=max(profit,pro);
            }
        }
        return dp[idx][bought]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return maxP(prices,0,false,0,dp);
        
    }
};