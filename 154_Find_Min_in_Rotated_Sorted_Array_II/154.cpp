#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len==1) return nums[0];
        int l = 0; int r = len-1;
        while(l<r){
            int m = (l+r)/2;
            if(nums[m] > nums[l]){
                if(nums[m] <= nums[r])
                    r = m;
                else
                    l = m;
            }else if(nums[m] < nums[l]){
                r = m;
            }else{
                if(r-l==1)
                  return min(nums[l],nums[r]);
                else{
                    if(nums[m] < nums[r])
                        r = m;
                    else if(nums[m] > nums[r])
                        l = m;
                    else
                        l++;
                }
            }
        }
    }
};

int main(){
	int a[] = {6,6,6,6,6,6,6,6,6,0,0,1,2,3,4,5};
	vector<int> b(a,a+16);
	Solution soln;
	cout<<soln.findMin(b)<<endl;
}