class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
       for(int i=0;i<r;i++){
        for(int j=i+1;j<r;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
       }
       for(int i=0;i<r;i++){
       int l=0;
       int e=r-1;
       while(l<e){
        swap(matrix[i][l],matrix[i][e]);
        l++;
        e--;
       }
       }
    }
};