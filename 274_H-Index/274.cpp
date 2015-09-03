class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(!size) return 0;
        vector<int> dp(size+1,0);
        for(int i = 0; i < size; i++){
            plusOne(citations[i],dp);
        }
        int ret = 0;
        for(int i = size; i >= 0; i--){
            if(ret > i) return ret;
            if(ret < min(i,dp[i]))
                ret = min(i,dp[i]);
        }
        return ret;
    }
    
    void plusOne(int idx, vector<int>& dp){
        if(idx > dp.size()) idx = dp.size()-1;
        for(int i = 0; i <= idx; i++){
            dp[i]++;
        }
    }
};
// O(n*n) not so good.
// sort first can get O(nlogn).