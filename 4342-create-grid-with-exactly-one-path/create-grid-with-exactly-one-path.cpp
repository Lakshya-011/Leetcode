class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        while(m>0){
            string res="";
            int k=n;
            if(m==1){
                while(k>0){
                    res+='.';
                    k--;
                }
            }
            else{
                while(k>0){
                    if(k==n)
                    res+='.';
                    else
                    res+='#';

                    k--;
                }
            }
            m--;
            ans.push_back(res);
        }
        return ans;
    }
};