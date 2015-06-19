#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        vector<int> a(n+1,0);
        a[0] = 1;
        a[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){ //j = #left children
                a[i] += a[i-1-j]*a[j];
            }
        }
        return a[n];
    }
};