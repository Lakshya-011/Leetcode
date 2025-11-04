class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();

        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         if(matrix[i][j]==target)
        //         return true;
        //     }
        // }
        // return false;

        int s=0;
        int e= r*c -1;

        while(s<=e){
            int mid=s+(e-s)/2;

            int element=matrix[mid/c][mid%c];
            if(element==target)
            return 1;

            if(element<target)
            s=mid+1;

            else
            e=mid-1;
        }
        return 0;
    }
};