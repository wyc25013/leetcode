#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
		int row = matrix.size();
		if(!row) return 0;
		int col = matrix[0].size();
		if(!col) return 0;

		int max = 0;

		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(matrix[i][j] == '1'){
					int cnt = 1;
					int si = i+1; int sj = j+1;
					while(si < row && sj < col && matrix[si][sj]=='1'){
						bool co = true; bool ro = true;
						for(int k = si-1; k >= i; k--){
							if(matrix[k][sj] == '0'){
								co = false;
								break;
							}
						}
						if(co){
							for(int l = sj-1; l >= j; l--){
								if(matrix[si][l] == '0'){
									ro = false;
									break;
								}
							}	
						}
						if(co && ro){
							si++;sj++;
							cnt++;
						} else break;
					}
		
					if(cnt > max) max = cnt;
				}
			}
		}        
		return max*max;

		/* better dp solution
		if(matrix.empty() || matrix[0].empty()) return 0;
	    int maxSize = 0;        
	    vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
	    for(int r = 0 ; r < m.size() ; ++r) {
	        for(int c = 0 ; c < m[0].size() ; ++c) {
	            m[r][c] = matrix[r][c]-'0';
	            if(r > 0 && c > 0 && m[r][c] == 1) {
	                m[r][c] += min(m[r-1][c], min(m[r][c-1], m[r-1][c-1]));
	            }
	            maxSize = max(maxSize, m[r][c]);
	        }
	    }
	    return maxSize*maxSize;
	    */
    }
};

int main(){
	char a1[] = {'1','0','1','0','0'}; 
	char a2[] = {'1','0','1','1','1'}; 
	char a3[] = {'1','1','1','1','1'}; 
	char a4[] = {'1','0','0','1','0'}; 

	vector<vector<char> > a;
	a.push_back(vector<char>(a1,a1+5));
	a.push_back(vector<char>(a2,a2+5));
	a.push_back(vector<char>(a3,a3+5));
	a.push_back(vector<char>(a4,a4+5));

	Solution soln;
	cout<<soln.maximalSquare(a)<<endl;
}