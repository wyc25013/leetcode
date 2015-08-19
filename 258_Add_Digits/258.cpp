class Solution {
public:
    int addDigits(int num) {
        int ret = num%9;
        if(!ret && num) return 9;
        else return ret;
    }
};