class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int vals : nums){
            cnt[vals]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto& vals : cnt){
            q.push({vals.second, vals.first});
            while(q.size() > k){
                q.pop();
            }
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
