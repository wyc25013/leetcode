#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
    	int len = s.length();
    	if(!len) return 0;
    	/* not work if using stack only
    	stack<char> a;
    	int i = 0;
    	for(; i<len && s[i]==')';i++);
    	int ret = 0; int max = ret;
    	if(i == len) return ret;
    	a.push(s[i]);
    	int localret = 0;
    	for(int j = i+1; j<len; j++){
    		if(s[j] == '(') a.push(s[j]);
    		else{
				if(!a.empty()){
    				localret += 2;
    				a.pop();
    				if(a.empty()){
    					ret += localret;
    					localret = 0;
    				} else{

    				}
    			}else{
    				if(ret > max) max = ret;
    				ret = 0; localret = 0;
    			}
    		}
    	}
    	if(localret > ret) ret = localret;
    	return max>ret? max : ret;
    	*/
	    stack<int> a;
	    vector<bool> dp(len,false);
	    for(int j = 0; j<len; j++){
			if(s[j] == '(') a.push(j);
			else{
				if(!a.empty()){
					dp[j] = true;
	    			dp[a.top()] = true;
	    			a.pop();
				}
			}
		}
	
		int cnt = 0; int max = 0;
		for(int i = 0; i < len; i++){
			if(dp[i]) cnt++;
			else{
				if(cnt > max) max = cnt;
				cnt = 0; 
			}
		}
	    return cnt>max? cnt:max;
	}
};

int main(){
	string s1 = "(()(((()";
	string s2 = "()())())";
	string s3 = "(((())))";
	string s4 = "(()()())()";
	string s5 = "()(()";
	Solution soln;
	cout<<soln.longestValidParentheses(s1)<<endl;
	cout<<soln.longestValidParentheses(s2)<<endl;
	cout<<soln.longestValidParentheses(s3)<<endl;
	cout<<soln.longestValidParentheses(s4)<<endl;
	cout<<soln.longestValidParentheses(s5)<<endl;
}