#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    	// d&c solution 
    	// Using segment tree will improve finding minimal
    	/*
        int len = height.size();
        if(!len) return 0;
        int pos = findmin(height,0,len-1);
        return max(height[pos]*len,max(helper(0,pos-1,height),helper(pos+1,len-1,height)));
        */

        // stack solution
        stack<int> a;
        int i = 0; int max = 0;
        while(i<height.size()){
        	if(a.empty() || height[i] >= height[a.top()])
        		a.push(i++);
        	else{
        		int tp = a.top(); a.pop();
        		int area = height[tp]*(a.empty()?i:i-a.top()-1);
        		if(area>max) max = area;
        	}
        }
        while(!a.empty()){
        	int tp = a.top(); a.pop();
        	int area = height[tp]*(a.empty()?i:i-a.top()-1);
        	if(area > max) max = area;
        }
        return max;
    }

    int findmin(vector<int>& height, int start, int end){
    	int min = INT_MAX; int ret = start;
    	for(int i = start; i<= end; i++){
    		if(height[i] < min){
    			min = height[i];
    			ret = i;
    		}
    	}
    	return ret;
    }

    int helper(int start, int end, vector<int>& height){
    	if(start > end) return 0;
    	if(start==end) return height[start];
    	int pos = findmin(height,start,end);
    	return max(height[pos]*(end-start+1),max(helper(start,pos-1,height),helper(pos+1,end,height)));
    }
};

int main(){
	int a[] = {2,1,5,6,2,3};
	vector<int> b(a,a+6);
	Solution soln;
	cout<<soln.largestRectangleArea(b)<<endl;
}