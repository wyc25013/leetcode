#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
		int len = nums.size();
		int left = 0;
		int right = len-1;
		while(left < right){
			int mid = (left+right)/2;
			if(nums[mid] == target)
				return true;

			if(nums[mid] > nums[right]){
				if(nums[mid] > target && nums[left] <= target) 
					right = mid;
				else
					left = mid+1;
			}else if(nums[mid] < nums[right]){
				if(nums[mid] < target && nums[right] >= target)
					left = mid+1;
				else
					right = mid;
			}else{
				right--;
			}
		}		        
		return (nums[left]==target); 
    }
};