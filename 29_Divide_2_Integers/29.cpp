#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	bool ifneg = false;
    	if(dividend < 0){
    		dividend = -dividend;
    		ifneg = true;	
    	}
    	if(divisor < 0){
    		divisor = -divisor;
    		if(ifneg)
    			ifneg = false;
    		else
    			ifneg = true;
    	}
		if(dividend < divisor)
			return 0;
		if(divisor == 0)
			return INT_MAX;

		int ret = 0;
		while(dividend > 0){
			dividend -= divisor;
			ret++;
		}        
		if(dividend < 0){
			if(ifneg)
				return 1-ret;
			else
				return ret-1;
		}
		else{
			if(ifneg)
				return -ret;
			else
				return ret;
		}
    }
};
/*
class Solution {
    bool difsig(const int &a, const int &b)
    {
        return (a < 0) ^ (b < 0);
    }
    bool ngt(const int& a, const int& b)
    {
        if (a == b) return true;
        return (!difsig(a, b) && !difsig(b, b - a));
    }
public:
    int divide(int dividend, int divisor) 
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        if (divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        if (dividend != INT_MIN && abs(divisor) > abs(dividend)) return 0;
        int table[32][2];
        int l = 0;
        table[0][0] = 1;table[0][1] = divisor;
        if (difsig(dividend, divisor))
        {
            table[0][0] = -1;
            table[0][1] = -divisor;
        }
        while (true)
        {
            int t(table[l][1] + table[l][1]);
            if (!ngt(t, dividend))
                break;
            table[l + 1][0] = table[l][0] + table[l][0];
            table[l + 1][1] = t;
            l ++;
        }
        int ans[2]{};
        for (int i = l; i >= 0; -- i)
        {
            int t(ans[1] + table[i][1]);
            if (ngt(t, dividend))
            {
                ans[1] = t;
                ans[0] += table[i][0];
            }
        }
        return ans[0];
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor)       return INT_MAX;

        bool is_neg = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
        // use long to accommodate -INT_MIN
        long nominator = dividend > 0 ? (long)dividend : -((long)dividend);
        long denominator = divisor > 0 ? (long)divisor : -((long)divisor) ;

        // grade school algorithm
        int result = 0;
        int n = sizeof(int) << 3;
        for (int i = n - 1; i >= 0; i--) {
            if ((nominator >> i) >= denominator) {
                nominator -= (denominator << i);
                result |= (1 << i);
            }
        }

        if (INT_MIN == result)
            return is_neg ? result : INT_MAX;
        return (is_neg ? -result : result);
	

    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (divisor==0) return INT_MAX;
        long long res=double(exp(log(fabs(dividend))-log(fabs(divisor))));
        if ((dividend<0)^(divisor<0)) res=-res;
        if (res>INT_MAX) res=INT_MAX;
        return res;
    }
};
*/
int main(){
	Solution soln;
cout<<INT_MAX<<endl;
	int a = soln.divide(2147483647,1);
	cout << a << endl;
}