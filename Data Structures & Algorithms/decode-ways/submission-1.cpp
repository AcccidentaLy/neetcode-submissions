class Solution {
public:
    vector<int> memo;

    int recurseHelp(string s, int pos){
        if(s[pos] == '0'){
            return 0;
        }
        
        if(pos == s.length()){
            return 1;
        }
        
        if(memo[pos] != -1){
            return memo[pos];
        }
        int ways = recurseHelp(s, pos+1);
        if(pos+1 < s.length()){
            string curr_sub = s.substr(pos, 2);
            int comp = (s[pos] - '0')*10 + s[pos+1]-'0';
            if(comp <= 26){
                ways += recurseHelp(s, pos+2);
            }
        }
        return memo[pos] = ways;
    }
    int numDecodings(string s) {
        memo.assign(s.length(), -1);
        recurseHelp(s, 0);
        if(memo[0] > 0){
            return memo[0];
        }else{
            return 0;
        }
    }
};
