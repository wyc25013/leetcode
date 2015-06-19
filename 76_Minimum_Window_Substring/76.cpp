#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(int i = 0; i < t.length(); i++){
        	if(m.find(t[i])==m.end())
        		m[t[i]] = 1;
        	else 
        		m[t[i]]++;
        }
        int start = 0;
        for(; start < s.length();start++){
        	if(m.find(s[start])!=m.end())
        		break;
        }

        int sp = start; int ep = start;
        bool ifw = false; int ms; int me;
        for(int i = start; i < s.length(); i++,ep++){
        	if(m.find(s[i])!=m.end()){
        		if(m[s[i]] <= 0 && s[sp]==s[i]){
    				sp++;
    				while(1){
        				while(m.find(s[sp])==m.end())
        					sp++;
        				if(m[s[sp]] < 0){
        					m[s[sp]]++;
        					sp++;
        				}else break;
        			}
        		} else m[s[i]]--;
        		if(!ifw){
        			if(ifwhole(m)){
        				ifw = true;
        				ms = sp; me = ep;
        			}
        		}else{
        			if(ep-sp < me-ms){
        				me = ep;
        				ms = sp;
        			}
        		}
        	}
        }
        if(!ifw) return "";
        else return s.substr(ms,me-ms+1);
    }

    bool ifwhole(unordered_map<char,int>& m){
    	unordered_map<char,int>::iterator it = m.begin();
    	while(it != m.end()){
    		if(it->second > 0)
    			return false;
    		it++;
    	}
    	return true;
    }
};
*/

// an improved version of above solution
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(256,0);
        vector<bool> b(256,false);
        for(int i = 0; i < t.length(); i++){
    		m[t[i]]++;
    		b[t[i]] = true;
        }
        int start = 0;
        for(; start < s.length();start++){
        	if(b[s[start]])
        		break;
        }
        int tl = t.length();
        int sp = start; int ep = start;
        bool ifw = false; int ms = 0; int me = INT_MAX;
        for(int i = start; i < s.length(); i++,ep++){
        	if(b[s[i]]==true){
        		if(m[s[i]] <= 0 && s[sp]==s[i]){
    				sp++;
    				while(1){
        				while(b[s[sp]]==false)
        					sp++;
        				if(m[s[sp]] < 0){
        					m[s[sp]]++;
        					sp++;
        				}else break;
        			}
        		} else {
        		    m[s[i]]--;
        		    if(m[s[i]]>=0) tl--;
        		}
        		if(tl<=0){
        			if(ep-sp < me-ms){
        				me = ep;
        				ms = sp;
        			}
        		}
        	}
        }
        if(tl>0) return "";
        else return s.substr(ms,me-ms+1);
    }
};

int main(){
	Solution soln;
	cout<<soln.minWindow("ADOBECODEBANC","ABC")<<endl;
}