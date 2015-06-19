#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
using namespace std;
//my stupid solution
/*
bool isValid(string s) { 
   	int circle = 0;
   	stack<char> inner;
    int len = s.length();
    if(s[len-1] != ')')
    	return false;
    for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			circle+= -1;
			inner.push('c');
		}
		else if (s[i] == ')') {
			if (inner.empty() || inner.top() != 'c' )
				return false;
			else {
				circle+= 1;
				inner.pop();
			}
		}
    }
    if(inner.size() || circle)
    	return false;
    return true;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	string first;
    	first += "(";
    	queue<string> tmp;
    	tmp.push(first);
    	for(int i = 0; i < 2*n-1; i++){
    		int len = tmp.size();
    		for(int j = 0; j < len; j++){
    			string s,s1,s2;
    			s = tmp.front();
    			s1 = s + "(";
    			s2 = s1;
    			int l = s2.length();
    			s2[l-1] = ')';
				tmp.pop();
				tmp.push(s1);
				tmp.push(s2);
    		}
    	}
    	while(tmp.size()){
    		if(isValid(tmp.front()))
    			result.push_back(tmp.front());
    		tmp.pop();
    	}
    	return result;
    }
};
*/

// recursive solution by others
class Solution {
public:
	void helper(vector<string>* result, int balance, int length, string s){
		if(s.length() == length){
			result->push_back(s);
			return;
		}

		if(balance > 0){
			helper(result,balance-1,length,s+")");
		}

		if(s.length()+balance < length){
			helper(result,balance+1,length,s+"(");
		}
	}

    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	int balance = 0;
    	helper(&result,0,2*n,"");
    	return result;
    }
};

int main(){
	Solution soln;
	vector<string> result = soln.generateParenthesis(4);
	for(int i = 0; i < result.size(); i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}