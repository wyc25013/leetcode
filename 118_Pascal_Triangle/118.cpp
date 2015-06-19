#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > ret;
		if(!numRows) return ret;
		vector<int> one(1,1);
		ret.push_back(one);
		for(int i = 2; i <= numRows; i++){
			vector<int> tmp = ret.back();
			int len = tmp.size();
			vector<int> next(len+1,1);
			for(int j = 0; j < len-1; j++){
				next[j+1] = tmp[j]+tmp[j+1];
			}
			ret.push_back(next);
		} 
		return ret;
    }
};