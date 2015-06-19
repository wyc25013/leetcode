#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		vector<int> v1; vector<int> v2;
		while(version1.length()){
			int pos = version1.find(".");
			string s = version1.substr(0,pos);
			v1.push_back(stoi(s));
			if(pos == string::npos)
				version1 = "";
			else
				version1 = version1.substr(pos+1);
		}        
		while(version2.length()){
			int pos = version2.find(".");
			string s = version2.substr(0,pos);
			v2.push_back(stoi(s));
			if(pos == string::npos)
				version2 = "";
			else
				version2 = version2.substr(pos+1);
		}  

		int len = min(v1.size(),v2.size());
		int i = 0;
		for(; i < len; i++){
			if(v1[i] > v2[i])
				return 1;
			else if(v1[i] < v2[i])
				return -1;
		}
		if(len==v1.size() && len != v2.size()){
		    for(int j = i; j < v2.size(); j++){
		        if(v2[j] != 0) return -1;
		    }
		    return 0;
		}
		if(len==v2.size() && len != v1.size()){
		    for(int j = i; j < v1.size(); j++){
		        if(v1[j] != 0) return 1;
		    }
		    return 0;
		}
		if(len==v1.size() && len==v2.size())
			return 0;
    }
};

int main(){
	string s1 = "2.3.50.101";
	string s2 = "2.3.10.9.1";
	Solution soln;
	cout<<soln.compareVersion(s1,s2)<<endl;
}