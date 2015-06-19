#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n)
            return 0;
        int *head = A;
        int *tail = A;
        int count = 1;
        int i = 0;
        while (i < n - 1) {
        	tail++;
        	if(*tail == *head) {
        		head++;
        	} else {
        		head++;
        		A[count] = *tail;
        		count++;
        	}
        	i++;
        }
        return count;
    }
};

int main(){
	Solution soln;
	int a[] = {1,1,2};
	cout << soln.removeDuplicates(a,3) <<endl;
	return 0;
}