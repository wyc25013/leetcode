#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> ret;
     	vector<int> m;
     	for(int i = 0; i < pow(2,n); i++){
     		m.push_back(i);
     	}   

     	ret.push_back(0);
     	m[0] = -1;
     	if(n==0)
     	    return ret;
 		ret.push_back(1);
 		m[1] = -1;
 		if(n==1)
 		    return ret;
 		helper(1,n,m,ret);

     	return ret;
    }

    void helper(int start, int n, vector<int>& m, vector<int>& ret){
    	for(int i = 0; i<n; i++){
    		int tmp = (start % (int)pow(2,i+1))/(int)pow(2,i);
    		if(tmp == 1){
    			if(m[start-pow(2,i)] != -1){
    				ret.push_back(start-pow(2,i));
    				m[start-pow(2,i)] = -1;
    				helper(start-pow(2,i),n,m,ret);
    				break;
    			}
    		}else{
    			if(m[start+pow(2,i)] != -1){
    				ret.push_back(start+pow(2,i));
    				m[start+pow(2,i)] = -1;
    				helper(start+pow(2,i),n,m,ret);
    				break;
    			}
    		}
    	}
    }
};

int main(){
	Solution soln;
	vector<int> a = soln.grayCode(3);
	while(a.size()){
		cout<<a.back()<<" ";
		a.pop_back();
	}
	cout<<endl;

	cout<<(2<<2)<<endl;
}