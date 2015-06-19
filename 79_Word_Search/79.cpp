#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
		int row = board.size();
		int col = board[0].size();
		vector<vector<bool> > map;
		for(int i = 0; i < row; i++){
			vector<bool> tmp(col,false);
			map.push_back(tmp);
		}
		bool ret = false;
		char first = word[0];
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(board[i][j] == first){
					map[i][j] = true;
					helper(1,ret,board,word,map,i,j);
					if(ret)
						break;
					map[i][j] = false;
				}
			}
			if(ret)
				break;
		}
		return ret;
	}
	void helper(int pos, bool& ret,vector<vector<char> >& board, string& word, vector<vector<bool> >& map,int i, int j){
		if(pos == word.length()){
			ret = true;
			return;
		} else {
			int row = board.size();
			int col = board[0].size();
			char target = word[pos];
			if(i < row-1 && board[i+1][j] == target && map[i+1][j] == false){
				map[i+1][j] = true;
				helper(pos+1,ret,board,word,map,i+1,j);
				if(ret)
					return;
				map[i+1][j] = false;
			}
			if(i > 0 && board[i-1][j] == target && map[i-1][j] == false){
				map[i-1][j] = true;
				helper(pos+1,ret,board,word,map,i-1,j);
				if(ret)
					return;
				map[i-1][j] = false;
			}
			if(j < col-1 && board[i][j+1] == target && map[i][j+1] == false){
				map[i][j+1] = true;
				helper(pos+1,ret,board,word,map,i,j+1);
				if(ret)
					return;
				map[i][j+1] = false;
			}
			if(j > 0 && board[i][j-1] == target && map[i][j-1] == false){
				map[i][j-1] = true;
				helper(pos+1,ret,board,word,map,i,j-1);
				if(ret)
					return;
				map[i][j-1] = false;
			}
		}
	}
    
};

int main(){
	char a[] = {'A','B','C','E'};
	char b[] = {'S','F','C','S'};
	char c[] = {'A','D','E','E'};
	vector<char> A(a,a+4);
	vector<char> B(b,b+4);
	vector<char> C(c,c+4);

	vector<vector<char> > board;
	board.push_back(A);
	board.push_back(B);
	board.push_back(C);
	Solution soln;
	cout<<soln.exist(board,"ABCCED")<<" "<<soln.exist(board,"SEE")<<" "<<soln.exist(board,"ABCB")<<endl;

}