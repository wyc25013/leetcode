class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n) return 0;
        int head = 0; int tail = n-1;
        int ret = 0;
        while(head <= tail){
            int mid = (head+tail)/2;
            if(citations[mid] < n-mid){
                ret = max(ret, citations[mid]);
                head = mid+1;
            }else{
                ret = max(ret, n-mid);
                tail = mid-1;
            }
        }
        return ret;
    }
};