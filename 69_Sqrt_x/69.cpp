#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if(x == 0 || x == 1)
    		return x;
    	int left = 1;
    	int right = x;
		int mid = (1+x)/2;
		while(1){
			if(x/mid > mid){
			    if(x/mid - mid == 1)
			        return mid;
				left = mid;
				mid = (left+right)/2;
			} 
			else if(x/mid < mid){
			    if(mid - x/mid == 1)
			        return x/mid;
				right = mid;
				mid = (left+right)/2;
			} 
			else
				return mid;
		}        
    }
};

int main(){
	Solution soln;
	cout<<soln.mySqrt(9)<<" "<<soln.mySqrt(256)<<endl;
}