#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	/* try to use dp to solve but MLE
		int len = nums.size();
		vector<vector<int> > a(len,vector<int>(len,0));
		for(int i = 0; i < len; i++){
			for(int j = 0; j < len-i; j++){
				if(i==0) a[j][j+i] = nums[j];
				else a[j][j+i] = a[j][j+i-1]+a[j+i][j+i];
				if(a[j][j+i] == s) return i+1;
			}
		}        
		return 0;
		*/
		/* o(n^2) solution
		int len = nums.size();
		int l = 0; int min = INT_MAX;
		while(l < len){
		    int sum = 0; int r = l;
		    while(r < len){
		        if(r-l+1 >= min) break;
		        sum += nums[r];
		        if(sum >= s) {
		            min = min > r-l+1 ? r-l+1 : min;
		            break;
		        }
		        r++;
		    }
		    l++;
		}
		if(min==INT_MAX) return 0;
		else return min;
		*/

		//o(n) solution
		int len = nums.size();
		int l = 0; int r = 0; int min = INT_MAX; int sum = 0;
		while(r < len || sum >= s){
			if(sum < s){
				sum += nums[r];
				r++;
			}
			if(sum >= s && l <= r){
				min = min > r-l ? r-l : min;
				sum -= nums[l];
				l++;
			}
		}
		return min == INT_MAX ? 0 : min;

		//o(nlogn) solution uses sum is a sorted array then do binary search
	}

};

int main(){
	int a[] = {1,4,4};
	vector<int> b(a,a+3);
	Solution soln;
	cout<<soln.minSubArrayLen(4,b)<<endl;
}