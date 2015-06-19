#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		int len = beginWord.length();
		int ret = INT_MAX;
		if(wordDict.find(beginWord) != wordDict.end())
			helper(1,beginWord,wordDict,endWord,ret); 
		else{
			for(int i = 0; i < len; i++){	
				char origin = beginWord[i];		
				for(char j = 'a'; j <= 'z'; j++){
					if(j != origin){
						beginWord[i] = j;
						if(wordDict.find(beginWord) != wordDict.end()){
							wordDict.erase(wordDict.find(beginWord));
							helper(2,beginWord,wordDict,endWord,ret);
							wordDict.insert(beginWord);
						}
						beginWord[i] = origin;
					}
				}
			}
		}       
		if(ret == INT_MAX) return 0;
		return ret;
    }

    void helper(int step, string& beginWord, unordered_set<string>& wordDict, string& endWord, int& ret){
    	if(wordDict.size() == 1) return;
    	if(beginWord.compare(endWord) == 0){
			ret = ret > step ? step : ret;
			return;			
		} 
		int len = beginWord.length();
		for(int i = 0; i < len; i++){
			char origin = beginWord[i];
			for(char j = 'a'; j <= 'z'; j++){
				if(j != origin){
					beginWord[i] = j;
					if(beginWord.compare(endWord) == 0){
						ret = ret > step+1 ? step+1 : ret;
						return;
					} 
					if(wordDict.find(beginWord) != wordDict.end()){
						wordDict.erase(wordDict.find(beginWord));
						helper(step+1,beginWord,wordDict,endWord,ret);
						wordDict.insert(beginWord);
					} 
					beginWord[i] = origin;
				}
			}
		}
	}   
};
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    	queue<string> a; a.push(beginWord);
    	int len = beginWord.length();
    	if(!len) return 0;
    	int count = 0;
    	while(a.size()){
    		queue<string> b;
    		count++;
    		while(a.size()){
    			string s = a.front();
		    	for(int i = 0; i < len; i++){
		    	    char origin = s[i];
		    		for(char j = 'a'; j <= 'z'; j++){
		    			s[i] = j;
		    			if(s.compare(endWord) == 0) return count+1;
		    			if(wordDict.find(s) != wordDict.end()){
		    				b.push(s);
		    				wordDict.erase(s);
		    			}
		    			s[i] = origin;
		    		}
		    	}
		    	a.pop();
		    }
            a = b;
	    }
	    return 0;
    }
};

int main(){
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	Solution soln;
	cout<<soln.ladderLength("hit","cog",dict)<<endl;
}