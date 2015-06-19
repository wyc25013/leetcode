#include <iostream>
#include <vector>
#include <unordered_set>	//vector seems better than set here
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int,int> >& prerequisites) {
        int presize = prerequisites.size();
    	if(!presize) return true;
		vector<vector<int> > pres(numCourses,vector<int>());
		vector<bool> vid(numCourses,false);
        
		for(int i = 0; i < presize; i++)
			pres[prerequisites[i].first].push_back(prerequisites[i].second);

//		bool ifsink = false;
//		for(int i = 0; i < numCourses; i++)
//			if(pres[i].empty()) ifsink = true;
//		if(!ifsink) return false;
		
		for(int i = 0; i < numCourses; i++){
			if(vid[i]) continue;
			vector<bool> vvid(numCourses,false);
			if(!explore(i,pres,vvid,vid)) return false;
		}
		return true;
    }

    bool explore(int start,vector<vector<int> >& pres, vector<bool>& vvid,vector<bool>& vid){
    	if(vvid[start]) return false;
    	vvid[start] = true; 
    	int s = pres[start].size();
    	for(int i = 0; i < s; i++)
    		if(!explore(pres[start][i],pres,vvid,vid)) return false;
    	vid[start] = true;
    	vvid[start] = false;
    	return true;
    }
};

int main(){
	vector<pair<int,int> > a;
	a.push_back(pair<int,int>(0,1));
	a.push_back(pair<int,int>(1,3));
	a.push_back(pair<int,int>(3,2));
	a.push_back(pair<int,int>(3,1));
//	a.push_back(pair<int,int>(2,3));
//	a.push_back(pair<int,int>(3,4));
//	a.push_back(pair<int,int>(4,5));
//	a.push_back(pair<int,int>(5,6));	
//	a.push_back(pair<int,int>(6,0));

	Solution soln;
	cout<<soln.canFinish(4,a)<<endl;
}