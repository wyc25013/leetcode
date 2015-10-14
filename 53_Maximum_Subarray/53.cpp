#include <vector>
#include <iostream>
using namespace std;
/*	not a good way to go
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	vector<int> merged;
		for(int i = 0; i < nums.size();){
			int neg,pos = 0;
			if(nums[i] <= 0){
				while(nums[i] <= 0){
					neg += nums[i];
					i++;
				}
				merged.push_back(neg);
			}
			else{
				while(nums[i] > 0){
					pos += nums[i];
					i++;
				}
				merged.push_back(pos);
			}
		}

		if(merged.size() == 1){
			if(merged[0] <= 0){
				sort(nums.begin().nums.end());
				return nums[nums.size()-1];
			}
			else
				return merged[0];
		} else if (merged.size() == 2){
			return merged[0] <= 0 ? merged[1] : merged[0];
		} 

		int sum = merged[0] <= 0 ? merged[1] : merged[0];
		int max = sum; 
		int i = merged[0] <= 0 ? 1 : 0;
		for(; i < merged.size(); ){
			int left = sum;
			int mid = abs(merged[i]);
			i++;
			int right = merged[i];
			i++;

			if(left > mid && right > mid){
				sum = right + left - mid;
				if(max <= sum)
					max = sum;
			} else if(left < mid && right > left){
				sum = right;
				if(max <= sum)
					max = sum;
			} else if(left < right && right < mid){
				sum = right;
				max = left;
			} else if(right < mid && mid < left){
				sum = right + left - mid;
				max = left;
			}
		}

    }
};
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //main idea here: once sum < maxsum, then reset it to the cur num[i]
    	int sum = 0;
    	int maxsum = INT_MIN;
    	for(int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    		sum = sum >= nums[i] ? sum : nums[i];
    		if(sum >= maxsum)
    			maxsum = sum;
    	}
    	return maxsum;
    }
};