#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
//#include <algorithm>
using namespace std;

class Solution {
public:
	int reverse1(int x) {
		bool sign;
		if(x > 0)
			sign = 1;
		else
			sign = 0;
		unsigned int x1 = abs(x);
		stringstream ss1,ss2;
		ss1<<x1;
		string t;
		ss1>>t;
		int len = t.length();

		for(int i = 0; i < len/2; i++){
			char tmp = t[i];
			t[i] = t[len-i-1];
			t[len-i-1] = tmp;
		}
			
		long y;
		ss2<<t;
		ss2>>y;

		if(y > INT_MAX)
			return 0;
		if(sign)
			return y;
		else
			return y*(-1);
	}
};

int main(){
	Solution soln;
	cout<<soln.reverse1(9876543210)<<endl;
	cout<<soln.reverse1(1)<<endl;
	return 0;
}
//15ms c++ solution by others
//no transverse to string
/*
class Solution {
public:
    int reverse(int x) {
        long num = abs((long)x);
        long new_num = 0;
        while(num) {
            new_num = new_num*10 + num%10;
            num /= 10;
        }

        if (new_num > INT_MAX) {
            return 0;
        }
        return (x<0 ? -1*new_num : new_num);
    }
};
*/