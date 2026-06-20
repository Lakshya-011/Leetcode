class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int val2=stoi(st.top());
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int ans=val1+val2;
                st.push(to_string(ans));
            }
            else if(tokens[i]=="-"){
                int val2=stoi(st.top());
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int ans=val1-val2;
                st.push(to_string(ans));
            }
            else if(tokens[i]=="*"){
                int val2=stoi(st.top());
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int ans=val1*val2;
                st.push(to_string(ans));
            }
            else if(tokens[i]=="/"){
                int val2=stoi(st.top());
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int ans=val1/val2;
                st.push(to_string(ans));
            }
            else
            st.push(tokens[i]);
        }
        return stoi(st.top());
    }
};