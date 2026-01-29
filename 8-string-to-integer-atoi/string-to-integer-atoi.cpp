class Solution {
    private:
    void solve(string s,int i,int &res, int& sign, bool &start){
        if(i>=s.size())
        return;

        if(!start && s[i]==' '){
        solve(s,i+1,res,sign,start);
        return;}

        if(!start && (s[i]=='-' || s[i]=='+')){
            sign=(s[i]=='-')?-1:1;
            start=true;
            solve(s,i+1,res,sign,start);
            return;
        }
        

        if(isdigit(s[i])){
            start=true;

            if (res > (INT_MAX - (s[i]-'0')) / 10) {
                res = (sign == 1) ? INT_MAX : INT_MIN;
                return;
            }
            res=res*10 + (s[i]-'0');
            solve(s,i+1,res,sign,start);
            return;
        }
        return;
    }
public:
    int myAtoi(string s) {
        int res=0;
        int sign=1;
        bool start=false;
        solve(s,0,res,sign,start);
        
    if (res == INT_MIN)
        return INT_MIN;

    if (res == INT_MAX)
        return (sign == 1) ? INT_MAX : -INT_MAX;
        return sign*res;
    }
};