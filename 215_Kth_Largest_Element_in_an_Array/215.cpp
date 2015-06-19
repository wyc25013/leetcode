#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	/* sort solution, which is not meant by this problem
        sort(nums.begin(),nums.end(),std::greater<int>());
        return nums[k-1];
		*/

        /* quicksort like solution
        int ret; int len = nums.size();
        qshelper(nums,k,0,len-1,ret);
        return ret;
        */

        // heapsort solution
        // first build heap
        int len = nums.size();
        for(int i = 1; i < len; i++)
        	backtoroot(nums,i);
        // then sort heap 
        for(int i = 0, size = len; i < k; i++){
        	// almost the same as build tree part
        	swap(nums,0,size-1); size--;
        	downtoleaf(nums,0,size);
        }
        return nums[len-k];
    }

    /* quicksort helper
    void qshelper(vector<int>& nums, int k, int start, int end, int& ret){
        if(start > end) return;
    	int pivot = nums[start]; 
    	int front = start+1; int back = end;
    	while(front <= back){
    		if(nums[front] >= pivot) 
    			front++;
    		else {
    			swap(nums,front,back);
    			back--;
    		}
    	}
    	if(front == k){
    		ret = pivot;
    		return;
    	} else if(front > k)						// here k+1 is important cuz we don't 
    		qshelper(nums,k+1,start+1,front-1,ret);	// change pivot's position and shift the 
    	else 										// former partition part 
    		qshelper(nums,k,back+1,end,ret);											
    }
    */

    void swap(vector<int>& nums, int i, int j){
    	int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void backtoroot(vector<int>& nums, int j){
    	if(j==0) return; 
    	int parent = (j-1) / 2;
		if(nums[parent] < nums[j]){
			swap(nums,j,parent);
			backtoroot(nums,parent);
		}
	}

	void downtoleaf(vector<int>& nums, int j, int size){
		if(2*j+1 >= size) return;
		if(2*j+2 >= size){
			if(nums[2*j+1] >= nums[j]){
				swap(nums,2*j+1,j);
				downtoleaf(nums,2*j+1,size);
			}
		} else {
			if(nums[j] >= nums[2*j+1] && nums[j] >= nums[2*j+2]){}
			else{
				if(nums[2*j+1] >= nums[2*j+2]){
					swap(nums,j,2*j+1);
					downtoleaf(nums,2*j+1,size);
				}else{ 
					swap(nums,j,2*j+2);
					downtoleaf(nums,2*j+2,size);
				}
			}
		}
    }
};