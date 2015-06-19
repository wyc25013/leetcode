#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> a;
		int len = nums.size();
		if(len <= 1) return false;
		for(int i = 0; i < len; i++){
			if(a.find(nums[i]) == a.end())
				a.insert(nums[i]);
			else
				return true;
		}         
		return false;
    }
};