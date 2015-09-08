// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        int head = 1; int tail = n;
        while(head <= tail){
            if(isBadVersion(head)) return head;
            if(tail-head == 1) return tail;
            int mid = head+(tail-head)/2;   //use a+(b-a)/2 is better than (a+b)/2 because of overflow
            if(isBadVersion(mid)){
                tail = mid;
            }else{
                head = mid+1;
            }
        }
    }
};