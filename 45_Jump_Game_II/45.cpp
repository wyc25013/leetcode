#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		int size = nums.size();
		if(size == 1)
		    return 0;
		int stdpt = 0;
		int max = 0;
		int steps = 0;
		while(stdpt < size-1 && stdpt+nums[stdpt] < size-1){
		    int range = stdpt+nums[stdpt];
			for(int i = stdpt+1; i <= range;i++){
			    if(i+nums[i] > max){
			        stdpt = i;
			        max = i+nums[i];
			    }
			}
			steps++;
		}
		return steps+1;
    }
};

int main(){
	Solution soln;
	int aa[] = {5,8,1,8,9,8,7,1,7,5,8,6,5,4,7,3,9,9,0,6,6,3,4,8,0,5,8,9,5,3,7,2,1,8,2,3,8,9,4,7,6,2,5,2,8,2,7,9,3,7,6,9,2,0,8,2,7,8,4,4,1,1,6,4,1,0,7,2,0,3,9,8,7,7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,4,1,0,7,2,0,3,9,8,7,7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,0};
	vector<int> a(aa,aa+sizeof(aa)/sizeof(int));
//	vector<int> a;
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(4);

	cout<<soln.jump(a)<<endl;
}