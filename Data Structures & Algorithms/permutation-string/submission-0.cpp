class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = s1.size()-1;
        sort(s1.begin(), s1.end());

        while(right < s2.size()){
            string comp = s2.substr(left, right-left+1);
            sort(comp.begin(), comp.end());
            if(comp == s1){
                return true;
            }
            left++;
            right++;
        }
        return false;
    }
};
