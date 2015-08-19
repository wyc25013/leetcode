class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ret(n,1);
        int i1 = 0; int i2 = 0; int i3 = 0;
        for(int i = 1; i < n; i++){
            int l1 = ret[i1]*2;
            int l2 = ret[i2]*3;
            int l3 = ret[i3]*5;
            ret[i] = min(min(l1,l2),l3);
            if(l1 == ret[i]) i1++;
            if(l2 == ret[i]) i2++;
            if(l3 == ret[i]) i3++;
        }
        return ret[n-1];
    }
};