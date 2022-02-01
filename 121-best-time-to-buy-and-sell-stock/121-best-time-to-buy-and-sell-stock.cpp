class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,maxProfit=0;
        
        int buy_price=prices[0], sell_price=prices[0];
        
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buy_price){
                buy_price=prices[i];
                sell_price=buy_price;
            }
            if(prices[i]>sell_price){
                sell_price=prices[i];
            }
            profit=sell_price-buy_price;
            maxProfit=max(maxProfit,profit);
            
        }
        
        return maxProfit;
    }
};