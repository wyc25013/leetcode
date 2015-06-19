#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(),num.end());
		vector<vector<int> > result;
		int len = num.size();
		if(len < 4)
			return result;
		for (int i = 0; i < len - 3; ++i)
		{	
			if(num[i] > target && num[i] >= 0)
				break;
			while(i > 0 && num[i] == num[i-1] && i < len-3)
				i++;

			for (int j = i+1; j < len - 2; ++j)
			{
				if(num[i]+num[j] > target && num[j] >= 0)
					break;
				while(num[j] == num[j-1] && j-1 > i && j < len -2)
					j++;
				int k = j+1;
				int l = len -1;
				while(k<l){
					int sum = num[i]+num[j]+num[k]+num[l];
					if(sum == target){
						vector<int> v;
						v.push_back(num[i]);
						v.push_back(num[j]);
						v.push_back(num[k]);
						v.push_back(num[l]);
						result.push_back(v);
						int kk = num[k++];
						while(kk == num[k] && k<l)
							k++;

					}
					else if(sum > target){
						int ll = num[l--];
						while(ll == num[l] && k<l)
							l--;
					}
					else{
						int kk = num[k++];
						while(kk == num[k] && k<l)
							k++;
					}
				}
			}
		}
		return result;
	}
};
/* using hash
		vector<vector<int> > vvi;
        int n = num.size();
        if(n < 4) return  vvi;

        sort(num.begin(), num.end());        
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }

        for(int i = 0; i < n; i++){
            if(i>0 && num[i] == num[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && num[j] == num[j-1]) continue;
                int res = target - num[i] - num[j];
                if(mp.count(res)){
                    for(auto it = mp[res].begin(); it != mp[res].end(); it++){
                        int k = (*it).first, l = (*it).second;
                        if(k > j){ // k>j make sure that the second pair has bigger values than the first pair.
                            if(!vvi.empty() && num[i]==vvi.back()[0] && num[j]==vvi.back()[1]
                            && num[k]==vvi.back()[2] && num[l] == vvi.back()[3]){
                                continue; //if the obtained 4 elements are the same as previous one continue to next
                            }
                            vector<int> vi={num[i], num[j], num[k], num[l]};
                            vvi.push_back(vi);
                        } // if k>j

                    }//for it
                }//if
            }// forj
        }//for i
        return vvi;
*/
int main(){
	Solution soln;
	int a[6] = {1,0,-1,0,-2,2};
	vector<int> v (a,a+sizeof(a)/sizeof(int));
	vector<vector<int> > rel = soln.fourSum(v,0);
	int len = rel.size();
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 4; j++){
			cout << rel[i][j] <<" ";
		}
		cout<<endl;
	}
}