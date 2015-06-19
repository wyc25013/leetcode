#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
    	int len = s.length();
    	int ret = 0;
    	for(int i = 0; i < len; i++){
    		char a = s[i];
    		ret += (a-64)*pow(26,len-i-1);
    	}
    	return ret;
    }
};