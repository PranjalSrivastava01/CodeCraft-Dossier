class Solution {
public:
    double myPow(double x, long long  n) {
        if(n<0)
        {
        {
            n=n*(-1);
            x=1/x;
        }
        }
        if(n==0) return 1;

        return  x*pow(x,n-1);
    }
};