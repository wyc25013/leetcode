#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    vector<pair<int,int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int,int> > ret;
        int lenb = buildings.size();
        if(!lenb) return ret;

        /* brutal solution costs O(n*n)
        int left = buildings[0][0];
        
        vector<int> a(10000,0);
        int right = left;
        for(int i = 0; i < lenb; i++){
        	int li = buildings[i][0];
        	int ri = buildings[i][1];
        	int hi = buildings[i][2];
        	for(int j = li-left; j < ri-left; j++){
        		if(hi > a[j])
        			a[j] = hi;
        	}
        	if(ri > right) right = ri;
        }
        
        for(int i = 0; i < right-left; ){
        	int x = i+left;
        	int y = a[i];
        	ret.push_back(pair<int,int>(x,y));
        	while(a[i]==y)
        		i++;
        }
        ret.push_back(pair<int,int>(right,0));
        */

        // d&c solution costs O(nlogn)
        ret = *(divide(buildings,0,lenb-1));
        return ret;
    }

    vector<pair<int,int> >* divide(vector<vector<int> >& buildings, int start, int end){
    	if(end-start+1 >= 2){
    		int mid = (start+end)/2;
    		vector<pair<int,int> >* f = divide(buildings,start,mid);
    		vector<pair<int,int> >* s = divide(buildings,mid+1,end);
    		return merge(f,s);
    	}else{	//start==end
    		vector<pair<int,int> >* a = new vector<pair<int,int> >;
			a->push_back(pair<int,int>(buildings[start][0],buildings[start][2]));
			a->push_back(pair<int,int>(buildings[start][1],0));
			return a;
    	}
    }

    vector<pair<int,int> >* merge(vector<pair<int,int> >* f,vector<pair<int,int> >* s){
    	int fi = 0; int si = 0; 
    	int hf = 0; int hs = 0; 
    	vector<pair<int,int> >* ret = new vector<pair<int,int> >;
    	while(fi < f->size() && si < s->size()){
    		if((*f)[fi].first < (*s)[si].first){
    			int li = (*f)[fi].first;
    			int hi = (*f)[fi].second > hs ? (*f)[fi].second : hs;
    			if(ret->empty() || (!ret->empty() && hi!=ret->back().second))
    				ret->push_back(pair<int,int>(li,hi));
    			hf = (*f)[fi].second; fi++;
    		}else if((*f)[fi].first > (*s)[si].first){
    			int li = (*s)[si].first;
    			int hi = (*s)[si].second > hf ? (*s)[si].second : hf;
    			if(ret->empty() || (!ret->empty() && hi!=ret->back().second))
    				ret->push_back(pair<int,int>(li,hi));
    			hs = (*s)[si].second; si++;
    		}else{
    			int li = (*f)[fi].first;
    			int hi = (*f)[fi].second > (*s)[si].second ? (*f)[fi].second : (*s)[si].second;
    			if(ret->empty() || (!ret->empty() && hi!=ret->back().second))
    				ret->push_back(pair<int,int>(li,hi));
    			hf = (*f)[fi].second; fi++;
    			hs = (*s)[si].second; si++;
    		}
    	}
    	while(si < s->size()){
    		ret->push_back((*s)[si]);
    		si++;
    	}
    	while(fi < f->size()){
    		ret->push_back((*f)[fi]);
    		fi++;
    	}
    	return ret;
    }
};

int main(){
	int a1[] = {2,4,7};
	int a2[] = {2,4,5};
	int a3[] = {2,4,6};
	int a4[] = {15,20,10};
	int a5[] = {19,24,8};
	vector<vector<int> > a;
	a.push_back(vector<int>(a1,a1+3));
	a.push_back(vector<int>(a2,a2+3));
	a.push_back(vector<int>(a3,a3+3));
//	a.push_back(vector<int>(a4,a4+3));
//	a.push_back(vector<int>(a5,a5+3));

	Solution soln;
	vector<pair<int,int> > b = soln.getSkyline(a);
	for(int i = 0; i < b.size(); i++){
		cout<<b[i].first<<" "<<b[i].second<<endl;
	}
}