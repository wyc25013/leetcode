class Solution {
    // use map to do DP
    unordered_map<int,int> a;
public:
    int countDigitOne(int n) {
        if(n<=0) return 0;
        if(a.find(n) != a.end()) return a[n];
        if(n >=1 && n <= 9) {
            a[n] = 1;
            return 1;
        }
        
        // find num of digits(cnt)
        // and the highest digit(m)
        int cnt = 1;
        int m = n;
        while(m/10){
            m /= 10;
            cnt++;
        }
        
        // find the max number that has digits
        // less than those of n by 1
        // eg. if n has 3 digits, then leastMax = 99
        //     if n has 5 digits, then leastMax = 9999
        int leastMax = pow(10,cnt-1)-1;
        int clm = countDigitOne(leastMax);
        int ret = clm;
        if(m==1){
            ret += (n-leastMax)+countDigitOne(n-leastMax-1);
        }else{
            int l = m;
            ret += clm + leastMax+1;
            while(l != 2){
                ret += clm;
                l--;
            }
            ret += countDigitOne(n-m*(leastMax+1));
        }
        a[n] = ret;
        return ret;
    }
};