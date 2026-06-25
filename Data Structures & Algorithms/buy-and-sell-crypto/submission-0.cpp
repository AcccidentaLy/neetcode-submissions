
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int maxprofit = 0;

        int n = prices.size();
        for(int i = 1; i < n; i++){
            low = min(low, prices[i]);
            maxprofit = max(maxprofit, prices[i]-low);
        }

        return maxprofit;
    }
};
