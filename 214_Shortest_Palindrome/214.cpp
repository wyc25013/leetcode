#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
		int len = s.length();
		string reverse;
		for(int i = len-1; i>=0;i--)
			reverse.push_back(s[i]);
		int pos;
		for(int i = len; i >= 1; i--){
			if(s.substr(0,i)==reverse.substr(len-i)){
				pos = len-i;
				break;
			}
		}        
		return reverse.substr(0,pos)+s;
    }
};

int main(){
	Solution soln;
	cout<<soln.shortestPalindrome("abcd")<<endl;
	cout<<soln.shortestPalindrome("aacecaaa")<<endl;
}