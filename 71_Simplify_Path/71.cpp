#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	stack<string> ret;
    //	ret.push("/");
    	path.replace(0,path.length(),path.substr(1,string::npos));
    	if(path[path.length()-1] != '/')
    	    path += "/";

    	while(path.length()){
    		int pos = path.find("/");
    		string cur = path.substr(0,pos);
    //		cout<<cur<<endl;
    		if(cur.compare(".") == 0 || cur.compare("") == 0){
    			// do nothing
    		} else if(cur.compare("..") == 0) {
    		    if(ret.size())
    		        ret.pop();
    		} else {
    			ret.push(cur);
    		}
    		path.replace(0,path.length(),path.substr(pos+1,string::npos));
    	}
    	if(ret.empty())
    	    return "/";
    	string result = ret.top();
    	ret.pop();
    	while(ret.size()){
    		result = ret.top() +"/"+ result;
    		ret.pop();
    	}
    	result = "/"+result;

    	return result;
    }
};

int main(){
	Solution soln;
	string a = "/home/";
	string b = "/a/./b/../../c/";
//	int pos = a.find("/");
//	a.replace(0,a.length(),a.substr(pos+1,string::npos));
//	cout<<a<<endl;

	cout<<soln.simplifyPath(b)<<endl;
}