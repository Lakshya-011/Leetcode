class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int i=s.length()-1;
        while(i>=0){
            if(len==0 && s[i]==' ')
            i--;

            else if(len>0 && s[i]==' ')
            break;

            else{
                len++;
                i--;
            }
        }
        return len;
    }
};