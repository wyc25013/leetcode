#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
    	if(!len) return 0;
		int min = prices[0];
		int max = prices[0];
		int ret = max - min;
		if(len==1) return 0;

		for(int i = 1; i < len; i++){
			if(prices[i] > max){
				ret += prices[i]-max;
				max = prices[i];
			} else {
				min = prices[i];
				max = prices[i];
			} 
		}
		return ret;
    }
};