class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        vector<int> a(n+1,0);
        a[0] = 1;
        a[1] = 1;
        int i = 2;
        while(i <= n){
            a[i] = a[i-1] + a[i-2];
            i++;
        }
        return a[n];
    }
};