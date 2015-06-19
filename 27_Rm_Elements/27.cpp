#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	if(!n)
    		return 0;

  		int *check = A;
  		int count = 0;
  		for (int i = 0; i < n; i++) {
  			if(*check != elem) {
  				A[count] = *check;
  				check++;
  				count++;
  			}
  			else {
  				check++;
  			}
  		}
  		return count;
    }
};