#include <string>
#include <iostream>
#include <vector>
using namespace std;

//backtracking solution, bad
/*
class Solution {
public:
    int numDecodings(string s) {
        int ret = 0;
        if(s.length() == 0)
            return ret;
        helper(0,s,ret);
        return ret;
    }

    void helper(int pos, string& s, int& ret){
    	if(pos == s.length()){
    		ret++;
    		return;
    	}
    	else{
    		if(s[pos] == '0')
    			return;
    		helper(pos+1,s,ret);
    		if(pos+1 < s.length()){	
    		    if(s[pos] == '1')
    			    helper(pos+2,s,ret);
    			else if((s[pos+1] >= '0' && s[pos+1] <='6') && (s[pos] == '2'))
    				helper(pos+2,s,ret);
    		}
    	}
    }
};
*/

//dp is better
class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0)
            return 0;
        vector<int> a(s.length(),0);
        if(s[0] == '0')
        	return 0;
        else
        	a[0] = 1;
        if(s.length() == 1)
            return a[0];
            
        if(s[0] == '1'){
            if(s[1] == '0')
                a[1] = 1;
            else
                a[1] = 2;
        }
        else if(s[0] == '2' && s[1] >= '1' && s[1] <= '6')
        	a[1] = 2;
        else if(s[0] >= '3' && s[1] == '0')
        	return 0;
        else
            a[1] = 1;

        for(int i = 2; i < s.length(); i++){
        	if(s[i] == '0'){
        		if(s[i-1] != '1' && s[i-1] != '2')
        			return 0;
        		else
        			a[i] = a[i-2];
        	}else{
        		if(s[i-1] == '1')
        			a[i] = a[i-1] + a[i-2];
        		else if(s[i-1] == '2'){
        			if(s[i] >= '7')
        				a[i] = a[i-1];
        			else
        				a[i] = a[i-1]+a[i-2];
        		}
        		else
        			a[i] = a[i-1];
        	}
        }
        return a[s.length()-1];
    }
};


int main(){
	string s = "110";
	Solution soln;
	cout<<soln.numDecodings(s)<<endl;
}