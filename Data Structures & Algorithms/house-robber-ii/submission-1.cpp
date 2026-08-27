class Solution {
public:
    vector<int> mem;

    int robHelp(vector<int>& nums){
        int n = nums.size();
        mem.assign(n+2, -1);

        mem[n] = 0;
        mem[n+1] = 0;

        for(int i = n-1; i >= 0; i--){
            mem[i] = max(mem[i+1], mem[i+2] + nums[i]);
        }
        return mem[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> n1 = nums;
        vector<int> n2 = nums;
        vector<int> n3 = nums;

        n1[0] = 0;
        n2[n-1] = 0;
        n3[0] = 0;
        n3[n-1] = 0;

        int res = 0;
        int n1_ret = robHelp(n1);
        res = max(res, n1_ret);
        int n2_ret = robHelp(n2);
        res = max(res, n2_ret);
        int n3_ret = robHelp(n3);
        res = max(res, n3_ret);

        return res;

    }
};
