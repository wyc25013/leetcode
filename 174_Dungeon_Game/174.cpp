#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
		int row = dungeon.size();
		int col = dungeon[0].size();
		// do it in place & backtrack from bottom-right to top-left
		dungeon[row-1][col-1] = dungeon[row-1][col-1] > 0 ? 0 : dungeon[row-1][col-1];
		for(int i = row-2; i >= 0; i--){
			dungeon[i][col-1] = dungeon[i+1][col-1]+dungeon[i][col-1];
			dungeon[i][col-1] = dungeon[i][col-1] > 0 ? 0 : dungeon[i][col-1];
		}	
		for(int i = col-2; i >= 0; i--){
			dungeon[row-1][i] = dungeon[row-1][i+1]+dungeon[row-1][i];
			dungeon[row-1][i] = dungeon[row-1][i] > 0 ? 0 : dungeon[row-1][i];
		}	
		for(int i = row-2; i >=0;i--){
			for(int j = col-2; j >=0;j--){
				dungeon[i][j] = max(dungeon[i+1][j],dungeon[i][j+1])+dungeon[i][j];
				dungeon[i][j] = dungeon[i][j] > 0 ? 0 : dungeon[i][j];
			}
		}
		return -dungeon[0][0]+1;
    }
};

int main(){
	int a1[]={-2,-3,3};
	int a2[]={-5,-10,1};
	int a3[]={10,30,-5};
	vector<vector<int> > dg;
	dg.push_back(vector<int>(a1,a1+3));
	dg.push_back(vector<int>(a2,a2+3));
	dg.push_back(vector<int>(a3,a3+3));
	Solution soln;
	cout<<soln.calculateMinimumHP(dg)<<endl;
}