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
				max = prices[i];
				ret = ret > max - min ? ret : max - min;
			} else if(prices[i] <= min){
				min = prices[i];
				max = prices[i];
			} else if(prices[i] > min && prices[i] <= max){

			}
		}
		return ret;
    }
};