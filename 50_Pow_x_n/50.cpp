class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        
        if(n < 0){
            n = -n;
            x = 1/x;
        }
        
        double tmp = pow(x,n/2);
        if(n%2 == 1){
            return tmp*tmp*x;
        }else{
            return tmp*tmp;
        }
    }
};