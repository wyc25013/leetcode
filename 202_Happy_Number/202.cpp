#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	unordered_set<int> vi;
		return helper(n,vi);
    }

    bool helper(int n, unordered_set<int>& vi){
        if(n==1) return true;
    	string s = to_string(n);
		int len = s.length();
		int next = 0;
		for(int i = 0; i < len; i++){
			next += (s[i]-48)*(s[i]-48);
		}
		if(next==1) return true;
		if(vi.find(next) == vi.end()) vi.insert(next);
		else return false;
		return helper(next,vi);
    }
};

int main(){
	Solution soln;
	cout<<soln.isHappy(7)<<endl;
}