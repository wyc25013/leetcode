#include <iostream>
#include <vector>
using namespace std;

//basic idea is to compare med of two arrays and drop some part of array
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
     
        if((m+n)%2==0)
        	return (findkth(nums1,0,m-1,nums2,0,n-1,(m+n)/2+1)+findkth(nums1,0,m-1,nums2,0,n-1,(m+n)/2))/2.0;
        else
        	return findkth(nums1,0,m-1,nums2,0,n-1,(m+n+1)/2);
    }

    int findkth(vector<int>& nums1,int s1,int e1, 
    			vector<int>& nums2,int s2,int e2,int k)
    {
    	if(e1-s1 < 0) return nums2[s2+k-1];
    	if(e2-s2 < 0) return nums1[s1+k-1];
    	int m1 = (s1+e1)/2; int m2 = (s2+e2)/2;
    	if(nums1[m1] >= nums2[m2]){
    		if(m1-s1+m2-s2+1 >= k)
    			return findkth(nums1,s1,m1-1,nums2,s2,e2,k); 
    		else
    			return findkth(nums1,s1,e1,nums2,m2+1,e2,max(1,k-m2+s2-1));
    	} else {
    		if(m1-s1+m2-s2+1 >= k)
    			return findkth(nums1,s1,e1,nums2,s2,m2-1,k);
    		else
    			return findkth(nums1,m1+1,e1,nums2,s2,e2,max(1,k-m1+s1-1));
    	}
    }
};