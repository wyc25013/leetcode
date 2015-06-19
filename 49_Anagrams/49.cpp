#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
    	unordered_map<string, int> str_map;
    	vector<string> ret;

    	for(int i = 0; i < strs.size(); i++){
    		string mapkey;
    		mapkey = strs[i];
    		sort(mapkey.begin(),mapkey.end());
    		
    		if(str_map.find(mapkey) == str_map.end()){
    			str_map.insert(pair<string,int>(mapkey,i));
    		}else{
    		    if(str_map[mapkey] == -1){	// -1 means the first one has been pushed
    		        ret.push_back(strs[i]);
    		    } else {					// if not -1, then push the val to ret vector and set val to -1
    		        ret.push_back(strs[str_map[mapkey]]);
    		        str_map[mapkey] = -1;
    		        ret.push_back(strs[i]);
    		    }
    		}
    	}
    	return ret;
    }
};

int main(){
	Solution soln;
	vector<string> a;
	a.push_back("abccc");
	a.push_back("cbacc");
	a.push_back("abbcc");
	vector<string> ret = soln.anagrams(a);
	int len = ret.size();
	for(int i = 0; i < len; i++){
		cout<<ret[i]<<endl;
	}
}