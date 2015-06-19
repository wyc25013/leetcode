#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        vector<vector<bool> > visited;
        int row = board.size(); if(!row) return;
        int col = board[0].size();
        if(row < 3 || col < 3) return;
        for(int i = 0; i < row; i++){
        	vector<bool> tmp(col,false);
        	visited.push_back(tmp);
        }

        for(int i = 0; i < row; i++){
        	for(int j = 0; j < col; j++){
        		if(visited[i][j]) continue;
                
                visited[i][j] = true;
        		if(board[i][j] == 'O'){
        			queue<int> coor;
        			queue<int> toflip;
        			bool ifflip = true;
        			coor.push(i*col+j);
        			while(coor.size()){
        				int xy = coor.front();
        				toflip.push(xy);
        				int x = xy / col;
        				int y = xy % col;
        				if(board[x][y] == 'O')
        					explore(x,y,col,row,coor,ifflip,visited);
        				coor.pop();
        			}
        			if(ifflip)
        				flip(toflip,board,col);
        		}
        	}
        }
    }

    void explore(int x, int y, int col,int row,queue<int>& bfs,bool& ifflip,vector<vector<bool> >& visited){
		if(x >= 1){
			if(visited[x-1][y] == false){
				bfs.push((x-1)*col+y);
				visited[x-1][y] = true;
			}
		}else
			ifflip = false;

	    if(x <= row-2){
	    	if(visited[x+1][y] == false){
	    		bfs.push((x+1)*col+y);
	    		visited[x+1][y] = true;
	    	}
	    }else
	    	ifflip = false;

		if(y >= 1){
			if(visited[x][y-1] == false){
				bfs.push(x*col+y-1);
				visited[x][y-1] = true;
			}
		}else
			ifflip = false;

		if(y <= col-2){
			if(visited[x][y+1] == false){
				bfs.push(x*col+y+1);
				visited[x][y+1] = true;
			}
		}else
			ifflip = false;
    }

    void flip(queue<int>& toflip, vector<vector<char> >& board, int col){
    	while(toflip.size()){
    		int x = toflip.front() / col;
    		int y = toflip.front() % col;
    		board[x][y] = 'X';
    		toflip.pop();
    	}
    }
};

/* go from boundary
 * better solution
class Solution {
   public:
    void solve(vector<vector<char> > &board){
        int height = board.size();
        if(0 == height) return;
        int width = board[0].size();
        int num = width*height;
        bool visited[num];
        for(int i=0; i<num; i++)
            visited[i] = false;
        queue<int> q;

         // push boarder
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if((i==0 || j==0 || i==height-1 || j==width-1)
                        && board[i][j] == 'O'){
                    int idx = width*i+j;
                    q.push(idx);
                    visited[idx] = true;
                }
            }
        }
        while(!q.empty()){
            int current = q.front();
            q.pop();

            int row = current / width;
            int col = current % width;
            // cout<<"("<<row<<","<<col<<")"<<endl;
            int idx = -1;
            //left
            idx = width*row + col -1;
            if(col-1 >= 0 && board[row][col-1] == 'O' && !visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
            //right
            idx = width*row + col +1;
            if(col+1 <=width-1 && board[row][col+1] == 'O' && !visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
            //up
            idx = width*(row-1) + col;
            if(row-1 >= 0 && board[row-1][col] == 'O' && !visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
            //down
            idx = width*(row+1) + col;
            if(row+1 <=height-1 && board[row+1][col] == 'O' && !visited[idx]){
                q.push(idx);
                visited[idx] = true;
            }
        }

        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                int idx = width*i+j;
                if(board[i][j] == 'O' && !visited[idx])
                    board[i][j] = 'X';
            }
        }
    }
}
*/

int main(){
	char a[] = {'O','O','O'};
	char b[] = {'O','O','O'};
	char c[] = {'O','O','O'};
//	char d[] = {'X','O','X','X'};
	vector<char> one(a,a+3);
	vector<char> two(b,b+3);
	vector<char> three(c,c+3);
//	vector<char> four(d,d+4);

	vector<vector<char> > board;
	board.push_back(one);
	board.push_back(two);
	board.push_back(three);
//	board.push_back(four);

	Solution soln;
	soln.solve(board);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}