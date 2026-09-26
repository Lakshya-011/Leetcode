class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int t=0;
        for(int x:cardPoints)
        t+=x;

        int mx=0;
        int n=cardPoints.size();
        int idx=n-k;
        if(idx==0)
        return t;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        mx=sum;
        int j=n-1;
        for(int i=k-1;i>=0;i--){
            sum-=cardPoints[i];
            sum+=cardPoints[j];
            mx=max(mx,sum);
            j--;
        }
        return mx;
    }
};