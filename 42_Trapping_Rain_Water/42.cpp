#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int len = height.size();
		if(len <= 2) return 0;
		int ret = 0; int tstart = 0;
		for(int i = 0; i < len-1; i++){
			if(height[i+1] >= height[i])
				tstart++;
			else break;
		}
		if(tstart==len-2) return 0;

		stack<int> a; a.push(height[tstart]);
		for(int i = tstart+1; i < len; i++){
			int t = a.top();
			if(height[tstart] > height[i])
				a.push(height[i]);
			else{
				while(!a.empty()){
					ret += height[tstart]-a.top();
					a.pop();
				}
				tstart = i;
				a.push(height[tstart]);
			}
		}
		int e = a.top(); a.pop();
		while(e != height[tstart]){
		    while(!a.empty() && e <= a.top()){
		        e = a.top();
			    a.pop();
		    }
		    if(!a.empty()){
		        ret += e-a.top();
		        a.pop();
		    }
		}
		return ret;
    }
};

int main(){
	int a[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
	Solution soln;
	vector<int> b(a,a+26);
	cout<<soln.trap(b)<<endl;
}