class Solution {
public:
    int minInsertions(string s) {
        // int ans=0;
        // stack<char>st;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     else{
        //         if(i+1<s.length() && s[i+1]==')'){
        //             if(!st.empty()){
        //                 st.pop();
        //             }
        //             else
        //             ans++;
        //             i++;
        //         }
        //         else{
        //             if(!st.empty()){
        //                 st.pop();
        //                 ans++;
        //             }
        //             else
        //             ans+=2;
        //         }
        //     }
        // }
        // ans+=(2*st.size());
        // return ans;
        int ans=0;
        int req=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(req%2==1){
                    ans++;
                    req--;
                }
                    req+=2;
            }
            else{
                req--;
                if(req<0){
                    ans++;
                    req=1;
                }
            }
        }
        return ans+req;
    }
};