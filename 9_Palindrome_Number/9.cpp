#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
        /*
        stringstream ss;
		ss<<x;
		string str;
		ss>>str;

		int len = str.length();

		for (int i = 0; i < len/2; i++) {
			if (str[i] != str[len-i-1])
				return false;
		}
		return true;
		*/
		
		int tail;
		int result;
		int tmp = x;
		while(tmp) {
		    tail = tmp % 10;
		    result = result*10 + tail;
		    tmp/= 10;
		}
		return (result == x ? true : false);
		
	}
}