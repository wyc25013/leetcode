#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// solve with stack solution of "max rect in hist" problem
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
    	int row = matrix.size();
    	if(!row) return 0;
    	int col = matrix[0].size();
    	if(!col) return 0;
    		
    	int max = 0; vector<int> height(col,0);
    	for(int i = 0; i < row; i++){
    		for(int j = 0; j < col; j++){
    			if(matrix[i][j]=='0')
    				height[j]=0;
    			else
    				height[j]++;
    		}
    		int ret = largestRectangleArea(height);
    		if(ret > max) max = ret;
    	}
    	return max;
    }

    int largestRectangleArea(vector<int>& height) {
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
};

int main(){
	vector<vector<char> > a(1,vector<char>(1,'1'));
	Solution soln;
	cout<<soln.maximalRectangle(a)<<endl;
}