#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		unordered_map<int,int> nummap;
		int len = nums.size();
		if(len <= 2)
			return len;
		int count = 0;
		int change_pos = 0;
		for(int i = 0; i < len; i++){
			if(nummap.find(nums[i]) == nummap.end()){
				nummap.insert(pair<int,int>(nums[i],1));
				count++;
				if(change_pos != i)
					nums[change_pos] = nums[i];
				change_pos++;
			}else{
				if(nummap[nums[i]] == 1){
					(nummap[nums[i]])++;
					count++;
					if(change_pos != i)
						nums[change_pos] = nums[i];
					change_pos++;
				}
			}
		}  
		return count;
    }
};

int main(){
	int a[5] = {1,1,1,2,3};
	vector<int> b(a,a+5);
	Solution soln;
	int len = soln.removeDuplicates(b);
	int i = 0;
	while(i<len){
		cout<<b[i]<<" ";
		i++;
	}
	cout<<endl;
}