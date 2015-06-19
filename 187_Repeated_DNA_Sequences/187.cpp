#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		int len = s.length();
		unordered_set<string> ret;
		vector<string> rett;
		if(len <= 10) return rett;
		unordered_set<int> vi;
		for(int i = 0; i < len-9; i++){
			int fb = 0;
			for(int j = i; j < i+10; j++){
				if(s[j] == 'T') fb += 1;
				else if(s[j] == 'C') fb += 2;
				else if(s[j] == 'G') fb += 3;
				fb <<= 2;
			}
			if(vi.find(fb) != vi.end()){
			    string ss = s.substr(i,10);
			    if(ret.find(ss) == ret.end())
			        ret.insert(ss);
			}else
				vi.insert(fb);
		}  
		for(unordered_set<string>::iterator it = ret.begin(); it != ret.end();it++)
		    rett.push_back(*it);
		return rett;
    }
};