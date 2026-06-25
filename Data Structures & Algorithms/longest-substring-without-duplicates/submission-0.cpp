class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_set<char> exist;

        while(left <= right && right < len){
            while(left < right && exist.find(s[right]) != exist.end()){
                exist.erase(s[left]);
                left++;
            }
            exist.insert(s[right]);
            right++;
            ans = max(ans, right-left);
        }

        return ans;

    }
};
