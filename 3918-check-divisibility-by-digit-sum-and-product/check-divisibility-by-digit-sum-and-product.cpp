class Solution {
public:
    bool checkDivisibility(int n) {
       int s=0,p=1;
       int temp=n;
       while(n!=0){
        s+=n%10;
        p*=n%10;
        n=n/10;
       } 
       return temp%(s+p)==0;
    }
};