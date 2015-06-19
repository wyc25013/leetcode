#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size()){
            int ret = 0;
            for(int i = 1; i < prices.size();i++){
                if(prices[i] > prices[i-1])
                    ret += prices[i]-prices[i-1];
            }
            return ret;
        }
		vector<int> sell(k+1,0);
		vector<int> buy(k+1,INT_MIN);
		for(int i = 0; i < prices.size(); i++){
			for(int j = k; j >= 1; j--){
				sell[j] = max(sell[j],buy[j]+prices[i]);
				buy[j] = max(buy[j],sell[j-1]-prices[i]);
			}
		}        
		return sell[k];
    }
};

int main(){
	int a[] = {1,2};
	vector<int> b(a,a+2);
	Solution soln;
	cout<<soln.maxProfit(1,b)<<endl;
}