#include <iostream>
#include <vector>
using namespace std;
/* backtracing solution --too slow
class Solution {
public:
    int uniquePaths(int m, int n) {
		int cnt_right = 0;
		int cnt_down = 0;
		int ret = 0;
		helper(0,0,m,n,ret);
		return ret;        
    }

    void helper(int cnt_right, int cnt_down, int m, int n, int& ret){
    	if(cnt_right+cnt_down < m+n-2){
    		if(cnt_right < m-1){
	    		helper(cnt_right+1,cnt_down,m,n,ret);
	    	}
	    	if(cnt_down < n-1){
	    		helper(cnt_right,cnt_down+1,m,n,ret);
	    	}
    	} else {
    		ret++;
    	}
    }
};
*/
//DP solution
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int> > a;
		for(int i = 0; i < n; i++){
			vector<int> tmp(m,0);
			a.push_back(tmp);
		} 

		a[0][0] = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i != 0)
					a[i][j] += a[i-1][j];
				if(j != 0)
					a[i][j] += a[i][j-1];
			}
		}

		return a[n-1][m-1];
	}
};
int main(){
	Solution soln;
	cout<<soln.uniquePaths(23,12)<<endl;
}