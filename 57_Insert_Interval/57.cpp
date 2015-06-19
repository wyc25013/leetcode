#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int len = intervals.size();
        if(!len){
            intervals.push_back(newInterval);
            return intervals;
        }
        /* TLE
        for(int i = 0; i < len; i++){
        	if(intervals[i].start < newInterval.start){}
        	else if(intervals[i].start==newInterval.start){
        		if(intervals[i].end > newInterval.end)
        			intervals.insert(intervals.begin()+i-1,newInterval);
        		else if(intervals[i].end == newInterval.end){}
        		else	
        			intervals.insert(intervals.begin()+i,newInterval);
        	}else
        		intervals.insert(intervals.begin()+i-1,newInterval);
        }
        ret.push_back(intervals[0]);
		for(int i = 0; i < len; i++){
			if(intervals[i].start <= ret[ret.size()-1].end){
				ret[ret.size()-1].end = max(ret[ret.size()-1].end,newIntervals.end);
			}else ret.push_back(intervals[i]);
		} 
		*/
		if(newInterval.start <= intervals[0].start && newInterval.end >= intervals[len-1].end){
            vector<Interval> a={newInterval};
            return a;
        }
        bool iff = false;
		for(int i = 0; i < len; ){
			if(!iff){
				if(intervals[i].start < newInterval.start){
					if(intervals[i].end >= newInterval.start){
						iff = true;
						intervals[i].end = max(newInterval.end,intervals[i].end);
					} 
				} else if(intervals[i].start == newInterval.start){
					iff = true;
					intervals[i].end = max(newInterval.end,intervals[i].end);
				} else{
				    iff = true;
					if(intervals[i].start <= newInterval.end){
						intervals[i].start = min(newInterval.start,intervals[i].start);
						intervals[i].end = max(newInterval.end,intervals[i].end);
					} else{
					    intervals.insert(intervals.begin()+i,newInterval); 
					    i++;
					}
				}
				i++;
			}else{
				if(i < intervals.size()){
					if(intervals[i-1].end < intervals[i].start) return intervals;
					else{
						if(intervals[i-1].end < intervals[i].end)
							intervals[i-1].end = intervals[i].end;
						intervals.erase(intervals.begin()+i);
					}
				} else
					return intervals;
			}
		}
		if(!iff) intervals.push_back(newInterval);
		return intervals;    
    }
};

int main(){
	vector<Interval> a;
	a.push_back(Interval(1,2));
	a.push_back(Interval(3,5));
	a.push_back(Interval(7,9));
	a.push_back(Interval(12,40));
	a.push_back(Interval(50,100));
	Interval c(2,3);
	Solution soln;
	vector<Interval> b = soln.insert(a,c);
	for(int i = 0; i<b.size();i++){
		cout<<b[i].start<<" "<<b[i].end<<endl;
	} 

}