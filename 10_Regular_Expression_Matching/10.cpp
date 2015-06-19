#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		// here s means string to be judged while p means pattern
		// so we can assume that only p would contain '*' and '.' 
		/*
	    if(p.empty()) return s.empty();
		if(p.length() > 1){
			if(s.empty()){
		        if(p.length()%2==1) return false;
		        else{
		            if(p[1] != '*') return false;
		            else return isMatch(s,p.substr(2));
		        }
		    } 
			if(p[1]=='*'){
				if(p[0] != s[0] && p[0] != '.') return isMatch(s,p.substr(2));
				else{
					int cnt = 0;
					for(; cnt+1 < s.length();cnt++)
						if(s[cnt+1]!=s[cnt]) break;
					if(p[0] == '.')
					    for(int i = 0; i <= s.length(); i++)
						    if(isMatch(s.substr(i),p.substr(2))) return true;

					for(int i = 0; i <= cnt+1; i++)
						if(isMatch(s.substr(i),p.substr(2))) return true;

					return false;
				}
			}else{
				if(p[0] != s[0] && p[0] != '.') return false;
				else return isMatch(s.substr(1),p.substr(1));
			}
		}else{
			if(s.length() != 1) return false;
			return p[0]==s[0] || p[0]=='.';
		}
		*/

		// match[i][j] == true means 
		// s[0]-s[i-1] matches p[0]-p[j-1]
		// means empty if i or j equal to zero
		int lens = s.length(); int lenp = p.length();
		vector<vector<bool> > match(lens+1,vector<bool>(lenp+1,false));
		match[0][0] = true;
		/*
		for(int i = 1; i < lens+1; i++)
			match[i][0] = false;
		*/
		for(int i = 1; i < lenp+1; i++)
			match[0][i] = i>1 && p[i-1]=='*' && match[0][i-2];

		for(int i = 1; i < lens+1; i++){
			for(int j = 1; j < lenp+1; j++){
				if(p[j-1] == '*')
					match[i][j] = match[i][j-2] || ((s[i-1]==p[j-2] || p[j-2]=='.') && match[i-1][j]);
				else
					match[i][j] = match[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
			}
		}
		return match[lens][lenp];
		/* dp solution
	    vector<bool> match(s.length()+1,false);
	    match[s.length()] = true;
	    for(int i=p.length()-1;i>=0;i--){
	        if(p[i]=='*'){
	            for(int j=s.length()-1;j>=0;j--)    
	                match[j] = match[j]||match[j+1]&&(p[i-1]=='.'||s[j]==p[i-1]);
	            i--;
	        }else{
	            for(int j=0;j<s.length();j++)   
	                match[j] = match[j+1]&&(p[i]=='.'||p[i]==s[j]);
	            match[s.length()] = false;
	        }
	    }
	    return match[0];
	    */
	}
};