class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 17;
        while(i <= 32){
            uint32_t testr = (long long)pow(2,i-1);
            uint32_t testl = (long long)pow(2,32-i);
            
            if(((testr|n) != n) && ((testl|n) != n)){/*both 0*/}
            else if(((testr|n) == n) && ((testl|n) == n)){/*both 1*/}
            else n ^= (testr+testl);
            
            i++;
        }
        return n;
    }
};