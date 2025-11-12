class Solution {
    private:
    int solve(int n,bool a){
        if(n==1)
        return 1;

        if(a)
        return 2*solve(n/2,false);
        else
        return 2*solve(n/2,true)- (n%2==0 ? 1:0);

    }
public:
    int lastRemaining(int n) {
        return solve(n,true);
    }
};