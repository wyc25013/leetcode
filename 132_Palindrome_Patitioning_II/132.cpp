#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
    	int len = s.length();
    	vector<int> map(len*len, 0xffff);
		for(int i = 0; i < len; i++){
			for(int j = 0; j <= i; j++){	// j = startpoint; i = endpoint
				if(s[i] == s[j]){
					map[j*len+i] = (j+1 > i-1) ? 0 : map[(j+1)*len+i-1];
				}
			}
		}	

		for(int i = 1; i < len; i++){
			for(int j = 0; j < i; j++){
				map[i] = min(map[i], 1+map[j]+map[(j+1)*len+i]);
			}
		}
		return map[len-1];
    }

};

int main(){
	string s = "aaabbaaaaaa";
	Solution soln;
	cout<<soln.minCut(s)<<endl;
}