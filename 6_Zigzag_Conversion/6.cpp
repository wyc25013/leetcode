#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int nRows){
		string r;

		try{
			if(!s.length()||nRows ==1)
				throw std::runtime_error("oops");
		} catch(std::runtime_error &re){
			return s;
		}
		
		int m = s.length()/(nRows*2-2);
		for(int i = 0; i < nRows; i++){
			int k = (i==0)||i==(nRows-1);
			int l = (s.length()%(nRows*2-2)) > i;
			for(int j = i, count = 0; count < m+l; j+=(nRows-1)*2, count++){
				r.push_back(s[j]);
				if(!k){
					if((j+(nRows-1-i)*2)<s.length())
						r.push_back(s[j+(nRows-1-i)*2]);
				}
			}
		}
		return r;

	}
};

int main(){
	Solution soln;
	cout<<soln.convert("hello world", 2)<<endl;
	return 0;
}