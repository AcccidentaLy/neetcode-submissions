class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxf = 0;
        int right = 0;
        int res = 0;

        unordered_map<char, int> freq;

        while(left <= right && right < s.length()){
            freq[s[right]]++;
            maxf = max(maxf, freq[s[right]]);

            while(right-left+1 > maxf+k){
                freq[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};
