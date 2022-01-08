/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(),-1) ;
        dp[prices.size()-1]=0;
        for(int i=0; i<dp.size();i++)
        maxProfitUtil(prices,dp,i);
        
        return *max_element(dp.begin(), dp.end());;
    }
    int maxProfitUtil(vector<int>& prices, vector<int>& dp, int index=0){
        if(index>=dp.size()){return 0;}
        if(dp[index]!=-1){return dp[index];}
        int maxProfit=0;
        for(int i=index+1; i<dp.size(); i++){
            int notBuy = maxProfitUtil(prices, dp,i);
            int profit = prices[i]-prices[index] +maxProfitUtil(prices, dp,i+2);
            maxProfit = max(maxProfit,profit);
            maxProfit = max(maxProfit,notBuy);
        }
        return dp[index]=maxProfit;
        
    }
};
