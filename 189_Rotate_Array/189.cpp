#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if(len<=1) return;
		k %= len;
		if(!k) return;
		vector<int> tmp;
		for(int i = len-k; i < len; i++)
			tmp.push_back(nums[i]);
		for(int i = len-k-1; i >= 0; i--)
			nums[i+k] = nums[i];
		for(int i = 0; i < k; i++)
			nums[i] = tmp[i];
    }
};

/* reverse solution
public void rotate(int[] nums, int k) {
    k %= nums.length;
    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);
}

public void reverse(int[] nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
*/