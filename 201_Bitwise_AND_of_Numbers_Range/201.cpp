#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0; 
        if(m < INT_MAX/2 && n >= 2*m) return 0;
        int c = 0;
        for(int hi = m; hi > 0; hi >>= 1,c++);
		vector<int> a(c,-1);
		for(long long i = m; i <= n; i++){
			for(int j = i,cnt = c-1; cnt >= 0; j >>= 1,cnt--){
				if(a[cnt] == 0) continue;
				if(j % 2)
					a[cnt] = 1;
				else 
					a[cnt] = 0;
			}
		}    
		int ret = 0; 
		for(int i = 0; i < c; i++){
			ret <<= 1;
			ret += a[i];
		}
		return ret;

		/* better bit manipulation solution

		int mask = ~0;
		while (mask != 0)
		{
		    if ((m & mask) == (n & mask))
		    {
		        break;
		    }
		    mask <<= 1;
		}
		return m & mask;

		*/

		/* simple one line solution
    	return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    	*/
    }
};

int main(){
	Solution soln;
	cout<<soln.rangeBitwiseAnd(2147483646,2147483647)<<endl;
}