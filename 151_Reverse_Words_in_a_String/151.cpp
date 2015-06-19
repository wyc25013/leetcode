#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		if(!s.length()) return;
		int len = s.length();
		stack<string> ss;
		while(s.length()){
			int pos = s.find_first_not_of(" ");
			if(pos == string::npos){
				s = "";
				break;
			}
			s = s.substr(pos);
			int pos1 = s.find(" ");
			string a = s.substr(0,pos1);
			if(pos1 == string::npos){
				ss.push(a);
				s = "";
				break;
			}
			ss.push(a);
			s = s.substr(pos1+1);
		}
		while(!ss.empty()){
			s += ss.top()+" ";
			ss.pop();
		}
		s.pop_back();
    }
};

int main(){
	string s = "aafa jfalfjal     fafalj   fjal";
	Solution soln;
	soln.reverseWords(s);
	cout<<s<<endl;
}