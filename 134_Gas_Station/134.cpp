#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int size = gas.size();
		if(!size) return -1;
		int start = 0;
		for(int i = 0; i < size; i++){
			if(gas[i] > gas[start])
				start = i;
		}

		for(int i = start, count0 = 0; count0 < size; count0++){
			int left = 0; bool ifbreak = false;
			for(int j = i, count1 = 0; count1 < size; count1++){
				left += (gas[j] - cost[j]);
				if(left < 0){
					ifbreak = true;
					break;
				}
				if(j < size-1) j++;
				else j = 0;
			}
			if(!ifbreak) return i;
			if(i < size-1) i++;
			else i = 0;
		}        
		return -1;
    }
};