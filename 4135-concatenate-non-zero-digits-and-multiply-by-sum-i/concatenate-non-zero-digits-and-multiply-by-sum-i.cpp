class Solution {
public:
    long long sumAndMultiply(int n) {
        int num=n;
        if(n==0)
        return 0;
        long long sum=0;
        string res="";
        while(num!=0){
            int r=num%10;
            if(r!=0){
                sum+=r;
                res+=to_string(r);
            }
            num=num/10;
        }
        reverse(res.begin(),res.end());
        long long t=stoll(res);
        return 1LL*sum*t;
    }
};