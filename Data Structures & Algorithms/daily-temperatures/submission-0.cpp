class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> unfound;
        int size = temperatures.size();
        vector<int> ret(size, 0);
        for(int i = 0; i < size; i++){
            while(!unfound.empty()){
                int comp = unfound.top();
                if(temperatures[i] > temperatures[comp]){
                    unfound.pop();
                    ret[comp] = i-comp;
                }else{
                    break;
                }
            }
            unfound.push(i);
        }
        return ret;
    }
};
