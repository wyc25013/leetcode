#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		if(!row) return 0;
		dp.push_back(triangle[0]);
		for(int i = 2; i <= row; i++)
			helper(i,triangle);
		vector<int> a = triangle[row-1];
		sort(a.begin(),a.end());
		return a[0];       
    }

    void helper(int level, vector<vector<int> >& triangle){
    	vector<int> a = triangle[level-2];
    	triangle[level-1][0] += triangle[level-2][0];
    	triangle[level-1][level-1] += triangle[level-2][level-2];
    	for(int i = 1; i < level-1; i++)
    		triangle[level-1][i] += triangle[level-2][i-1] > triangle[level-2][i] ? triangle[level-2][i] : triangle[level-2][i-1];
    }
};