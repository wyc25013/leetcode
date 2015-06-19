#include <deque>
#include <vector>
using namespace std;

class MinStack {
	vector<int> ms;
	map<int,int> mp;
public:
    void push(int x) {
		ms.push_back(x);
		if(mp.find(x) == mp.end())
			mp[x] = 1;
		else
			mp[x]++;
    }

    void pop() {
        int x = ms.back();
        ms.pop_back();
        if(mp[x] > 1)
        	mp[x]--;
        else
        	mp.erase(x);
    }

    int top() {
        return ms.back();
    }

    int getMin() {
        map<int,int>::iterator it = mp.begin();
        return it->first;
    }
};
/* a much better solution
class MinStack {
	vector<int> ms;
	stack<int> mp;
public:
    void push(int x) {
		ms.push_back(x);
		if(mp.empty() || x <= mp.top())
		    mp.push(x);
    }

    void pop() {
        int x = ms.back();
        ms.pop_back();
        if(x == mp.top())
            mp.pop();
    }

    int top() {
        return ms.back();
    }

    int getMin() {
        return mp.top();
    }
};
*/