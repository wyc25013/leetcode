#include <iostream>
#include <string>
#include <vector>
using namespace  std;

class Solution {
public:
	string LongestCommonPrefix(vector<string> &strs) {
		string result;
		int len = strs.size();
		if (!len)
			return result;
		int shortest = strs[0].length();
		for (int i = 1; i < len; i++) {
			if (strs[i].length() < shortest)
				shortest = strs[i].length();
		}
		if (!shortest)
			return result;
		int count = shortest;
		while (count) {
			result+= strs[0][shortest - count];
			
			for (int i = 1; i < len; i++) {
				if (result.back() != strs[i][shortest - count]) {
					result.pop_back();
					return result;
				}
			}

			count--;
		}

		return result;
		
	}
};

int main(){
	Solution soln;
	vector<string> strs;
	strs.push_back("abcd");
	strs.push_back("abc");
	strs.push_back("abd");
	cout << soln.LongestCommonPrefix(strs) <<endl;
	return 0;
}