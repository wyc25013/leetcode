#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        int size = nums.size();
		for(int i = 0; i <= max_pos; i++){
		    if(i+nums[i] > max_pos){
		        if(i+nums[i] >= size-1)
		            return true;
		        else
		            max_pos = i+nums[i];
		    }
		}    
		return (max_pos >= size-1);
    }
};  

int main(){
	Solution soln;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	cout<<soln.canJump(nums)<<endl;
}