#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> ret;
    	if(nums.size() == 0){
    		ret.push_back(-1);
    		ret.push_back(-1);
			return ret;
    	}
    	int head = 0;
    	int tail = nums.size()-1;
    	bool findhead = false;
    	bool findtail = false;
    	while(head <= tail){
    		if(findhead == false){
    			if(nums[head] == target){
	    			ret.push_back(head);
	    			findhead = true;
	    			if(findtail == true){
	    				int tmp = ret[0];
	    				ret[0] = ret[1];
	    				ret[1] = tmp;
	    				return ret;
	    			}
    			} else {
    				head++;
    			}
    		}
    		if(findtail == false){
    			if(nums[tail] == target){
	    			ret.push_back(tail);
	    			findtail = true;
	    			if(findhead == true)
	    				return ret;
    			} else {
    				tail--;
    			}
    		}	
    	}  
    	if(findtail == false || findhead == false){
    		ret.push_back(-1);
    		ret.push_back(-1);
			return ret;    		
    	} 
    }
};

int main(){
	Solution soln;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	vector<int> a = soln.searchRange(nums,2);
	cout<<a[0]<<" "<<a[1]<<endl;
}