#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        
        while(left < right) {
            if(height[left] >= height[right]){
            	int tmp = height[right];
                result = max(result,height[right]*(right-left));
                right--;
                while(height[right] <= tmp && left < right)
                    right--;
            } else {
            	int tmp = height[left];
            	result = max(result,height[left]*(right-left));
            	left++;
            	while(height[left] <= tmp && left < right)
            		left++;
            }
        }
        return result;
    }
};

int main(){
	Solution soln;
	int i[] = {1,2,3,4,5};
	vector<int> v (i,i+sizeof(i)/sizeof(int));
	cout << soln.maxArea(v) <<endl;
	return 0;
}