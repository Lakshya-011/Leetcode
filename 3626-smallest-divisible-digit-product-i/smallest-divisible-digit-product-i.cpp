class Solution {
public:
int solve(int n){
    int p=1;
    while(n!=0){
        p=p*(n%10);
        n=n/10;
    }
    return p;
}
    int smallestNumber(int n, int t) {
        while(solve(n)%t!=0)
        n++;

        return n;
    }
};