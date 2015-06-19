#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int len = nums.size();
		int pivot = nums[len-1];
		if(pivot > target){
			for(int i = len-1; ; i--){
				if(nums[i] == target)
					return i;
				else if(nums[i] > target){

				}else{
					return -1;
				}
				
				if(nums[i-1] > nums[i])
				    break;
			}
			return -1;
		} else if(pivot < target){
			for(int i = 0; ;i++){
				if(nums[i] == target)
					return i;
				else if(nums[i] < target){

				}else{
					return -1;
				}
				
				if(nums[i+1] < nums[i])
				    break;
			}
			return -1;
		} else
			return len-1;  
    }
};

//bad solution, binary search uses only logN