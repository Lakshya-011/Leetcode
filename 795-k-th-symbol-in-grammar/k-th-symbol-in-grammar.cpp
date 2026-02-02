class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1)
        return 0;

        int p=kthGrammar(n-1, (k+1)/2);

        if(k&1)
        return p;

        else
        return 1-p;
    }
};