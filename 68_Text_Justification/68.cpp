#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	int lenw = words.size();
    	int i = 0; vector<string> ret;
    	while(i < lenw){
    		string s; int cnt = 0; int cntw = 0; 
    		int start = i; int length = 0;
    		while(i < lenw && cnt+words[i].length() <= maxWidth){
    			cnt += words[i].length();
    			length += words[i].length();  
    			cnt++; i++; cntw++; 
    		}
    		if(cntw==1){
    			int space = maxWidth-length;
    			string sp;
    			while(space){
    				sp+=" ";
    				space--;
    			}
    			s += words[start]+sp;
    		}else{
    			int space = (maxWidth - length)/(cntw-1);
    			string sp;
    			while(space){
    				sp+=" ";
    				space--;
    			}
    			int res = (maxWidth-length)%(cntw-1);
    			while(cntw-1){
    				s+=words[start]+=sp;
    				if(res){
    					s+=" "; res--;
    				}
    				cntw--; start++;
    			}
    			s+=words[start];
    		}
    		ret.push_back(s);
    	}
    	
    	string last = ret.back();
    	ret.pop_back();
    	string ll;
    	while(last!=""){
    		int pos = last.find(" ");
    		if(pos != string::npos && pos != 0){
	    		ll+=last.substr(0,pos)+" ";
	    	    while(pos != string::npos && last[pos] == ' ')
	    		    pos++;
	    	    last = last.substr(pos);
	    	}else{
	    		ll+=last; last="";
	    	}
    	}
    	while(maxWidth-ll.length()){
    		ll+=" ";
    	}
    	ret.push_back(ll);
    	
    	return ret;
    }
};

int main(){
	Solution soln;
	vector<string> a;
	a.push_back("a");
	a.push_back("b");
	a.push_back("c");
	a.push_back("d");
	a.push_back("e");
//	a.push_back("text");
//	a.push_back("justification.");
	vector<string> b = soln.fullJustify(a,3);
	for(int i = 0; i < b.size();i++)
		cout<<b[i]<<endl;
}