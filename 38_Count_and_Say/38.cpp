#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// unknown bug here
class Solution {
	string helper(string s, int n){
		if(n == 0){
			return s;
		}
		else{
			int len = s.length();
			string ret;
			for(int i = 0; i < len; ){
				int say = s[i] - 48;
				int count = 1;
				while(s[i+1] == s[i]){
					i++;
					count++;
				}
				ret += to_string(count)+to_string(say);
				i++;
			}
			return helper(ret, n-1);		//bug here, need to return
		}

	}
public:
    string countAndSay(int n) {
		string init("1");
		return helper(init, n-1);
    }
};

/*
class Solution {
    void helper(string &s, int n){
		if(n == 0)
			return;
		else{
			int len = s.length();
			string ret;
			for(int i = 0; i < len; ){
				int say = s[i] - 48;
				int count = 1;
				while(s[i+1] == s[i]){
					i++;
					count++;
				}
				ret += to_string(count)+to_string(say);
				i++;
			}
			s.replace(0,ret.length(),ret);
			helper(s, n-1);
		}
	}
public:
    string countAndSay(int n) {
	    string init("1");
		helper(init, n-1);
		return init;
    }
};
*/
int main(){
	Solution soln;
	cout<<soln.countAndSay(6)<<endl;
}