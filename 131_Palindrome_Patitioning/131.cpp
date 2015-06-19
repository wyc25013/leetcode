#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
		vector<vector<string> > retset;
		int len = s.length();
		if(len < 2){
			vector<string> a(1,s);
			retset.push_back(a);
			return retset;
		} 

		for(int i = 1; i <= len; i++){
			vector<string> ret;
			if(ifpalindrome(s.substr(0,i))){
				ret.push_back(s.substr(0,i));
				helper(s.substr(i,len-i),ret,retset);
				ret.pop_back();
			}
		}

		return retset;
    }

    void helper(string s,vector<string>& ret,vector<vector<string> >& retset){
    	int len = s.length();
    	if(!len){
    		retset.push_back(ret);
    		return;
    	}

    	for(int i = 1; i <= len; i++){
    		if(ifpalindrome(s.substr(0,i))){
    			ret.push_back(s.substr(0,i));
    			helper(s.substr(i,len-i),ret,retset);
    			ret.pop_back();
    		}
    	}
    }

    bool ifpalindrome(string s){
    	int len = s.length();
    	if(len < 2) return true;
    	int head = 0; int tail = len-1;
    	while(head < tail){
    		if(s[head] == s[tail]){
    			head++;
    			tail--;
    		} else
    			return false;
    	}
    	return true;
    }
};

int main(){
	string s = "aab";
	Solution soln;
	vector<vector<string> > a = soln.partition(s);
	while(a.size()){
		vector<string> tmp = a.back();
		while(tmp.size()){
			cout<<tmp.back()<<" ";
			tmp.pop_back();
		}
		cout<<endl;
		a.pop_back();
	}
}