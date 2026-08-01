class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = 0, sell = 1;

        while(sell < prices.size()){
            if(prices[buy] < prices[sell]){ // profit
                maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            }else{ // selling price > buying price: found a lower buying price
                buy = sell;
            }
            sell++;
        }
        return maxProfit;
    }
};
