class Solution {
    private:
    bool isPrime(int c){
        if(c<=1)
        return false;
        if(c==2)
        return true;
        for(int i=2;i<c;i++){
            if(c%i==0)
            return false;
        }
        return true;
    }
    int setbit(int n){
        int s=0;
        while(n>0){
            s+=n&1;
            n=n>>1;
        }
        return s;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int cnt=setbit(i);
            if(isPrime(cnt)){
                count++;
            }
        }
        return count;
    }
};