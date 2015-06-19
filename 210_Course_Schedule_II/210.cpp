#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> emptyret;
        vector<int> ret(numCourses,0);
        for(int i = 0; i < numCourses;i++)
            ret[i] = i;
		int presize = prerequisites.size();
    	if(!presize) return ret;
		vector<vector<int> > pres(numCourses,vector<int>());
		vector<bool> vid(numCourses,false);
        int curlabel = 0;
        
		for(int i = 0; i < presize; i++)
			pres[prerequisites[i].first].push_back(prerequisites[i].second);
		
		for(int i = 0; i < numCourses; i++){
			if(vid[i]) continue;
			vector<bool> vvid(numCourses,false);
			if(!explore(i,pres,vvid,vid,curlabel,ret)) return emptyret;
		}
		return ret;
    }

    bool explore(int start,vector<vector<int> >& pres, vector<bool>& vvid, 
    			vector<bool>& vid, int& curlabel,vector<int>& ret)
    {
    	if(vvid[start]) return false;
    	vvid[start] = true; 
    	int s = pres[start].size();
    	for(int i = 0; i < s; i++)
    		if(!explore(pres[start][i],pres,vvid,vid,curlabel,ret)) return false;
    	if(!vid[start]){
    	    ret[curlabel] = start;
    	    curlabel++;
    	}
    	vid[start] = true;
    	vvid[start] = false;
    	return true;
    }       
};