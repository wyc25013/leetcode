#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> ret;
		int lenw = words.size();
		if(!lenw) return ret;
		int lens = words[0].length();
		if(!lens) return ret;
		int len = s.length();
		if(lens*lenw > len) return ret;

		unordered_map<string,int> m;
		for(int i = 0; i < lenw; i++){
			if(m.find(words[i])==m.end())
				m[words[i]] = 1;
			else m[words[i]]++;
		}
		
		/*
		for(int i = 0; i <= len-lens*lenw; i++){
			string tmp = s.substr(i,lens); 
			if(m.find(tmp) != m.end()){
				if(m[tmp]==1)
					m.erase(tmp);
				else m[tmp]--;
				int r = i;
				helper(m,s,lens,i+lens,r,ret);
				if(m.find(tmp)==m.end())
					m[tmp]=1;
				else m[tmp]++;
			}
		}   
		*/
		unordered_map<string,int> mm = m;
		for(int i = 0; i <= len-lens*lenw; i++){
			m = mm;
			bool iff = true;
			for(int j = 0; j < lenw; j++){
				string tmp = s.substr(i+j*lens,lens);
				if(m.find(tmp)!=m.end()){
					if(m[tmp]==1)
						m.erase(tmp);
					else m[tmp]--;
				} else {
					iff = false;
					break;
				}
			}
			if(iff) ret.push_back(i);
		}      
		return ret;
    }
    /*
    void helper(unordered_map<string,int>& m, string& s, int lens, int pos, int r, vector<int>& ret){
    	if(m.empty()){
    		ret.push_back(r);
    		return;
    	}
    	if(s.length()==pos) return;
		string tmp = s.substr(pos,lens); 
		if(m.find(tmp) != m.end()){
			if(m[tmp]==1)
				m.erase(tmp);
			else m[tmp]--;
			helper(m,s,lens,pos+lens,r,ret);
			if(m.find(tmp)==m.end())
				m[tmp]=1;
			else m[tmp]++;
		}
    }
    */
};

int main(){
	vector<string> a;
//	for(int i =0;i<10;i++)	
	a.push_back("foo");
	a.push_back("bar");
	Solution soln;
	vector<int> b = soln.findSubstring("foobarthebarfooman",a);
	for(int i = 0; i < b.size(); i++)
		cout<<b[i]<<" ";
	cout<<endl;
}