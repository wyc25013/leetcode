#include <unordered_set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.length();
		if(!len) return true;
		vector<bool> map(len*len,false);
		for(int i = 0; i < len; i++){
			for(int j = 0; j <= i; j++){	//j->i
				string ss = s.substr(j,i-j+1);
				if(wordDict.find(ss) != wordDict.end())
					map[j*len+i] = true;
			}
		}

		for(int i = 0; i < len; i++){
			for(int j = 0; j < i; j++){
				if(map[i]){}
				else
					if(map[j] && map[(j+1)*len+i])
						map[i] = true;
			}
		}

		return map[len-1];



    }

  
};

int main(){
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> dict;
	dict.insert("aaaaaaaaaaaaa");
	dict.insert("a");
	dict.insert("aaaaaa");
	Solution soln;
	cout<<soln.wordBreak(s,dict)<<endl;
}