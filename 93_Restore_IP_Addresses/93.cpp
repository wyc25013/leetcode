#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> retset;
    	helper(0,s,1,retset,"");
    	return retset;
    }
    void helper(int pos, string& s, int dot, vector<string>& retset, string ret){
 //   	cout<<ret<<endl;
    	if(dot > 4){
    		if(pos < s.length())
    			return;
    		ret.pop_back();
    		retset.push_back(ret);
    		return;
    	}
    	if(pos < s.length()){
    		if(s[pos] != '0'){
    			helper(pos+1,s,dot+1,retset,ret+s.substr(pos,1)+".");
	    		if(pos+1 < s.length())
	    			helper(pos+2,s,dot+1,retset,ret+s.substr(pos,2)+".");
    		}else
    		    helper(pos+1,s,dot+1,retset,ret+s.substr(pos,1)+".");
    		
	    	if(s[pos] == '1'){
	    		if(pos+2 < s.length())
		    		helper(pos+3,s,dot+1,retset,ret+s.substr(pos,3)+".");
	    	}else if(s[pos] == '2'){
	    		if(pos+2 < s.length() && s[pos+1] == '5' && s[pos+2] <= '5')
	    			helper(pos+3,s,dot+1,retset,ret+s.substr(pos,3)+".");
	    		else if(pos+2 < s.length() && s[pos+1] < '5')
	    			helper(pos+3,s,dot+1,retset,ret+s.substr(pos,3)+".");
	    	}
    	}
    }
};

int main(){
	string s = "25525511135";
	Solution soln;
	vector<string> a = soln.restoreIpAddresses(s);
	while(a.size()){
		cout<<a.back()<<" ";
		a.pop_back();
	}
	cout<<endl;
}