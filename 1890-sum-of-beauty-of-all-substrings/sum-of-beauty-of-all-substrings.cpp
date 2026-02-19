class Solution {
public:
    int beautySum(string s) {
        int c=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;

                int mx=0;
                int mn=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k] > 0){
                        mx=max(mx,freq[k]);
                        mn=min(mn,freq[k]);
                    }
                }
                c+=(mx-mn);
            }
        }
        return c;
    }
};