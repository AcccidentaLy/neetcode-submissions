class Solution {
public:
    bool okaySpeed(vector<int>& piles, int k, int h){
        int totHours = 0;
        for(int vals : piles){
            if(vals % k == 0){
                totHours += vals/k;
            }else{
                totHours += vals/k+1;
            }
        }
        return totHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        for(int vals : piles){
            r = max(r, vals);
        }

        while(l < r){
            int mid = (l + r)/2;
            if(okaySpeed(piles, mid, h)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }
};
