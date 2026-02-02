class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        int i=0;
        int n=s.size();
        
        while(i<n){
            if(s[i]!=']'){
                st.push(s[i]);
                i++;
            }
            else{
                i++;
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                int num = 0;
                int base = 1;
                while (!st.empty() && isdigit(st.top())) {
                    num = (st.top() - '0') * base + num;
                    base *= 10;
                    st.pop();
                }
                string expanded = "";
                while (num--) {
                    expanded += temp;
                }

                for (char ch : expanded) {
                    st.push(ch);
                }
            }
        }
        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};