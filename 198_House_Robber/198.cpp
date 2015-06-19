#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		int len = nums.size();
		if(!len) return 0;
		if(len==1) return nums[0];
		if(len==2) return max(nums[0],nums[1]);
		if(len==3) return max(nums[0]+nums[2],nums[1]);
		vector<int> a(len,0);
		a[0] = nums[0]; a[1] = nums[1]; a[2] = nums[2]+a[0];
		for(int i = 3; i < len; i++){
			a[i] = nums[i] + max(a[i-2],a[i-3]);
		}
		return max(a[len-1],a[len-2]);
    }
};