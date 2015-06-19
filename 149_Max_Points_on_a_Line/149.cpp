#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Line{
	int a;
	int b;
	int c;
	Line(int x,int y,int z):a(x),b(y),c(z){}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
		unordered_map<Line*,int> m;
		int len = points.size();
		if(len <= 2) return len;

		for(int i = 0; i < len-1; i++){
			for(int j = i+1; j < len; j++){
				bool iff = isexist(points[i],points[j],m);
				if(!iff){	
					int x1 = points[i].x; int y1 = points[i].y;
					int x2 = points[j].x; int y2 = points[j].y;
					int a = y1-y2; int b = x2-x1; int c = a*x1+b*y1;
					Line* l = new Line(a,b,c);
					m[l] = 2;	
				}
			}
		}        
		auto it = m.begin(); int ret = INT_MIN;
		while(it != m.end()){
			if(it->second > ret)
				ret = it->second;
			it++;
		}		
		return ret;
    }

	bool isexist(Point a, Point b, unordered_map<Line*, int>& m){
		auto it = m.begin(); bool ret = false;
    	while(it != m.end()){
    		bool ifa = false; bool ifb = false;
    		int aa = it->first->a;
    		int bb = it->first->b;
    		int cc = it->first->c;
    		if(aa*a.x+bb*a.y==cc){
    			it->second++;
    			ifa = true;
    		}
    		if(aa*b.x+bb*b.y==cc){
    			it->second++;
    			ifb = true;
    		}
    		if(ifa && ifb) ret = true;
    		it++;
    	}
    	return ret;
	}
};
/* better solution from luming.zhang
 * for one point point[i] and if the 3rd
 * point has slope that is the same as slope
 * between point[i] and 2nd point
 * then point[i],2nd,3rd point are on the 
 * same line
 
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        if(points.size()<=2) return points.size();
        int res=0;
        for(int i=0;i<points.size()-1;i++) {
            int numVertical=1,local=1,duplicate=0;
            unordered_map<double,int> map;
            for(int j=i+1;j<points.size();j++) {
                if(points[i].x==points[j].x) // special cases
                    if(points[i].y==points[j].y) // duplicate 
                        duplicate++;
                    else // vertical
                        numVertical++;
                else {
                    double slope=(points[i].y-points[j].y)*1.0/(points[i].x-points[j].x);
                    map[slope]==0?map[slope]=2:map[slope]++;
                    local=max(local,map[slope]);
                }
            }
            local=max(local+duplicate,numVertical+duplicate);
            res=max(res,local);
        }
        return res;
    }
};
*/