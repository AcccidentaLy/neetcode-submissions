class Solution {
public:
    vector<int> dp;

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        dp.assign(amount + 1, -1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            int minComp = amount;
            bool changeComp = false;
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && dp[i-coins[j]] != -1){
                    minComp = min(minComp, dp[i-coins[j]] + 1);
                    changeComp = true;
                }
            }
            if(changeComp){
                dp[i] = minComp;
            }
        }

        return dp[amount];
    }
};
