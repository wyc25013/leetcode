#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int,int> a;
		int len = nums.size();
		if(len <= 1) return false;
		for(int i =0 ;i < len; i++){
			if(a.find(nums[i])==a.end())
				a[nums[i]] = i;
			else{
				if(i-a[nums[i]] <= k)
					return true;
				else
					a[nums[i]] = i;
			}
		}        
		return false;
    }
};