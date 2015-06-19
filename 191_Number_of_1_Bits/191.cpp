#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ret = 0;
		for(int i = 0; i < 32; i++){
			uint32_t test = (long long)pow(2,i);        
			if((test|n)==n) ret++;
		}
		return ret;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ret = 0;
		for(int i = 31; i >= 0; i--){
		    uint32_t t = (long long)pow(2,i);
			ret += n/t;
			n %= t;
		}
		return ret;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ret = 0;
		for(int i = 0; i < 32; i++){
			ret += n%2;
			n >>= 1;
		}
		return ret;
    }
};