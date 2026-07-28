class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> a(26,0);
        int n=s.length();
        int j=0;
        for(char c:s){
            a[c-'a']++;
        }
        for(int i=0;i<26;i++){
            while(a[i]>=2){
                s[j]='a'+i;
                s[n-1-j]='a'+i;
                j++;
                a[i]-=2;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]==1){
                s[n/2]='a'+i;
                break;
            }
        }
        return s;
    }
};