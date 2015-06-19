#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() <= 1)
            return;
		int len = num.size();
		bool iffound = false;
		int toPermutated;
		for(int i = len-1; i > 0; i--){
			if(num[i] > num[i-1]){
				for(int j=len-1; j>=i; j--){
					if(num[j] > num[i-1]){
						toPermutated = j;
						break;
					}
				}
				int tmp = num[toPermutated];
				num[toPermutated] = num[i-1];
				num[i-1] = tmp;

				for(int j = 0; j < (len-i)/2; j++){
					int tmp2 = num[j+i];
					num[j+i] = num[len-1-j];
					num[len-1-j] = tmp2;
				}
				iffound = true;
				break;
			}
		}        
		if(iffound)
			return;
		else{
			for(int i = 0; i < len/2; i++){
				int tmp = num[i];
				num[i] = num[len-1-i];
				num[len-1-i] = tmp; 
			}
			return;
		}
    }
};

int main(){
	Solution soln;
	vector<int> a;
	a.push_back(3);
	a.push_back(5);
	a.push_back(4);
	a.push_back(2);
	soln.nextPermutation(a);
	for (int i = 0; i < 4; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}