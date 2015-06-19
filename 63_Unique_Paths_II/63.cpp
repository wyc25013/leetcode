#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
        	return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[row-1][col-1] == 1)
        	return 0;

        vector<vector<int> > a;
        for (int i = 0; i < row; ++i)
        {
        	vector<int> tmp(col,0);
        	a.push_back(tmp);
        }

        a[0][0] = 1;
        for(int i = 0; i<row; i++){
        	for(int j = 0; j < col; j++){
        		if(obstacleGrid[i][j] == 1)
        			a[i][j] = 0;
        		else {
        			if(i != 0)
        				a[i][j] += a[i-1][j];
        			if(j != 0)
        				a[i][j] += a[i][j-1];
        		}
        	}
        }

        return a[row-1][col-1];
    }
};

int main(){
	Solution soln;
	vector<vector<int> > a;
	for(int i = 0; i < 3; i++){
		vector<int> tmp(3,0);
		a.push_back(tmp);
	}
	a[1][1] = 1;
	cout<<soln.uniquePathsWithObstacles(a)<<endl;
}