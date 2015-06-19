#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
		int len = nums.size();
		if(!len) return 0;
		if(len==1) return nums[0];
		if(len==2) return max(nums[0],nums[1]);
		if(len==3) return max(nums[0],max(nums[1],nums[2]));
		vector<int> a(len,0); 
		vector<int> b(len-1,0);
		a[0] = nums[0]; a[1] = nums[1]; a[2] = nums[0]+nums[2];
		b[0] = nums[1]; b[1] = nums[2]; b[2] = nums[1]+nums[3];
		for(int i = 3; i < len-1; i++)
			a[i] = nums[i] + max(a[i-2],a[i-3]);
		for(int i = 3; i < len-1; i++)
			b[i] = nums[i+1]+max(b[i-2],b[i-3]);
		
		return max(max(a[len-3],a[len-2]),max(b[len-3],b[len-2]));
    }
};