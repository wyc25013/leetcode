#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	/*
		for(int i = 0; i < intervals.size(); i++){
			for(int j = i+1; j < intervals.size(); ){
				if(ifmerge(intervals[i],intervals[j])){
					intervals[i].start = min(intervals[i].start,intervals[j].start);
					intervals[i].end = max(intervals[i].end,intervals[j].end);
					intervals.erase(intervals.begin()+j);
				} else j++;
			}
		}
		return intervals;
		*/

		/* this try failed handling [0,0]
		unordered_set<int> a; int max = INT_MIN; int min = INT_MAX;
		for(int i = 0; i < intervals.size(); i++){
		    int start = intervals[i].start; int end = intervals[i].end;
		    if(start==end)a.insert(start);
			else
			    for(int j = start; j < end; j++)
				    a.insert(j);
			if(start < min) min = start;
			if(end > max) max = end;
		} 
		vector<Interval> ret;
		for(int i = min; i <= max; ){
			int start = i;
			while(i <= max && a.find(i) != a.end() )
				i++;
			ret.push_back(Interval(start,i));
			while(i <= max && a.find(i) == a.end())
				i++;
		}
		return ret;
		*/
		if(intervals.empty()) return intervals;
        sort(intervals.begin(),intervals.end(),
    		[](Interval a, Interval b){
		    	return a.start==b.start ? a.end < b.end : a.start < b.start;
	    	} );
    	vector<Interval> ret={intervals[0]};
	    for(int i = 1; i < intervals.size();i++){
		    if(ret[ret.size()-1].end >= intervals[i].start)
				ret[ret.size()-1].end = max(intervals[i].end,ret[ret.size()-1].end);
			else ret.push_back(intervals[i]);
		}
		return ret;
    } 

    bool ifmerge(Interval a, Interval b){
    	int as = a.start; int ae = a.end;
    	int bs = b.start; int be = b.end;
    	if(ae < bs || be < as) return false;
    	else return true;
    }
};

int main(){
	Interval a1(1,18);
	Interval a2(2,10);
	Interval a3(3,5);
	Interval a4(4,4);
	vector<Interval> a;
	a.push_back(a1);
	a.push_back(a2);
	a.push_back(a3);
	a.push_back(a4);
	Solution soln;
	vector<Interval> b = soln.merge(a);
	for(int i = 0; i < b.size(); i++){
		cout<<b[i].start<<" "<<b[i].end<<endl;
	}
}