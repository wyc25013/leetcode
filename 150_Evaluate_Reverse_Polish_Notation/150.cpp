#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<string> ret;
		int len = tokens.size();
		if(len == 1) return stoi(tokens[0]);
		ret.push(tokens[0]);
		ret.push(tokens[1]);
		ret.push(tokens[2]);
		int count = 3;
		while(1){
			string a = ret.top();
			if(a!= "+" && a!= "-" && a!= "*" && a!= "/"){
				if(count < len){
					ret.push(tokens[count]);
					count++;
				} else break;
			}else{
				ret.pop();
				string r1 = ret.top(); ret.pop();
				string r2 = ret.top(); ret.pop();
				int a1 = stoi(r1); int a2 = stoi(r2); int a0;
				if(a == "+") a0 = a1+a2;
				else if(a == "-") a0 = a2-a1;
				else if(a == "*") a0 = a1*a2;
				else a0 = a2/a1;
				ret.push(to_string(a0));
			}
		}        
		return stoi(ret.top());
    }
};

int main(){
	vector<string> a;
	a.push_back("4");
	a.push_back("13");
	a.push_back("5");
	a.push_back("/");
	a.push_back("+");
	Solution soln;
	cout<<soln.evalRPN(a)<<endl;
}