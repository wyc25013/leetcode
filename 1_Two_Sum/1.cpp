#include <iostream>
#include <vector>
#include <map>

//hash table problem
//unordered_map find O(1) vs map find O(log n)
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int len = numbers.size();
		vector<int> v1;
		unordered_map<int,int> m;
		unordered_map<int,int>::iterator mit;
		for (int i = 0; i < len; i++) {
			mit = m.find(target - numbers[i]);
			if(mit == m.end()) 
			    m.insert(pair<int,int>(numbers[i],i+1));
			else {
				v1.push_back(mit->second);
				v1.push_back(i+1);
				break;
			}
		}
		return v1;
	}
};

int main () {
	Solution soln;
	vector<int> v;
	v.push_back(2);
	v.push_back(7);
	v.push_back(9);
	v.push_back(11);
	cout << soln.twoSum(v,9)[0]<<" "<<soln.twoSum(v,9)[1] <<endl;
	return 0;
}