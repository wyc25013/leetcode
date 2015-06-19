#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<int> backup;
        for(int i = 0; i < n; i++)
            backup.push_back(i+1);

        helper(n,k,ret,backup);
        return ret;
    }

    void helper(int n, int k, string& ret, vector<int>& backup){
        if(n > 1){
            int i = (k-1) / factor(n-1);
            int j = (k-1) % factor(n-1);
            ret += to_string(backup[i]);
            int size = backup.size();
            vector<int> backup_next;
            for(int l = 0; l < size; l++){
                if(l != i)
                    backup_next.push_back(backup[l]);
            }
            helper(n-1,j+1,ret,backup_next);
        }
        else if(n == 1){
            ret += to_string(backup[0]);
            return;
        }
    }

    int factor(int n){
        int ret = 1;
        for(int i = 0; i < n; i++)
            ret *= i+1;
        return ret;
    }
};

int main(){
    Solution soln;
    cout << soln.getPermutation(4,23)<<endl;;
}