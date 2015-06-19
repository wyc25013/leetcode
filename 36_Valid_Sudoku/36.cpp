#include <iostream>
#include <vector>
using namespace std;

class Solution {
	    bool isRepeat(vector<char> a){
		bool check[9] = {false};
		for(int i = 0; i < 9; i++){
			if(a[i] >= '1' && a[i] <= '9'){
				if(check[a[i] - 49])
					return true;
				else
					check[a[i] - 49] = true;
			}
		}
		return false;
	}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
		{
		    if(isRepeat(board[i]))
		        return false;
		    vector<char> b;
			for(int j = 0; j < 9; ++j)
			{
				b.push_back(board[j][i]);
			}
			if(isRepeat(b))
				return false;
		} 
		
		for(int i = 0; i < 7; i+=3){
			for(int j = 0; j < 7; j+=3){
                vector<char> v;
				v.push_back(board[i][j]);
				v.push_back(board[i][j+1]);
				v.push_back(board[i][j+2]);
				v.push_back(board[i+1][j]);
				v.push_back(board[i+1][j+1]);
				v.push_back(board[i+1][j+2]);
				v.push_back(board[i+2][j]);
				v.push_back(board[i+2][j+1]);
				v.push_back(board[i+2][j+2]);
				if(isRepeat(v))
					return false;
			}
		}
		return true;
    }
};
/* better solution
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool rawFlags[9][9]={false};
        bool colFlags[9][9]={false};
        bool sectionFlags[9][9]={false};
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                int section = (i/3)*3+j/3;
                if(rawFlags[i][num-1] || colFlags[j][num-1]|| sectionFlags[section][num-1])
                    return false;
                else {
                    rawFlags[i][num-1] = true;
                    colFlags[j][num-1] = true;
                    sectionFlags[section][num-1] = true;
                }
            }
        }
        return true;
    }
};
*/
int main(){
	vector<vector<char> > a;
	for(int i = 0; i < 9; i++){
		vector<char> b;
		for(int j = 0; j < 9; j++){
			b.push_back((char)i);
		}
		a.push_back(b);
	}
	Solution soln;
	cout<<soln.isValidSudoku(a)<<endl;
	char jj = '9';
	cout<<(int)jj<<endl;
}