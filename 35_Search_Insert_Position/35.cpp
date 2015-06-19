#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int len = nums.size();
    	if(!len)
    		return 0;
    	int head = 0;
    	int tail = len-1;
    	if(target > nums[tail])
    		return tail+1;
    	else if(target < nums[head])
    		return 0;
		while(head < tail){
			int mid = (head+tail)/2;
			if(nums[mid] > target){
				if(tail - head == 1){
					return head;
				}
				tail = mid;
			} else if (nums[mid] < target){
				if(tail - head == 1){
					return tail;
				}
				head = mid;
			} else {
				return mid;
			}
		}        
    }
};

int main(){
	Solution soln;
	vector<int> a;
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(7);

	int b = soln.searchInsert(a,2);
	int c = soln.searchInsert(a,6);
	int d = soln.searchInsert(a,4);

	cout << b << c << d <<endl;
}