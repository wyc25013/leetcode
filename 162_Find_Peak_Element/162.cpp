#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	/* o(n)
		int len = nums.size();
		if(len == 1) return 0;
		int a = nums[0];
		for(int i = 1; i < len; i++){
			if(nums[i] > a) a= nums[i];
			else return i-1;
		}
		return len-1;
		*/

		//o(logn)
		int len = nums.size();
		if(len==1) return 0;
		int l = 0; int r = len-1;
		while(l < r){
			if(nums[l+1] < nums[l]) return l;
			else l++;
			if(nums[r-1] < nums[r]) return r;
			else r--;
		}
		return l;
    }
};