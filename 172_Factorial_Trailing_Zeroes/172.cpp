#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
    	int ret = 0;
    	int i = 1;
        while(n >= pow(5,i)){ // here use >= instead of /, save lots of time
        	ret += n / pow(5,i);
        	i++;
        }
        return ret;
    }
};

int main(){
	Solution soln;
	cout<<soln.trailingZeroes(2147483647)<<endl;
}