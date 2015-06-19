#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
    	vector<vector<bool> > rowhs(9,vector<bool>(9,true)); 
    	vector<vector<bool> > colhs(9,vector<bool>(9,true)); 
    	vector<vector<bool> > sqrhs(9,vector<bool>(9,true)); 
		
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(board[i][j]=='.') continue;
				char er = board[i][j];
				rowhs[i][er-49] = false;
				colhs[j][er-49] = false;
				sqrhs[(i/3)*3+(j/3)][er-49] = false;
			}
		}			        

		int si,sj;
		for(int i = 0; i < 9; i++){
			bool ifbreak = false;
			for(int j = 0; j < 9; j++){
				if(board[i][j] == '.'){
					si = i; sj = j;
					ifbreak = true;
					break;
				}
			}
			if(ifbreak) break;
		}

		bool ret = false;
		for(char k = '1'; k <= '9'; k++){
			if(rowhs[si][k-49] && colhs[sj][k-49]
			&& sqrhs[(si/3)*3+(sj/3)][k-49])
			{
				board[si][sj] = k;
				rowhs[si][k-49]=false;
				colhs[sj][k-49]=false;
				sqrhs[(si/3)*3+(sj/3)][k-49]=false;
				helper(si,sj+1,ret,board,rowhs,colhs,sqrhs);
				if(ret) return;
				rowhs[si][k-49]=true;
				colhs[sj][k-49]=true;
				sqrhs[(si/3)*3+(sj/3)][k-49]=true;
			}
		}
    }

    void helper(int si, int sj, bool& ret, vector<vector<char> >& board,
    			vector<vector<bool> >& rowhs,
    			vector<vector<bool> >& colhs,
    			vector<vector<bool> >& sqrhs)
    {
    	if(si==9) {
    		for(int i = 0; i < 9; i++){
    		    for(int j = 0; j < 9; j++){
    		        if(!rowhs[i][j]&&!colhs[i][j]&&!sqrhs[i][j]){}
    			    else return;
    		    }
    		}
    		ret = true;
    		return;
    	}
    	if(sj==9){
    		helper(si+1,0,ret,board,rowhs,colhs,sqrhs);
 			return;
    	}
    	if(board[si][sj]!='.'){
    		helper(si,sj+1,ret,board,rowhs,colhs,sqrhs);
    		return;
    	}
    	for(char k = '1'; k <= '9'; k++){
			if(rowhs[si][k-49] && colhs[sj][k-49]
			&& sqrhs[(si/3)*3+(sj/3)][k-49])
			{
				board[si][sj] = k;
				rowhs[si][k-49]=false;
				colhs[sj][k-49]=false;
				sqrhs[(si/3)*3+(sj/3)][k-49]=false;
				helper(si,sj+1,ret,board,rowhs,colhs,sqrhs);
				if(ret) return;
				board[si][sj] = '.';
				rowhs[si][k-49]=true;
				colhs[sj][k-49]=true;
				sqrhs[(si/3)*3+(sj/3)][k-49]=true;
			}
		}
    }
};

int main(){
	char a1[]={'.','.','9','7','4','8','.','.','.'};
	char a2[]={'7','.','.','.','.','.','.','.','.'};
	char a3[]={'.','2','.','1','.','9','.','.','.'};
	char a4[]={'.','.','7','.','.','.','2','4','.'};
	char a5[]={'.','6','4','.','1','.','5','9','.'};
	char a6[]={'.','9','8','.','.','.','3','.','.'};
	char a7[]={'.','.','.','8','.','3','.','2','.'};
	char a8[]={'.','.','.','.','.','.','.','.','6'};
	char a9[]={'.','.','.','2','7','5','9','.','.'};
	vector<vector<char> > a;
	a.push_back(vector<char>(a1,a1+9));
	a.push_back(vector<char>(a2,a2+9));
	a.push_back(vector<char>(a3,a3+9));
	a.push_back(vector<char>(a4,a4+9));
	a.push_back(vector<char>(a5,a5+9));
	a.push_back(vector<char>(a6,a6+9));
	a.push_back(vector<char>(a7,a7+9));
	a.push_back(vector<char>(a8,a8+9));
	a.push_back(vector<char>(a9,a9+9));
	Solution soln;
	soln.solveSudoku(a);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}