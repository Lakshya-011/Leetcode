class Solution {
public:
    bool checkValidString(string s) {
        int c1=0,c2=0;
        for(char c:s){
            if(c=='(' || c=='*') c1++;
            else
            c1--;
            if(c1<0) return false;
        }
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*') c2++;
            else
            c2--;
            if(c2<0) return false;
        }
        return true;
    }
};