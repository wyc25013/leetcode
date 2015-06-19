#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(),num.end());
		int len = num.size();
		int diff = abs(num[0]+num[1]+num[len-1]-target);
		int result = abs(num[0]+num[1]+num[len-1]-target);

		for (int i = 0; i < len-2; ++i)
		{
			int j = i + 1;
			int k = len - 1;

			while(j < k){
				int sum = num[i]+num[j]+num[k];
				
				if(sum == target){
					return sum;
				}
				else if(sum > target){
					if(sum - target > diff){
						k--;
					}
					else{
						diff = sum - target;
						result = sum;
						k--;
					}
				}
				else{
					if(target - sum > diff){
						j++;
					}
					else{
						diff = target - sum;
						result = sum;
						j++;
					}
				}
			}
		}        
		return result;
    }
};

int main(){
	Solution soln;
	int a[4] = {-1,2,1,4};
	std::vector<int> v (a,a+sizeof(a)/sizeof(int));
	cout << soln.threeSumClosest(v,1)<<endl;
	return 0;
}