#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordDict) {
		int len = beginWord.length();
		vector<vector<string> > retset;
		if(!len) return retset;
		
		if(wordDict.find(beginWord) != wordDict.end())
		    wordDict.erase(beginWord);
		if(wordDict.find(endWord) == wordDict.end())
			wordDict.insert(endWord);

		unordered_map<string, vector<string> > endmap;
		vector<string> a; a.push_back(beginWord);
		
		bool iffound = false;
		while(!iffound && !a.empty()){
			vector<string> tobedel;
	    	while(a.size()){
	    		string s = a.back();
	    		if(s.compare(endWord) == 0){
	    			iffound = true;
	    			break;
	    		}
		    	for(int i = 0; i < len; i++){
		    	    string tmp = s;
		    		for(char j = 'a'; j <= 'z'; j++){
		    			tmp[i] = j;
		    			if(tmp.compare(s) == 0) continue;
		    			
		    			if(wordDict.find(tmp) != wordDict.end()){
		    				if(endmap.find(tmp) == endmap.end())
		    					tobedel.push_back(tmp);
		    				endmap[tmp].push_back(s);
		    			}	
		    		}
		    	}
		    	a.pop_back();
		    }
		    
		    int delsize = tobedel.size();
		    for(int i = 0; i < delsize; i++){
		    	wordDict.erase(tobedel[i]);
		    	a.push_back(tobedel[i]);
		    }
		}

		if(endmap[endWord].size() == 0)
			return retset;
		else{
			vector<string> ret; ret.push_back(endWord);
			backtracking(endWord,endmap,retset,beginWord,ret);
			return retset;
		}
    }

    void backtracking(string findparent, unordered_map<string,vector<string> >& endmap, 
    					vector<vector<string> >& retset, string& beginWord,vector<string>& ret)
    {
    	if(findparent.compare(beginWord) == 0){
    		vector<string> topush;
    		int size = ret.size();
    		for(int i = size-1; i >= 0; i--)
    			topush.push_back(ret[i]);
    		retset.push_back(topush);
    		return;
    	}
    	vector<string> next = endmap[findparent];
    	int len = next.size();
    	for(int i = 0; i < len; i++){
    		ret.push_back(next[i]);
    		backtracking(next[i],endmap,retset,beginWord,ret);
    		ret.pop_back();
    	}
    }
};

int main(){
	unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("rex");
	Solution soln;
	vector<vector<string> > ret = soln.findLadders("red","tax",dict);
	while(ret.size()){
		vector<string> a = ret.back();
		while(a.size()){
			cout<<a.back()<<" ";
			a.pop_back();
		}
		cout<<endl;
		ret.pop_back();
	}
}