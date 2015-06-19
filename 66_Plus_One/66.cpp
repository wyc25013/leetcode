#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int len = digits.size();
		int i = len-1;
		while(digits[i] == 9 && i >= 0) {
			digits[i] = 0;
			i--;
		}      
		if(i >= 0)
			(digits[i])++;
		else{
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
    }
};