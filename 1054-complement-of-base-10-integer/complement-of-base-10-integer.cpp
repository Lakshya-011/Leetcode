class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
        return 1;
        string res="";
        while(n!=0){
            int bit=n&1;
            if(bit==0)
            res.push_back('1');
            else
            res.push_back('0');

            n=n>>1;
        }
        int i=0;
        int ans=0;
        for(int j=0;j<(int)res.length();j++){
            int digit=res[i]-'0';
            int r=digit * pow(2,i);
            ans=ans+r;
            i++;
        }
        return ans;
    }
};