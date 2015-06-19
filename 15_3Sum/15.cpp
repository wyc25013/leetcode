#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* O(N^3) too slow
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector< vector<int> > result;
        int len = num.size();
        if(len < 3)
            return result;
        for(int i = 0; i < len-2; i++) {
            if(num[i]>0)
                break;
            for (int j = i+1; j < len-1; j++){
                if(num[i]+num[j]>0)
                    break;
                for(int k = j+1; k < len; k++){
                    if(num[i]+num[j]+num[k]>0)
                        break;
                    if(num[k]+num[j]+num[i] == 0 ){
                        vector<int> v;
                        if(num[i]>num[j]){
                            int tc = num[i];
                            num[i] = num[j];
                            num[j] = tc; 
                        }

                        if(num[i] >= num[k]){
                            int a = 0;
                            for(; a < result.size();a++){
                                if(result[a][0] == num[k] && result[a][1] == num[i])
                                    break;                            
                            }
                            if(a == result.size()){
                                v.push_back(num[k]);
                                v.push_back(num[i]);
                                v.push_back(num[j]);
                            }else{
                                continue;
                            }           
                        }else{
                            if(num[j] > num[k]){
                                int tc = num[j];
                                num[j] = num[k];
                                num[k] = tc;
                            }
                            int a = 0;
                            for(; a < result.size();a++){
                                if(result[a][0] == num[i] && result[a][1] == num[j])
                                    break;                            
                            }
                            if(a == result.size()){
                                v.push_back(num[i]);
                                v.push_back(num[j]);
                                v.push_back(num[k]);
                            }else{
                                continue;
                            }    
                        }
                        result.push_back(v);
                    }
                }
            }
        }
        return result;
    }
};
*/

//better solution 
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector< vector<int> > result;
        int len = num.size();
        if(len < 3)
            return result;

//        vector<int> newnum;
//        newnum.push_back(num[0]);
//        for (int i = 0; i < len; ++i)
//      {
//          if(num[i]!=newnum.back())
//              newnum.push_back(num[i]);
//      }
//        int newlen = newnum.size();
        for(int i = 0; i < len-2; i++) {
            if(num[i]>0)
                break;
            if(i>=1 && num[i]==num[i-1])
                continue;
            int j = i+1;
            int k = len -1;
            while(j<k){
                int sum = num[i]+num[j]+num[k];
                if(sum == 0){
                    vector<int> v;
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    v.push_back(num[k]);
                    result.push_back(v);
                    int tmp = num[j++];
                    while(tmp==num[j] && j<k)
                        j++;
                }
                else if(sum < 0){
                    int tmp = num[j++];
                    while(tmp==num[j] && j<k)
                        j++;
                }
                else{
                    int tmp = num[k--];
                    while(tmp==num[k] && j<k)
                        k--;
                }
            }
        }
        return result;
    }
};
int main(){
	Solution soln;
	int in[6] = {-1,0,1,2,-1,-4};
	vector<int> v (in,in+sizeof(in)/sizeof(int));

	vector< vector<int> > tmp = soln.threeSum(v);
	int len = tmp.size();
	for (int i = 0; i < len; ++i)
	{
		vector<int> t2 = tmp.back();
		tmp.pop_back();
		for (int i = 0; i < 3; ++i)
		{
			cout << t2[i] <<" ";
		}
		cout <<endl;
	}
}