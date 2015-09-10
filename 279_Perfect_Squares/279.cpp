class Solution {
public:
    int numSquares(int n){
        static vector<int> dp(1,0); // static here is to keep data between test cases
        while (dp.size() <= n) {
            int m = dp.size(), squares = INT_MAX;
            for (int i=1; i*i<=m; ++i)
                squares = min(squares, dp[m-i*i] + 1);
            dp.push_back(squares);
        }
        return dp[n];
    }
    /*
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i = 1; i <= n; i++){
            int numSq = INT_MAX;
            for(int j = 1; j*j <= i; j++){
                numSq = min(numSq, dp[i-j*j]+1);
            }
            dp[i] = numSq;
        } 
        return dp[n];
    }
    */
};