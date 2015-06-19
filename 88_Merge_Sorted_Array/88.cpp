#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for(int i = m+n-1; i >= n; i--){
			nums1[i] = nums1[i-n];
		}        
		int i0 = 0;
		int i1 = n;
		int i2 = 0;
		while(i1 < m+n && i2 < n){
			if(nums1[i1] < nums2[i2]){
				nums1[i0] = nums1[i1];
				i1++;
				i0++;
			}else{
				nums1[i0] = nums2[i2];
				i2++;
				i0++;
			}
		}
		if(i2 == n && i1 != m+n){
		    while(i1 < m+n){
		    	nums1[i0] = nums1[i1];
			    i0++;
		    	i1++;
		    }
		} else if(i1 == m+n && i2 != n){
		    while(i2 < n){
		    	nums1[i0] = nums2[i2];
			    i0++;
			    i2++;
		    }
		}
    }
};