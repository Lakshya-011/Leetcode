class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26,0);
        for(char c:word)
        f[c-'a']++;
        sort(f.begin(),f.end());
        int p=0;
        for(int i=25,pc=0;i>=0;i--){
            int cidx=25-i;
            if(cidx%8==0)
            pc++;
            p+=f[i]*pc;
        }
        return p;
    }
};