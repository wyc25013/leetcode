#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

char lmap[32] = {
					'a','b','c','0',
					'd','e','f','0',
					'g','h','i','0',
				 	'j','k','l','0',
					'm','n','o','0',
					'p','q','r','s',
					't','u','v','0',
					'w','x','y','z'
				};

void combHelper(vector<string>* result, string digits, int pos){
	if(!result->size()){
	//	cout <<"nana"<<endl;
		int idx = digits[pos] - 48 - 2;
		for(int j = 0; lmap[4*idx+j] != '0' && j < 4; ++j){
			string rels;
			rels.push_back(lmap[4*idx+j]);
			result->push_back(rels);
		}
	}
	else{
	//	cout <<"jaja"<<endl;
		int len = result->size();
		for(int i = 0; i < len; ++i){
		//	cout<<"hehe"<<endl;
	//		cout<<result->size()<<endl;
			int idx = digits[pos] - 48 - 2;
	//		cout <<idx<<endl;
			(*result)[i] += lmap[4*idx]; 
			for(int j = 1; lmap[4*idx+j]!='0' && j < 4 ; ++j){
		//		cout <<"htht"<<endl;
				string rels = (*result)[i];
				rels.pop_back();
				rels.push_back(lmap[4*idx+j]);
				result->push_back(rels);
			}
		}
	}
	
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> result;
        if(!len)
        	return result;
    //    cout <<"haha " <<endl;
        for (int i = 0; i < len; ++i)
        {
    //    	cout <<"hehe"<<endl;
        	combHelper(&result,digits,i);
        }
        return result;
    }
};

int main(){
	Solution soln;
	string s = "23";
	vector<string> v = soln.letterCombinations(s);
//	cout << v.size()<<endl;
	while(v.size()){
		cout << v.back() <<" ";
		v.pop_back();
	}
	//cout<<"here"<<endl;
	cout<<endl;
	return 0;
}