class Solution {
    private:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int c=0;
        int arrow=0;
        for(int i=0;i<points.size();i++){
            if(c==0 || points[i][0]>arrow){
                c++;
                arrow=points[i][1];
            }
        }
        return c;
    }
};