#include <iostream>
#include <queue>
#include <list>
using namespace std;
/*
class LRUCache{
	unordered_map<int,pair<int,int> > k_av;
	int cap; int cnt;
public:
    LRUCache(int capacity) {
		cap = capacity;  
		cnt = 0;  
    }
    
    int get(int key) {
        if(k_av.find(key) != k_av.end()){
        	int o = k_av[key].first;
        	auto it = k_av.begin();
        	while(it != k_av.end()){
        		if(it->second.first < o)
        			it->second.first++;
        		it++;
        	}
        	k_av[key].first = 0;
        	return k_av[key].second;
        } else return -1;
    }
    
    void set(int key, int value) {
    	int o = k_av[key].first;
    	if(k_av.find(key) != k_av.end()){
    		auto it = k_av.begin();
        	while(it != k_av.end()){
        		if(it->second.first < o)
        			it->second.first++;
        		it++;
        	}
    		k_av[key].second = value;
        	k_av[key].first = 0;
    	}else{
    		if(cnt < cap){
    			auto it = k_av.begin();
    			while(it != k_av.end()){
	        		it->second.first++;
	        		it++;
	        	}
    			k_av[key].second = value;
	        	k_av[key].first = 0;
	        	cnt++;
	        }else{
	        	auto it = k_av.begin();
	        	while(it != k_av.end()){
	        		if(it->second.first==cap-1)
	        			k_av.erase(it);
	        		else
	        			it->second.first++;
	        		it++;
	        	}
	        	k_av[key].second = value;
	        	k_av[key].first = 0;
	        }
    	} 
    }
};
class LRUCache{
	queue<pair<int,int> > q;
	int cap; int cnt;
public:
    LRUCache(int capacity) {
		cap = capacity;  
		cnt = 0;  
    }
    
    int get(int key) {
        if(cnt==0) return -1;
        else{
        	int f = q.front().first;
        	if(f==key){
        	    int ret = q.front().second;
        	    q.push(q.front());
        	    q.pop();
        	    return ret;
        	}
        	int tmp = f;
        	while(tmp != key){
        		q.push(q.front());
        		q.pop();
        		tmp = q.front().first;
        		if(tmp==f) return -1;
        	}
        	pair<int,int> ret = q.front();
        	q.pop();
        	if(q.empty()) {
        		q.push(ret);
        		return ret.second;
        	}
        	tmp = q.front().first;
        	while(tmp != f){
        		q.push(q.front());
        		q.pop();
        		tmp = q.front().first;
        	}
        	q.push(ret);
        	return ret.second;
        }
    }
    
    void set(int key, int value) {
    	if(cnt < cap) {
    		q.push(pair<int,int>(key,value));
    		cnt++;
    	}else{
        	q.pop();
        	q.push(pair<int,int>(key,value));
        }
    }
};
*/
class LRUCache{
private:
	list<int> ls;
	unordered_map<int,pair<list<int>::iterator,int> > um;
	int cap;
public:
    LRUCache(int capacity) {
		cap = capacity;    
    }
    
    int get(int key) {
        auto it = um.find(key);
        if(it==um.end()) return -1;
        else{
        	ls.erase(it->second.first);
        	ls.push_front(key);
        	it->second.first = ls.begin();
        	return it->second.second;
        }
    }
    
    void set(int key, int value) {
        auto it = um.find(key);
    	if(it==um.end()){
    		if(um.size()==cap){	// here use um.size() is much more faster than ls.size()
    		    um.erase(ls.back());
    			ls.pop_back();
    		}
    	}else ls.erase(it->second.first);
    	ls.push_front(key);
        um[key]= {ls.begin(),value};
    }
};