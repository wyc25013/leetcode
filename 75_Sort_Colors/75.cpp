#include <vector>
#include <iostream>
using namespace std;

//using two-pass counting sort

//using one-pass plus o(1) space
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int len = nums.size();
		if(len == 0 || len == 1)
			return;
		if(len == 2){
			if(nums[0] > nums[1])
				swap(nums[0],nums[1]);
			return;
		}
		int left = -1;
		int right = len;
		for(int i = 0; left < i && i < right; ){
			if(nums[i] == 0){
				if(i-left == 1){
					left++;
					i++;
				}
				else{
					swap(nums[i],nums[left+1]);
					left++;
				}
			}else if(nums[i] == 1){
				i++;
			}else{
				if(right == len){
					swap(nums[i],nums[len-1]);
					right = len-1;
				}
				else{
					swap(nums[i],nums[right-1]);
					right--;
				}
			}
		}		
    }

    void swap(int& a, int& b){
    	int tmp = a;
    	a = b;
    	b = tmp;
    }
};

int main(){
	int a[] = {1,1,2,0,0,1,2,0};
	vector<int> b(a,a+sizeof(a)/sizeof(int));
	Solution soln;
	soln.sortColors(b);
	for(int i = 0; i < 8; i++)
		cout<<b[i]<<" ";
	cout<<endl;
}
