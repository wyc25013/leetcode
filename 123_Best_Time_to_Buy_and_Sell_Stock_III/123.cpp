#include <iostream>
#include <vector>
using namespace std;

//based on part I, just break it into two part
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if(len < 2) return 0;
		int max = 0;
		int ret = 0;
		for(int i = 0; i < len; i++){
			if(prices[i] - prices[i-1] > 0){
				max = maxProfitPart(prices,0,i)+maxProfitPart(prices,i+1,len-1);
				if(max > ret) ret = max;
			}
		}
	//	int one = maxProfitPart(prices,0,len-1);
		return ret > one ? ret : one;
    }

    int maxProfitPart(vector<int>& prices, int start, int end) {
    	int len = end - start + 1;
    	if(len < 2) return 0;
		int min = prices[start];
		int max = prices[start];
		int ret = max - min;

		for(int i = start+1; i <= end; i++){
			if(prices[i] > max){
				max = prices[i];
				ret = ret > max - min ? ret : max - min;
			} else if(prices[i] <= min){
				min = prices[i];
				max = prices[i];
			}
		}
		return ret;
    }
};

/* faster solution with dp
 *
class Solution {
public:
	 int maxProfit(vector<int>& prices) {
	 	int len = prices.size();
        if(len< 2) return 0;

        int TIME = 2;
        vector<int> sell(TIME+1,0);
        vector<int> buy(TIME+1,INT_MIN);
        
        for(int i = 0; i < len; i++){
            for(int j = TIME; j > 0; j--){
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }
        return sell[TIME];
    }
};
*/