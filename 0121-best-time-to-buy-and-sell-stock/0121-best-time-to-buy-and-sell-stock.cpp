class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0];
        int max_profit=INT_MIN;
        int profit;
        
        for(auto i:prices)
        {
            min_price=min(i,min_price);
            profit=i-min_price;
            max_profit=max(profit,max_profit);
        }
        return max_profit;
    }
};