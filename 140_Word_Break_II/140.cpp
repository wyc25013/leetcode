#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.length();		
		vector<string> retset;
		if(!len){
			retset.push_back(s);
			return retset;
		}
		vector<bool> map(len*len,false);
		for(int i = 0; i < len; i++){
			for(int j = 0; j <= i; j++){	//j->i
				string ss = s.substr(j,i-j+1);
				if(wordDict.find(ss) != wordDict.end())
					map[j*len+i] = true;
			}
		}
		vector<bool> map2 = map;
		for(int i = 0; i < len; i++){
			for(int j = 0; j < i; j++){
				if(!map[i])
					if(map[j] && map[(j+1)*len+i])
						map[i] = true;
			}
		}
		if(map[len-1])
		    helper(s,map2,0,"",retset);  
		else return retset;
		
		return retset;  
    }

    void helper(string& s, vector<bool>& map, int pos,string ret,vector<string>& retset){
    	int len = s.length();
    	if(pos == len){
    		ret.pop_back();
    		retset.push_back(ret);
    		return;
    	}	
    	for(int i = pos; i < len; i++){
    		if(map[pos*len+i]){
    			helper(s,map,i+1,ret+s.substr(pos,i-pos+1)+" ",retset);
    		}
    	}
    }
};
*/
//use backtracking
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.length();		
		vector<string> retset;
		if(!len){
			retset.push_back(s);
			return retset;
		}
		unordered_map<int,vector<int> > bt;
//		vector<bool> map(len*len,false);
		for(int i = 0; i < len; i++){
			for(int j = 0; j <= i; j++){	//j->i
				string ss = s.substr(j,i-j+1);
				if(wordDict.find(ss) != wordDict.end()){
//					map[j*len+i] = true;
					bt[i].push_back(j-1);
				}
			}
		}
//		for(int i = 0; i < len; i++){
//			for(int j = 0; j < i; j++){
//				if(!map[i])
//					if(map[j] && map[(j+1)*len+i]){
//						map[i] = true;
//					}
//			}
//		}
//		if(map[len-1])
		    helper(s,bt,len-1,"",retset);  
//		else return retset;
		
		return retset;  
    }

    void helper(string& s, unordered_map<int,vector<int> >& bt, int pos,string ret,vector<string>& retset){
    	int len = s.length();
    	if(pos == -1){
    		ret.pop_back();
    		retset.push_back(ret);
    		return;
    	}	
    	vector<int> parent = bt[pos];
    	while(parent.size()){
    		int a = parent.back();
    		helper(s,bt,a,s.substr(a+1,pos-a)+" "+ret,retset);
    		parent.pop_back();
    	}
    }
};

int main(){
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	string s = "catsanddog";
	Solution soln;
	vector<string> a = soln.wordBreak(s,dict);
	while(a.size()){
		cout<<a.back()<<endl;
		a.pop_back();
	}
}