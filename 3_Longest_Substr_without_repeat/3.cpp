#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

/*queue & unordered_map solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		unordered_map<char,bool> m;
    	unordered_map<char,bool>::iterator mit;
    	queue<char> q;
    	int longest = 0;
    	for(int i = 0; i < s.length(); i++) {

    		mit = m.find(s[i]);
    		if(mit == m.end()) {
    			m.insert(pair<char,bool>(s[i],true));
    			q.push(s[i]);
    		}
    		else if(mit != m.end() && mit->second == false) {
    			q.push(s[i]);
    			mit->second = true;
    		}
    		else {
    			while(q.front() != s[i]) {
    				m[q.front()] = false;
    				q.pop();
    			}
    			q.pop();
    			q.push(s[i]);
    		}
    		longest = (longest > q.size() ? longest : q.size());
    	}   
    	return longest;     
    }
};
*/

//two pointer & vector solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		bool m[256] = {false};
    	char* head = &s[0];
    	char* tail = &s[0];
    	int longest = 0;
    	for(int i = 0; i < s.length(); i++) {
    		if(m[s[i]] == false) {
    			m[s[i]] = true;
    			tail = &s[i];
    		}
    		else {
    			while(*head != s[i]) {
    				m[*head] = false;
    				head++;
    			}
    			head++;
    			tail = &s[i];
    		}
    		longest = (longest > (tail - head + 1) ? longest : (tail - head + 1));
    	}   
    	return longest;    
    }
};
int main(){
	Solution soln;
	cout << soln.lengthOfLongestSubstring("abcabcbb") <<" "<<soln.lengthOfLongestSubstring("bbbb") << endl;
	return 0;
}
