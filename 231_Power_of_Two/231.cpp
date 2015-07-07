class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==0) return false;
        int res = n % 2;
        if(res==0) return isPowerOfTwo(n/2);
        else return false;
    }
};
